#include <stdio.h>
#include <stdlib.h>

typedef enum {
    MIEZOZERNY,
    ROSLINOZERNY,
    WSZYSTKOZERNY
} Dieta;

typedef struct {
    Dieta dieta;
} Dinozaur;

int main (void) 
{
    Dinozaur d1;

    d1.dieta = MIEZOZERNY;

    printf("Dinozaur ma diete: %d\n", d1.dieta);

    return 0;
}