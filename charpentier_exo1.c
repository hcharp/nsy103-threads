// Exercice 1

// Soit le programme essai.c suivant :
// (voir plus bas)
// L’exécution génère les traces suivantes. Commentez les résultats dans un fichier texte.
// hello,
// hello,
// hello,
// hello,
// thread
// thread
// thread
// thread
// principal 1000
// fils 1010
// principal 3010
// fils 3030


#include <stdio.h>
#include <pthread.h>

int i; // déclaration i entier VARIABLE GLOBALE

void addition() {
    i = i + 10;
    /* selon la valeur courante de i (globale), on y ajoute 10 */
    printf ("hello, thread fils %d\n", i);

    i = i + 20;
    /* selon la valeur courante de i (globale), on y ajoute 10 */
    printf ("hello, thread fils %d\n", i);
}

int main() {
    pthread_t num_thread; // équivalent du pid_t : c'est le type des numéros de threads
    i = 0; // affectation i valeur 0

    if (pthread_create(&num_thread, NULL, (void *(*)())addition, NULL) == -1) {
    
    // même si c'est dans un if, ça exécute la fonction pthread_create

    /* si la valeur retournée par le pthread_create est -1
    c'est-à dire, si aucun thread n'a été créé à cause d'une erreur, alors..
    */
   /* &num_thread : adresse du thread
    NULL : options (par défaut)
    addition : fonction qui s'exécute au lancement du thread (équivalent d'un main())
    le format void*(*)() est un pointeur de fonction
    NULL : argument passé à la fonction (mais addition ne prend pas d'arguments)
   */
        perror ("pb pthread_create\n");
    
    } // j'ai rajouté l'accolade sinon je comprenais rien et puis après c'est un else en fait

    i = i + 1000; 
    /* 
    Ici on est dans le parent
    Le parent n'exécute pas addition
    Donc tout bêtement, il avait i=0, il retourne i=1000

    Mais comme i est une variable globale, si le fils a changé i avant que
    le parent n'ait eu le temps, on a i=1010
    (voire 1030 s'il avait le temps d'exécuter la 2ème ligne)
    */
    printf ("hello, thread principal %d\n", i);

    i = i + 2000;
    /* 
    Ici on est dans le parent
    Le parent n'exécute pas addition
    Donc tout bêtement, il avait i=1000, il retourne i=3000

    Mais comme i est une variable globale, si le fils a changé i avant que
    le parent n'ait eu le temps, on a i=3010
    (voire 3030 s'il avait le temps d'exécuter la 2ème ligne)
    */
    printf ("hello, thread principal %d\n", i);

    pthread_join(num_thread, NULL);
    // on attend la fin du fils pour terminer le parent (sinon orphelin)
}