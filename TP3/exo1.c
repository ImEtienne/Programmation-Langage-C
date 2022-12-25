#include <stdio.h>
#include <stdlib.h>

int main (){
    double flottants[12] = { 0.0,
			 -0.0,
			 123456123456123456,
			 1234561234561234561234,
			 1234561234561234561234.0,
			 0.123456123456123456123456,
			 0.000123456123456123456123456,
			 0.000000123456123456123456123456,
			 0.0000000000000123456123456123456123456,
			 1.23456123456123456123456e-14,
			 1.23456123456123456123456e-128,
			 1.23456123456123456123456e-324 };
    printf("%f\n", flottants[0]);
    printf("%.10f\n", flottants[1]);
    printf("%e\n", flottants[2]);
    printf("%E\n", flottants[3]);
    printf("%g\n", flottants[3]);
    printf("%G\n", flottants[4]);
    //printf("%f\n", flottants[0]);
}