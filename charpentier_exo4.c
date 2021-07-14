// Exercice 4

// Écrire un programme qui effectue les opérations suivantes :
// - remplit un tableau de 20 entiers avec des valeurs tirées aléatoirement entre 1 et 1000.
// - recherche la valeur maximale dans le tableau, à l'aide de n threads. Chaque thread recherche la
// valeur maximale dans une sous-partie du tableau, et renvoie cette valeur. Le thread principal
// recherche le maximum parmi les valeurs retournées.


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define TAILLE_TAB 20


void remplir(int* table) {
    for (int i = 0; i < TAILLE_TAB; i++)
    {
        table[i]=1+rand()%999; // 1 parce que sinon ça commence à 0 ; 999 parce que sinon ça finit à 1001
        // printf("valeur = %d\n", table[i]);
    }
    
}


int rechercher_max(int* table) {
    int max = table[0];
    for (int i = 1; i < TAILLE_TAB/2; i++)
    {
        if (table[i]>max) {
            max = table[i];
            printf("petitmax = %d\n", max);
        }
    }
    return max;
    printf("Max = %d\n", max);

}


int main() {

    int tab[TAILLE_TAB];
    int le_max=0;
    remplir(tab);
    printf("valeur = %d\n", tab[5]);
    printf("valeur = %d\n", tab[15]);
    pthread_t thr1;   
    pthread_create(&thr1, NULL, (void *(*)())rechercher_max, &tab[0]);
    pthread_join(thr1, &le_max);
    pthread_t thr2;    
    pthread_create(&thr2, NULL, (void *(*)())rechercher_max, &tab[10]);
    pthread_join(thr2, &le_max);


    printf("Max = %d\n", le_max);
}