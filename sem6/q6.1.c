#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ile_razy( char *napis, char *szukany_wyraz) {
    int c = 0;
    char *w;
    w = strtok(napis, " ");
    while (w != NULL) {
        if (strcmp(w, szukany_wyraz) == 0)
            c++;
        w = strtok(NULL, " ");
    }
    return c;
}

int main(int argc, char **argv) {
    printf("Wynik: %d.\n", ile_razy(argv[1], argv[2]));
    return 0;
}