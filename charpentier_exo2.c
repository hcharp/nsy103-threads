#include <stdio.h>
#include <pthread.h>

pthread_t num_thread1;
pthread_t num_thread2;

// classe struc avec deux attributs parce que sinon j'étais obligée de faire deux fonctions et c'était moche
struct MyThreadsStruct {
    char* msg;
    int zero_ou_un;
};


void my_message(struct MyThreadsStruct * une_structure) {

    if ((*une_structure).zero_ou_un == 0) { // on peut aussi faire avec le raccourci ->zero_ou_un
        fprintf(stdout, "Message : %s\n", une_structure->msg);// c'est plus lisible c'est bo
    } else {
        fprintf(stderr, "Message : %s\n", une_structure->msg);
        }
}


int main() {

    char message1[] = "je suis a et j'en ai marre";
    char message2[] = "zut";

    struct MyThreadsStruct struct1 = {
        message1,
        0
    };

    struct MyThreadsStruct struct2 = {
        message2,
        1
    };
    
    // Le thread principal lance 2 threads auxiliaires
    // chacun un message
    pthread_create(&num_thread1, NULL, (void *(*)())my_message, &struct1);
    pthread_create(&num_thread2, NULL, (void *(*)())my_message, &struct2);

    pthread_join(num_thread1, NULL);
    pthread_join(num_thread2, NULL);
}