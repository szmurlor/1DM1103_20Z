#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"


int main(int argc, char ** argv) {
    SBaza *baza;
    baza = wczytaj_baze(argv[1]);

    if (strcmp("list_students", argv[2]) == 0) {
        listuj_studentow(baza);
    }

    zapisz_baze(argv[1], baza);
    zwolnij(baza);
    return 0;
}