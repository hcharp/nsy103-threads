// Exercice 3

// Écrire un programme générant N threads (N est constant). A chaque thread est associé un numéro
// (compris entre 1 et N) et qui permet :
// - chaque thread créé affiche son numéro, puis se termine en retournant la valeur de son numéro
// multipliée par 2.
// - le thread principal, quant à lui, attend la terminaison des threads qu'il a créés, et affiche leur valeur
// de retour.


#include <stdio.h>
#include <pthread.h>
#define N 10


int numero_et_double(int num) {
    printf("Mon numéro est le : %d\n\n", num);
    pthread_exit(num*2);
}

int main() {
    pthread_t tab[N];

    int le_double;

    // Génération de n threads
    for (int i = 1; i < N; i++)
    {
        // pthread_t num_thread;
        // tab[i] = num_thread; 
        // pas nécessaire d'utiliser &num_thread et ces deux lignes
        pthread_create(&tab[i], NULL, (void *(*)())numero_et_double, i);
        

    }

    for (int i = 1; i < N; i++) {
    pthread_join(tab[i], &le_double);
    printf("La terminaison est : %d\nLe double est : %d\n\n", tab[i], le_double);

    }
}