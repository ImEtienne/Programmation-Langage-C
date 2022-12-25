#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>

int main() {                                          
  char * c[4] = {"ENTER","NEW","POINT","FIRST"};
  char ** cp[4] = { c+3, c+2, c+1, c};
  char *** cpp = cp;
 
  printf("%s",**++cpp);
  printf("%s ",*--*++cpp+3);
  printf("%s",*cpp[-2]+3);
  printf("%s\n",cpp[-1][-1]+1);
  return EXIT_SUCCESS;
}