#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int nb;
int x[34];
int a;
int b;

int count;

void rec(int sum, int i) {
    if(i > nb) count++;
    if(sum + x[i] >= a && sum + x[i] <= b) {
        rec(sum + x[i], i+1);
    }
    rec(sum, i+1);
}

int main(int argc, char const *argv[]) {

    fscanf(STDIN_FILENO, "%i %i %i", &nb, &a, &b);
    for (int i = 0; i < nb; i++) {
        fscanf(STDIN_FILENO, "%i", &(x[i]));
    }

    count = 0;

    rec(0, 0);

    printf("%i", count);

    return 0;
}
