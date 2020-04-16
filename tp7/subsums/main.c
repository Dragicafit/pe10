#include <stdlib.h>
#include <stdio.h>

int nb;
int x[34];
int a;
int b;

unsigned long long count;

long sum(long ensemble) {
    long ret = 0;
    for(int i = 0; i < 34; ++i) {
        if((ensemble & (1 << i)) > 0) {
            ret += x[i];
        }
    }
    return ret;
}

void rec(long ensemble) {
    long somme = sum(ensemble);
    if(somme < a) {
        for(int i = 0; i < 34; ++i) {
            if(x[i] > 0 && (somme + x[i]) <= b && ((ensemble & (1 << i)) > 0)) {
                ++count;
                rec(ensemble ^ (1<<i));
            }
        }
    } else if(somme > b) {
        for(int i = 0; i < 34; ++i) {
            if(x[i] < 0 && (somme + x[i]) >= a && ((ensemble & (1 << i)) > 0)) {
                ++count;
                rec(ensemble ^ (1<<i));
            }
        }
    } else {
        for(int i = 0; i < 34; ++i) {
            if ((somme + x[i]) <= b && (somme + x[i]) >= a && ((ensemble & (1 << i)) > 0)) {
                ++count;
                rec(ensemble ^ (1 << i));
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    scanf("%i %i %i", &nb, &a, &b);
    for (int i = 0; i < nb; i++) {
        scanf("%i", &(x[i]));
    }

    count = 1;

    rec(0);

    printf("%llu", count);

    return 0;
}
