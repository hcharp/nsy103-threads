// Exercice 2

// Remarque :
// « Chaque programme Unix possède des flux d'entrée-sortie ouverts pour lui. Par défaut, tout
// processus se voit donc attribuer 3 flux d'entrée-sortie standard. Le flux d'entrée est appelé « entrée
// standard » (standard input), le flux de sortie, « sortie standard » (standard output), et le flux d'erreur
// est souvent appelé « erreur standard » (standard error). Ces noms sont abrégés dans les
// dénominations symboliques de ces fichiers : stdin, stdout et stderr.
// Il faut voir les entrées-sorties standard comme des "flux" d'octets qui sont disponibles en entrée ou
// en sortie du processus. En entrée ces flux sont alimentés par un périphérique ou un fichier ou un
// flux de sortie d'un autre processus. En sortie, le flux est traité par un périphérique ou dirigé vers un
// fichier ou vers un flux d'entrée d'un autre processus.
// Les flux standard sont fermés lors d'un appel à exit(3) ou lors d'une fin normale de programme. »
// Construire un processus lourd avec 3 threads :
// * le thread principal qui lance 2 threads auxiliaires en fournissant un message à chacun ;
// * le premier thread écrit le message obtenu sur la sortie standard (stdout) et se termine par un appel
// à pthread_exit en renvoyant la chaîne de caractères "Je suis A et j'ai fini\n" ;
// * le second thread écrit le message obtenu sur la sortie d’erreur (stderr) et se termine en renvoyant
// (par terminaison de sa fonction principale) la chaîne de caractères "Je suis B et j'ai fini\n" ;
// Le thread principal attends la terminaison du second thread et affiche la chaîne renvoyée sur la
// sortie standard puis il attends la terminaison du premier thread et affiche la chaîne renvoyée sur la
// sortie d’erreur.


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