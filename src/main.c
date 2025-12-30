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
    Dinozaur d1;

    d1.dieta = MIEZOZERNY;
    d1.masa = 1;
    strcpy(d1.gatunek, "Tyrannosaurus rex");
    d1.status = Zagrozenie;

    printf("Dinozaur ma diete: %s.\n", dieta_na_tekst(d1.dieta));
    printf("Dinozaur ma mase: %.2f.\n", d1.masa);
    printf("Gatunek: %s.\n", d1.gatunek);
    printf("Dinozaur ma status: %s.\n", status_bezpieczenstwa(d1.status));


    return 0;
}