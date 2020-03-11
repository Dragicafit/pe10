#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int nb;
    int a;
    int b;
    fscanf(STDIN_FILENO, "%i %i %i", &nb, &a, &b);
    int x[nb];
    for (int i = 0; i < nb; i++) {
        fscanf(STDIN_FILENO, "%i", &(x[i]));
    }
    return 0;
}
