#include <stdlib.h>
#include <stdio.h>

int nb;
int x[34];
int a;
int b;

unsigned long long count;

void rec(int sum, int i) {
    if(i > nb) count++;
    if(sum + x[i] >= a && sum + x[i] <= b) {
        rec(sum + x[i], i+1);
    }
    rec(sum, i+1);
}

int main(int argc, char const *argv[]) {

    scanf("%i %i %i", &nb, &a, &b);
    for (int i = 0; i < nb; i++) {
        scanf("%i", &(x[i]));
    }

    count = 0;

    rec(0, 0);

    printf("%i", count);

    return 0;
}
