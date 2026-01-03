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

typedef struct {
    Dieta dieta;
    double masa;
    char gatunek[101];
    StatusBezpieczenstwa status;
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

void wypisz_dinozaura (const Dinozaur *d) {
    printf("Gatunek: %s\n", d->gatunek);
    printf("Dieta: %s\n", dieta_na_tekst(d->dieta));
    printf("Masa: %.2f\n", d->masa);
    printf("Status: %s\n", status_bezpieczenstwa(d->status));
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

    dinozaury[1].masa = 113;
    dinozaury[1].dieta = ROSLINOZERNY;
    strcpy(dinozaury[1].gatunek, "Pterodaktyl");
    dinozaury[1].status = Bezpieczny;

    for (int i = 0; i < liczba_dinozaurow; i++) {
        wypisz_dinozaura(&dinozaury[i]);
    }

    free(dinozaury);
    dinozaury = NULL;
    
    return 0;
}