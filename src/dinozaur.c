#include "dinozaur.h"

const char* dieta_na_tekst(Dieta d) {
    switch (d) {
        case MIESOZERNY: return "Miesozerny";
        case ROSLINOZERNY: return "Roslinozerny";
        case WSZYSTKOZERNY: return "Wszystkozerny";
        default: return "Nieznana";
    }
}

const char* status_bezpieczenstwa(StatusBezpieczenstwa s) {
    switch (s) {
        case Bezpieczny: return "Bezpieczny";
        case Pod_Obserwacja: return "Pod obserwacja";
        case Zagrozenie: return "Zagrozenie!";
        case Ucieczka: return "Ucieczka!";
        case Awaryjna_Kwarantanna: return "Awaryjna Kwarantanna!";
        default: return "Status nieznany";
    }
}

const char* temperament_na_tekst(Temperament t) {
    switch (t) {
        case SPOKOJNY: return "Spokojny";
        case AGRESYWNY: return "Agresywny";
        case NIEPRZEWIDYWALNY: return "Nieprzewidywalny";
        default: return "Temperament nieznany";
    }
}

const char* zagroda_na_tekst(Zagroda z) {
    switch (z) {
        case Zagroda_I: return "Zagroda I";
        case Zagroda_II: return "Zagroda II";
        case Zagroda_III: return "Zagroda III";
        case Zagroda_IV: return "Zagroda IV";
        case Zagroda_V: return "Zagroda V";
        case Izolatka: return "Izolatka";
        default: return "Zagroda nieznana";
    }
}

void wypisz_dinozaura(const Dinozaur *d) {
    printf("Gatunek: %s\n", d->gatunek);
    printf("Dieta: %s\n", dieta_na_tekst(d->dieta));
    printf("Masa: %.2f\n", d->masa);
    printf("Status: %s\n", status_bezpieczenstwa(d->status));
    printf("Temperament: %s\n", temperament_na_tekst(d->temperament));
    printf("Zagroda: %s\n", zagroda_na_tekst(d->zagroda));
}
