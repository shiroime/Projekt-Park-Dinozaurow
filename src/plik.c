#include <stdio.h>
#include <stdlib.h>
#include "plik.h"

int wczytaj_z_pliku(const char *nazwa, Dinozaur **dinozaury, int *liczba) {
    FILE *fp = fopen(nazwa, "rb");
    if (!fp) {
        printf("Brak pliku danych – start z pusta baza.\n");
        *liczba = 0;
        *dinozaury = NULL;
        return 0;
    }

    if (fread(liczba, sizeof(int), 1, fp) != 1) {
        fclose(fp);
        *liczba = 0;
        return -1;
    }

    *dinozaury = malloc(*liczba * sizeof(Dinozaur));
    if (!*dinozaury) {
        fclose(fp);
        *liczba = 0;
        return -1;
    }

    if (fread(*dinozaury, sizeof(Dinozaur), *liczba, fp) != (size_t)*liczba) {
        free(*dinozaury);
        *dinozaury = NULL;
        *liczba = 0;
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

int zapisz_do_pliku(const char *nazwa, Dinozaur *dinozaury, int liczba) {
    FILE *fp = fopen(nazwa, "wb");
    if (!fp) return -1;

    fwrite(&liczba, sizeof(int), 1, fp);
    fwrite(dinozaury, sizeof(Dinozaur), liczba, fp);

    fclose(fp);
    return 0;
}
