#ifndef DINOZAUR_H
#define DINOZAUR_H

#include <stdio.h>

typedef enum {
    MIESOZERNY,
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
    NIEPRZEWIDYWALNY
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

const char* dieta_na_tekst(Dieta d);
const char* status_bezpieczenstwa(StatusBezpieczenstwa s);
const char* temperament_na_tekst(Temperament t);
const char* zagroda_na_tekst(Zagroda z);

void wypisz_dinozaura(const Dinozaur *d);

#endif
