#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    MIEZOZERNY,
    ROSLINOZERNY,
    WSZYSTKOZERNY
} Dieta;

typedef enum {
    Bezpieczny,
    Pod_Obserwacja,
    Zagrozenie,
    Ucieczka,
    Awaryjna_Kwarantanna
} StatusBezpieczenstwa;

typedef enum {
    SPOKOJNY,
    AGRESYWNY,
    NIEPRZEWIDYWALNY,
} Temperament;

typedef enum {
    Zagroda_I,
    Zagroda_II,
    Zagroda_III,
    Zagroda_IV,
    Zagroda_V,
    Izolatka
} Zagroda;

typedef struct {
    Dieta dieta;
    double masa;
    char gatunek[101];
    StatusBezpieczenstwa status;
    Temperament temperament;
    Zagroda zagroda;
} Dinozaur;

const char* dieta_na_tekst (Dieta d) {
    switch (d) {
    case MIEZOZERNY:
        return "Miesozerny";
    case ROSLINOZERNY:
        return "Roslinozerny";
    case WSZYSTKOZERNY:
        return "Wszystkozerny";
    default:
        return "Nieznana";
    }
}
const char* status_bezpieczenstwa (StatusBezpieczenstwa s) {
    switch (s) {
        case Bezpieczny:
            return "Bezpieczny";
        case Pod_Obserwacja:
            return "Pod obserwacja";
        case Zagrozenie:
            return "Zagrozenie!";
        case Ucieczka:
            return "Ucieczka!";
        case Awaryjna_Kwarantanna:
            return "Awaryjna Kwarantanna!";
        default:
            return "Status nieznany";
    }
}

const char* temperament_na_tekst (Temperament t) {
    switch (t) {
        case SPOKOJNY:
            return "Spokojny";
        case AGRESYWNY:
            return "Agresywny";
        case NIEPRZEWIDYWALNY:
            return "Nieprzewidywalny";
        default:
            return "Temperament nieznany.";
    }
}

const char* zagroda_na_tekst (Zagroda z) {
    switch (z) {
        case Zagroda_I:
            return "Zagroda I";
        case Zagroda_II:
            return "Zagroda II";
        case Zagroda_III:
            return "Zagroda III";
        case Zagroda_IV:
            return "Zagroda IV";
        case Zagroda_V:
            return "Zagroda V";
        case Izolatka:
            return "Izolatka";
        default:
            return "Zagroda nieznana.";
    }
}

void wypisz_dinozaura (const Dinozaur *d) {
    printf("Gatunek: %s\n", d->gatunek);
    printf("Dieta: %s\n", dieta_na_tekst(d->dieta));
    printf("Masa: %.2f\n", d->masa);
    printf("Status: %s\n", status_bezpieczenstwa(d->status));
    printf("Temperament: %s\n", temperament_na_tekst(d->temperament));
    printf("Zagroda: %s\n", zagroda_na_tekst(d->zagroda));
}

int main (void) 
{
    Dinozaur *dinozaury = NULL;
    int liczba_dinozaurow = 0;
    Dinozaur *tmp;

    dinozaury = malloc(sizeof(Dinozaur));

    if (dinozaury == NULL) {
        printf("Blad alokacji pamieci\n");
        return 1;
    }
    liczba_dinozaurow = 1;

    tmp = realloc(dinozaury, (liczba_dinozaurow + 1) * sizeof(Dinozaur));

    if (tmp == NULL) {
        printf("Blad alokacji pamieci\n");
        free(dinozaury);
        return 1;
    }
    dinozaury = tmp;
    liczba_dinozaurow++;

    dinozaury[0].masa = 1;
    dinozaury[0].dieta = MIEZOZERNY;
    strcpy(dinozaury[0].gatunek, "Tyrannosaurus rex");
    dinozaury[0].status = Zagrozenie;
    dinozaury[0].temperament = AGRESYWNY;
    dinozaury[0].zagroda = Izolatka;

    dinozaury[1].masa = 113;
    dinozaury[1].dieta = ROSLINOZERNY;
    strcpy(dinozaury[1].gatunek, "Pterodaktyl");
    dinozaury[1].status = Bezpieczny;
    dinozaury[1].temperament = NIEPRZEWIDYWALNY;
    dinozaury[1].zagroda = Zagroda_III;

    for (int i = 0; i < liczba_dinozaurow; i++) {
        wypisz_dinozaura(&dinozaury[i]);
    }

    free(dinozaury);
    dinozaury = NULL;
    
    return 0;
}