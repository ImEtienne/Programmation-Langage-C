#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>


int main() {
  char c; char* ptr_c = &c;
  int i; int* ptr_i = &i;
  double d; double* ptr_d= &d;

 //int *a : variable de type int* 
 //char* : une adresse vers un char
 //int* : une adresse vers un int

//*ptr_c : la variable pointéé
//ptr_c : le valeur du pointeur
//&ptr_c : la valeur pointée

    //l'adresse contenue par le pointeur
  printf("prt_c = %p\n", ptr_c);
  printf("prt_i = %p\n", ptr_i);
  printf("prt_d = %p\n", ptr_d);

  printf("prt_c = %p\n", ptr_c + 1);
  printf("prt_i = %p\n", ptr_i + 1);

   //la variable ou valeur pointée
  printf("prt_c = %u\n", *ptr_c);
  printf("prt_i = %d\n", *ptr_i);
  printf("prt_d = %f\n", *ptr_d);

    //la taille
  printf("prt_c = %lld\n", sizeof(char*));
  printf("prt_i = %lld\n", sizeof(int*));
  printf("prt_d = %lld\n", sizeof(double*));
 
  return EXIT_SUCCESS;
}