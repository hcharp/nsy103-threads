#include <stdio.h>
#include <pthread.h>


void numero_et_double() {
    printf("truc");
}

int main() {
    int n;
    pthread_t tab[n];

    // Génération de n threads
    for (int i = 0; i < n; i++)
    {
        pthread_t num_thread;
        int pthread_create(&num_thread, NULL, (void *(*)())numero_et_double, NULL);
        tab[i] = num_thread;

    }

    for (int i = 0; i < n; i++) {
    pthread_join(tab[i], NULL);
    }
}