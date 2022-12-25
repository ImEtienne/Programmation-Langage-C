#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>


int main(){
    int *p = malloc(sizeof(int) * 100);
    //printf("%p", p);
    int *i = 0;
    
    while(i!=-1){
        printf("valeur de i=%d, l'adresse =%p, la valeur(contenu) =%d,\n", i, (p+i) ,*(p+i));
        i++;
    }
}