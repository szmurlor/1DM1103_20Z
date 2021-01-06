#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int n  = atoi(argv[1]);
    FILE *fout = argc > 2 ? fopen(argv[2], "w") : stdout;

    fprintf(fout, "%d\n", n);
    while (n--) {
        fprintf(fout, "%.1f\n",  ((float) (rand() % 100)) / 10.0);
    }

    fclose(fout);
    return 0;
}