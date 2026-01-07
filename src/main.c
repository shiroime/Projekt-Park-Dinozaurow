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
    int status_input;
    int dieta_input;
    int temperament_input;
    int zagroda_input;
    int idx;
    int wybor;
    Dinozaur *dinozaury = NULL;
    int liczba_dinozaurow = 0;
    Dinozaur *tmp;

    do {
        printf("\n=== PARK DINOZAUROW ===\n");
        printf("1. Wypisz wszystkie dinozaury\n");
        printf("2. Dodaj nowego dinozaura\n");
        printf("4. Usun dinozaura\n");
        printf("5. Zmien status bezpieczenstwa\n");
        printf("6. Przenies dinozaura do innej zagrody\n");
        printf("7. Zaplanuj karmienie\n");
        printf("0. Zakoncz program\n");
        printf("Twoj wybor: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                if (liczba_dinozaurow == 0)
                    printf("Brak dinozaurow w parku.\n");
                else {
                    for (int i = 0; i < liczba_dinozaurow; i++) {
                        wypisz_dinozaura(&dinozaury[i]);
                    }
                }
            break;

            case 2:
                tmp = realloc(dinozaury, (liczba_dinozaurow + 1) * sizeof(Dinozaur));
                if (tmp == NULL) {
                    printf("Brak alokacji dinozaurow.\n"); 
                    break;
                }
                dinozaury = tmp;
                liczba_dinozaurow++;

                int idx = liczba_dinozaurow - 1;

                printf("Podaj gatunek: ");
                getchar();
                fgets(dinozaury[idx].gatunek, sizeof(dinozaury[idx].gatunek), stdin);
                dinozaury[idx].gatunek[strcspn(dinozaury[idx].gatunek, "\n")] = '\0';

                printf("Wybierz diete:\n");
                printf("0 - Miesozerny\n");
                printf("1 - Roslinozerny\n");
                printf("2 - Wszystkozerny\n");
                printf("Twoj wybor: ");
                scanf("%d", &dieta_input);
                if (dieta_input < 0 || dieta_input > 2) {
                    printf("Nieprawidlowy wybor diety.\n");
                    break;
                }
                dinozaury[idx].dieta = (Dieta)dieta_input;

                printf("Podaj mase (kg): ");
                scanf("%lf", &dinozaury[idx].masa);

                printf("Wybierz status bezpieczenstwa:\n");
                printf("0 - Bezpieczny\n");
                printf("1 - Pod obserwacja\n");
                printf("2 - Zagrozenie\n");
                printf("3 - Ucieczka\n");
                printf("4 - Awaryjna kwarantanna\n");
                printf("Twoj wybor: ");
                scanf("%d", &status_input);
                if (status_input < 0 || status_input > 4) {
                    printf("Nieprawidlowy wybor statusu.\n");
                    break;
                }
                dinozaury[idx].status = (StatusBezpieczenstwa)status_input;

                printf("Wybierz temperament:\n");
                printf("0 - Spokojny\n");
                printf("1 - Agresywny\n");
                printf("2 - Nieprzewidywalny\n");
                printf("Twoj wybor: ");
                scanf("%d", &temperament_input);
                if (temperament_input < 0 || temperament_input > 2) {
                    printf("Nieprawidlowy wybor temperamentu.\n");
                    break;
                }
                dinozaury[idx].temperament = (Temperament)temperament_input;
                
                printf("Wybierz zagrode:\n");
                printf("0 - Zagroda I\n");
                printf("1 - Zagroda II\n");
                printf("2 - Zagroda III\n");
                printf("3 - Zagroda IV\n");
                printf("4 - Zagroda V\n");
                printf("5 - Izolatka\n");
                printf("Twoj wybor: ");
                scanf("%d", &zagroda_input);
                if (zagroda_input < 0 || zagroda_input > 5) {
                    printf("Nieprawidlowy wybor zagrody.\n");
                    break;
                }
                dinozaury[idx].zagroda = (Zagroda)zagroda_input;
            break;

            case 4:
                if (liczba_dinozaurow == 0) {
                    printf("Brak dinozaurow do usuniecia.\n");
                    break;
                }
                else {
                    for (int i = 0; i < liczba_dinozaurow; i++) {
                        printf("%d. %s\n", i, dinozaury[i].gatunek);
                    }
                    printf("Podaj numer dinozaura do usuniecia: ");
                    scanf("%d", &idx);

                    if (idx < 0 || idx >= liczba_dinozaurow) {
                        printf("Podano nieprawidlowy numer.\n");
                        break;
                    }
                }

                if (dinozaury[idx].status == Zagrozenie || dinozaury[idx].status == Ucieczka) {
                        printf("Nie mozna usunac dinozaura: sytuacja niebezpieczna (%s).\n",
                            status_bezpieczenstwa(dinozaury[idx].status));
                        break;
                    }

                for (int i = idx; i < liczba_dinozaurow - 1; i++) {
                    dinozaury[i] = dinozaury[i + 1];
                }

                liczba_dinozaurow--;

                if (liczba_dinozaurow == 0) {
                    free(dinozaury);
                    dinozaury = NULL;
                    printf("Usunieto ostatniego dinozaura.\n");
                    break;
                }

                tmp = realloc(dinozaury, liczba_dinozaurow*sizeof(Dinozaur));
                if (tmp == NULL) {
                    printf("Blad zmniejszenia tablicy.\n");
                    break;
                }
                dinozaury = tmp;
                printf("Dinozaur zostal poprawnie usuniety.\n");
            break;

            case 5:
                if (liczba_dinozaurow == 0) {
                    printf("Brak dinozaurow do zmiany statusu.\n");
                    break;
                }

                for (int i = 0; i < liczba_dinozaurow; i++) {
                        printf("%d. %s\n", i, dinozaury[i].gatunek);
                    }
                printf("Wybor dinozaura do zmiany statusu (numer): ");
                scanf("%d", &idx);

                if (idx < 0 || idx >= liczba_dinozaurow) {
                    printf("Wybrano nieprawidlowy numer.\n");
                    break;
                }

                printf("Wybierz nowy status bezpieczenstwa:\n");
                printf("0 - Bezpieczny\n");
                printf("1 - Pod obserwacja\n");
                printf("2 - Zagrozenie\n");
                printf("3 - Ucieczka\n");
                printf("4 - Awaryjna kwarantanna\n");
                scanf("%d", &status_input);
                dinozaury[idx].status = (StatusBezpieczenstwa)status_input;
                printf("Status zostal zmieniony.\n");
            break;

            case 6:
                if (liczba_dinozaurow == 0) {
                    printf("Brak dinozaurow do przeniesienia.\n");
                    break;
                }

                for (int i = 0; i < liczba_dinozaurow; i++) {
                        printf("%d. %s\n", i, dinozaury[i].gatunek);
                    }
                printf("Podaj numer dinozaura do przeniesienia: ");
                scanf("%d", &idx);

                if (idx < 0 || idx >= liczba_dinozaurow) {
                    printf("Wybrano nieprawidlowy numer.\n");
                    break;
                }

                printf("Dostepne zagrody:\n");
                printf("0 - Zagroda I\n");
                printf("1 - Zagroda II\n");
                printf("2 - Zagroda III\n");
                printf("3 - Zagroda IV\n");
                printf("4 - Zagroda V\n");
                printf("5 - Izolatka\n");
                printf("Twoj wybor: ");
                scanf("%d", &zagroda_input);
                if (zagroda_input < 0 || zagroda_input > 5) {
                    printf("Nieprawidlowy wybor zagrody.\n");
                    break;
                }
                dinozaury[idx].zagroda = (Zagroda)zagroda_input;
                printf("Dinozaur zostal przeniesiony do nowej zagrody.\n");
            break;

            case 7:
                 // zaplanuj karmienie
            break;

            case 0:
                printf("Koniec programu.\n");
            break;

            default:
                printf("Nieprawidlowy wybor.\n");
        }

    } while (wybor != 0);

    free(dinozaury);
    dinozaury = NULL;
    
    return 0;
}