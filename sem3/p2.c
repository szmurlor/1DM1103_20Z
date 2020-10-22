#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char n[100]; // zarezerwuj pamiec dla tablicy 100 znakow
    int i;
    char n2[] = "Wielki i długi napis.";
    char *n3;
    char tab[10][10];

    strcpy(tab[0], "akuku");
    strcpy(tab[1], "hello");
    strcpy(n, "Ala");
    // n2 = "Nowego napisu!";
    printf("%s, %s, %s, %s\n", n, n2, tab[0], tab[1]);

    for (i=0; i < 4; i++) {
        printf("[%d] %c, %d\n", i, n[i], n[i]);
    }

    printf("Trzeci znak z pierwszego napisu argv: %c\n", argv[0][2]);

    return 0;
}