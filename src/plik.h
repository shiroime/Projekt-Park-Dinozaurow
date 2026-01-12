#ifndef PLIK_H
#define PLIK_H

#include "dinozaur.h"

int wczytaj_z_pliku(
    const char *nazwa,
    Dinozaur **dinozaury,
    int *liczba_dinozaurow
);

int zapisz_do_pliku(
    const char *nazwa,
    Dinozaur *dinozaury,
    int liczba_dinozaurow
);

#endif
