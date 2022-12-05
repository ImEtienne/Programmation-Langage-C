#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>

int main(){
    char s[5] = "\0\0\0\0\0"; 
    printf("Veuillez entrer une chaine : ");
    scanf("%4s", s);
    printf("Vous avez entre %4s\n", s);
}