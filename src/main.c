#include <stdio.h>
#include <stdlib.h>

typedef enum {
    MIEZOZERNY,
    ROSLINOZERNY,
    WSZYSTKOZERNY
} Dieta;

typedef struct {
    Dieta dieta;
    double masa;
} Dinozaur;

int main (void) 
{
    Dinozaur d1;

    d1.dieta = MIEZOZERNY;
    d1.masa = 1;

    printf("Dinozaur ma diete: %d\n", d1.dieta);
    printf("Dinozaur ma mase: %2.f\n", d1.masa);

    return 0;
}