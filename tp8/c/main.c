#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

typedef __int128 set; //On au maximum 100 éléments, donc on fait un ensemble de 128 bits

double* rocks_weight;
size_t rocks_len;
double total_weight = 0;

void find(set s, double set_weight, int chosen_debug) {
    double remaining = total_weight-set_weight;
    double margin = (remaining / 100.) * 2.;
    if(set_weight > remaining+margin) {
        return; //On a dépassé, donc on backtrack
    } else if(set_weight < remaining-margin) { //On tente de trouver un élément à ajouter
        set try_set = s;
        double difference = remaining-set_weight;

        while(1) {
            double bestDelta = DBL_MAX;
            int bestIndex = -1;

            for(int i = 0; i < rocks_len; ++i) {
                if(!(try_set & (1 << i))) {
                    double delta = fabs(difference - rocks_weight[i]);
                    if(delta < bestDelta) {
                        bestDelta = delta;
                        bestIndex = i;
                    }
                }
            }

            if(bestIndex == -1) {
                return; //On a tout essayé, en vain; On backtrack
            } else {
                find(s | (1 << bestIndex), set_weight + rocks_weight[bestIndex], bestIndex);
                //Si l'éxecution continue, c'est qu'on a échoué; On ajoute au essai et on continue
                try_set |= 1 << bestIndex;
            }
        }
    } else { //On a trouvé notre ensemble: on l'affiche et on quitte
        for(int i = 0; i < rocks_len; ++i) {
            if(s & (1 << i)) {
                printf("%d ", i+1); //Comme les éléments ont des indices entre 1 et 100 ont doit les incrémenter.
            }
        }
        exit(0);
    }
}

int main() {
    scanf("%ud", &rocks_len);
    rocks_weight = malloc(sizeof(double) * rocks_len);
    total_weight = 0;

    for(int i = 0; i < rocks_len; ++i) {
        scanf("%lf", &rocks_weight[i]);
        total_weight += rocks_weight[i];
    }
    getc(stdin); //On se débarrasse du dernier 0
    find(0, 0, 0);
    fprintf(stderr, "\nAucune solution trouvée.\n");
    return 1;
}