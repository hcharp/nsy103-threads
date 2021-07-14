#include <stdio.h>
#include <pthread.h>

pthread_t num_thread1;
pthread_t num_thread2;

// classe struc avec deux attributs parce que sinon j'étais obligée de faire deux fonctions et c'était moche
struct MyThreadsStruct {
    char* msg;
    int zero_ou_un;
    char* autre_msg;
};


char* my_little_threads(struct MyThreadsStruct * une_structure) {

    if ((*une_structure).zero_ou_un == 0) { // on peut aussi faire avec le raccourci ->zero_ou_un
        fprintf(stdout, "Message : %s\n", une_structure->msg);// c'est plus lisible c'est bo
        pthread_exit(une_structure->autre_msg);
    } else {
        fprintf(stderr, "Message : %s\n", une_structure->msg);
        return une_structure->autre_msg;
        }
}


int main() {

    char message11[] = "je suis a et j'en ai marre";
    char message12[] = "je suis a et j'AI ENFIN FINI ELKJFLDKJFLDKNF";
    char message21[] = "zut";
    char message22[] = "PROUT";

    char* retour_de_my_little_threads;

    struct MyThreadsStruct struct1 = {
        message11,
        0,
        message12
    };

    struct MyThreadsStruct struct2 = {
        message21,
        1,
        message22
    };
    
    // Le thread principal lance 2 threads auxiliaires
    // chacun un message
    pthread_create(&num_thread1, NULL, (void *(*)())my_little_threads, &struct1);
    pthread_create(&num_thread2, NULL, (void *(*)())my_little_threads, &struct2);

    pthread_join(num_thread2, &retour_de_my_little_threads); // fin du thread2
    // j'ai donné au thread1 l'adresse où il va écrire
    // et puis il se finit aussi
    // et comme il est fini, on écrit le message :
    fprintf(stdout, "Message : %s\n", retour_de_my_little_threads);

    pthread_join(num_thread1, &retour_de_my_little_threads);
    // j'ai donné au thread1 l'adresse où il va écrire
    // et puis il se finit aussi
    // et comme il est fini, on écrit le message :
    fprintf(stderr, "Message : %s\n", retour_de_my_little_threads);
}