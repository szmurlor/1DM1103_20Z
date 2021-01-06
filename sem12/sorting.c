#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int check_sort(float *data, int n) {
    while (--n > 0) 
        if (data[n-1] > data[n]) {
            printf("Niewlasciwe posortowanie na pozycji data[%d] = %.1f > data[%d] = %.1f\n", n-1, data[n-1], n, data[n]);
            return 0;
        }
    
    return 1;
}

void bubble(float *data, int n) {
    int i,j;
    for (i=0;i<(n-1);i++)
        for (j=0;j<(n-1);j++)
            if (data[j] > data[j+1]) {
                float t = data[j];
                data[j] = data[j+1];
                data[j+1] = t;
            }
}

void select_sort(float *data, int n) {
    int i,j;
    float t;
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
            if (data[i] > data[j]) {
                t = data[j];
                data[j] = data[i];
                data[i] = t;
            }
}

void wypisz(float *data, int n) {
    int i;
    for (i=0; i < n; i++) {
        printf("%.1f, ", data[i]);
    }
    printf("\n");
}

void do_merge(float *data, int start, int middle, int end) {
    int first_n = middle - start;
    int second_n = end - middle;
    int f, s;
    int i = 0;
    float res[first_n + second_n];
    // printf("%d,%d,%d\n", start, middle,end);
    f = start;
    s = middle;
    while (f < middle && s < end) {
        if (data[f] < data[s]) {
            res[i++] = data[f];
            // printf("f %.1f\n", data[f]);
            f++;
        } else {
            res[i++] = data[s];
            // printf("s %.1f\n", data[s]);
            s++;
        }
    }

    while (f < middle) {
        res[i++] = data[f];
        // printf("fw %.1f\n", data[f]);
        f++;
    }

    while (s < end) {
        res[i++] = data[s];
        // printf("sw %.1f\n", data[s]);
        s++;
    }

    for (i=0; i<(first_n+second_n); i++) {
        data[start + i] = res[i];
    }
}

// 1 6 2 3 7 2 3 5
void merge_sort(float *data, int n) {
    int slice = 1;
    int i;
    
    // printf("Before: %d\n", slice);
    // wypisz(data,n);

    while (slice < n) {
        for (i=0; i < n; i += 2*slice) {
            do_merge(data, i, i+slice, i+2*slice < n ? i+2*slice : n);
        }
        //printf("Slice: %d\n", slice);
        //wypisz(data,n);
        slice *= 2;
    }
}


int main(int argc, char **argv) {
    clock_t start,end;
    float secs;
    float *data_original;
    float *data;
    int n;
    int i;
    FILE *fin = fopen(argv[1],"r");

    fscanf(fin, "%d", &n);
    data_original = (float*) malloc(sizeof(float)*n);
    data = (float*) malloc(sizeof(float)*n);
    for (i=0;i<n;i++)
        fscanf(fin, "%f", &data_original[i]);
    fclose(fin);

    memcpy(data, data_original, sizeof(float)* n);
    start =  clock();
    bubble(data, n);
    end =  clock();
    secs = ((double)(end - start)) / CLOCKS_PER_SEC; 
    printf("time bubble: %fs\n", secs);
    printf("sort %s\n", check_sort(data,n) ? "Success" : "Error");

    memcpy(data, data_original, sizeof(float)* n);
    start =  clock();
    select_sort(data, n);
    end =  clock();
    secs = ((double)(end - start)) / CLOCKS_PER_SEC; 
    printf("time select sort: %fs\n", secs);
    printf("sort %s\n", check_sort(data,n) ? "Success" : "Error");


    memcpy(data, data_original, sizeof(float)*n);
    start =  clock();
    merge_sort(data, n);
    end =  clock();
    secs = ((double)(end - start)) / CLOCKS_PER_SEC; 
    printf("time mergesort: %fs\n", secs);
    printf("merge sort %s\n", check_sort(data,n) ? "Success" : "Error");

//    for (i=0;i<n;i++)
//        printf("%.2f, ", data[i]);
//    printf("\n");

    free(data_original);
    free(data);

    printf("Done.\n");

    return 0;
}