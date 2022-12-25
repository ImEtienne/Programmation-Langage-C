#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
    double f;
  for (f = 1.0; f != 0.0; f -= 0.1) {
    printf("%g\n", f);
    if (f < 0.0) exit(EXIT_FAILURE);
  }
}