#include <stdio.h>
#include <pthread.h>

pthread_t num_thread1;
pthread_t num_thread2;


void my_message1() {

    printf("Un message du thread numéro %d\n", num_thread1);
}

void my_message2() {

    printf("Un message du thread numéro %d\n", num_thread2);
}


int main() {


    // Le thread principal lance 2 threads auxiliaires
    // chacun un message
    pthread_create(&num_thread1, NULL, (void *(*)())my_message1, NULL);
    pthread_create(&num_thread2, NULL, (void *(*)())my_message2, NULL);
}