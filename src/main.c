#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    MIEZOZERNY,
    ROSLINOZERNY,
    WSZYSTKOZERNY
} Dieta;

typedef struct {
    Dieta dieta;
    double masa;
    char gatunek[101];
} Dinozaur;

const char* dieta_na_tekst(Dieta d) {
    switch (d)
    {
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

int main (void) 
{
    Dinozaur d1;

    d1.dieta = MIEZOZERNY;
    d1.masa = 1;
    strcpy(d1.gatunek, "Tyrannosaurus rex");

    printf("Dinozaur ma diete: %s.\n", dieta_na_tekst(d1.dieta));
    printf("Dinozaur ma mase: %2.f.\n", d1.masa);
    printf("Gatunek: %s.\n", d1.gatunek);
    

    return 0;
}