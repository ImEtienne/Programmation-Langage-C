#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>

void mac(){
    int *p1 = malloc(sizeof(int) * 100);
    
    for (int i = 0; i < 100; i++){
        printf("contenu : %d\n", p1[i]);
    }
    for (int i = 0; i < 100; i++){
        p1[i] = i;
    }
    for (int i = 0; i < 100; i++){
        printf("contenu : %d\n", p1[i]);
    }
    free(p1);

    for (int i = 0; i < 100; i++){
        printf("contenu : %d\n", p1[i]);
    }
    int *p2 = malloc(sizeof(int) * 100);
    
    for (int i = 0; i < 100; i++){
        printf("contenu : %d\n", p2[i]);
    }
}


int main(){
    mac();
    return EXIT_SUCCESS;
}