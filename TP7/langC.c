#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>


int main() {
    char* c[4] = { "LXJSD", "FTPVG", "ZBMAQ", "EUHKO" };
    char** cp[4] = { c + 0, c + 1, c + 3, c + 2 };
    char*** cpp = cp + 1;
    printf("%s\n", (*(cpp + 1))[-1] + 3);
    return EXIT_SUCCESS;                
}