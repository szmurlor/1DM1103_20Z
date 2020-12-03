#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void nawielkie(char * n) {
    for (int i=0; i< strlen(n); i++)
        n[i] = toupper(n[i]);
}

int main(int argc, char *argv[]) {
    char napis[255];
    printf("%s ma dlugosc: %ld\n", argv[1], strlen(argv[1]));

    printf("Przed\n");
    strncpy(napis, argv[2], 254);
    nawielkie(napis);
    printf("Po\n");
    printf("%s ma dlugosc: %ld\n", napis, strlen(napis));

    return 0;
}