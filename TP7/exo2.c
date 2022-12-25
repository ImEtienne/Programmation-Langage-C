#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>
 
int main() {
    int *p = NULL;
    printf("Contenu de *p : %d\n", *p); // pour afficher l'adresse de P, il faut
    return EXIT_SUCCESS;                // %p
}