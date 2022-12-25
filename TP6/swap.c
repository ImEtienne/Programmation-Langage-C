#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>

 
void swap(int a, int b) {
  int c;
  printf("Before: a = %d, b = %d\n", a, b);
  c = a; a = b; b = c;
  printf("After: a = %d, b = %d\n", a, b);
}
 
int main() {
  int x = 123;
  int y = 456;
  printf("Before: x = %d, y = %d\n", x, y);
  swap(x, y);
  printf("After: x = %d, y = %d\n", x, y);
  return EXIT_SUCCESS;
}