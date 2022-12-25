#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>


void swap_charptr(char** x, char** y){
    char* c;
     printf("Before: a = %p, b = %p\n", x, y);
    c = *x; *x = *y; *y = c;
    printf("After: a = %p, b = %p\n", x, y);
}

int main() {
  char a = 12; char* ptr_a = &a; 
  char b = 40; char* ptr_b = &b;

  printf("Before: a = %p, b = %p\n", ptr_a , ptr_b);
  swap_charptr(&ptr_a, &ptr_b);
  printf("after: a = %p, b = %p\n", ptr_a, ptr_b);
  
}