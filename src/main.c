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

int main (void) 
{
    Dinozaur *dinozaury = NULL;
    int liczba_dinozaurow = 0;

    dinozaury = malloc(sizeof(Dinozaur));

    if (dinozaury == NULL) {
        printf("Blad alokacji pamieci\n");
        return 1;
    }
    liczba_dinozaurow = 1;

    dinozaury[0].masa = 1;
    dinozaury[0].dieta = MIEZOZERNY;
    strcpy(dinozaury[0].gatunek, "Tyrannosaurus rex");
    dinozaury[0].status = Zagrozenie;

    printf("Dinozaur ma diete: %s.\n", dieta_na_tekst(dinozaury[0].dieta));
    printf("Dinozaur ma mase: %.2f.\n", dinozaury[0].masa);
    printf("Gatunek: %s.\n", dinozaury[0].gatunek);
    printf("Dinozaur ma status: %s.\n", status_bezpieczenstwa(dinozaury[0].status));

    free(dinozaury);
    dinozaury = NULL;
    
    return 0;
}