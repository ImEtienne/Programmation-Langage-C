#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>

int main(){
    int i;
    printf("Veuillez entrer un entier : ");
    scanf("%d", &i);
    printf("Vous avez entré %d\n", i);
}

