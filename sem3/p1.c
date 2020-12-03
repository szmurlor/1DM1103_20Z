#include <stdio.h>
#include <stdlib.h>

// W plikach nagłówkowych *.h jest DEKLARACJA funkcji
// W bibliotece wspoldzielonej jest DEFINICJA funkcji

// systemy operacyjne zgodne z POSIX

// argv[0] - nazwa programu
// %f - float
int main(int argc, char *argv[]) {
    // int
    // unsigned int
    // float
    // double
    // char - znak
    // unsigned char

    // napis to tablica znaków  char napis[255];
    // zero "\0" oznacza koniec napisu!

    float v;
    float a1;
    float a2;
    // a1 = atof(argv[1]);
    // a2 = atof(argv[2]);
    // a1 = atof("12.3");
    // a2 = atof("0.1");
    // "12.3" + napis
    a1 = 12.3;
    a2 = 0.1;
    v = a1 + a2;
    printf("[%s] Suma: %f\n", argv[0], v);

    return 0;
}