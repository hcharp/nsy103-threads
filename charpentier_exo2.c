#include <stdio.h>
#include <pthread.h>


void my_message(int num) {

    printf("Un message du thread numéro %d\n", num);
}


int main() {
    int num_thread1;
    int num_thread2;


    // Le thread principal lance 2 threads auxiliaires
    // avec un message chacun
    pthread_create(&num_thread1, NULL, void*(*)())my_message, &num_thread1);
    pthread_create(&num_thread2, NULL, void*(*)())my_message, &num_thread2);
}