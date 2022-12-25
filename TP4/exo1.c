#include <stdio.h>
#include <stdlib.h>


//Types énumérés
typedef enum {
  January = 1,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December,

  Jan = January,
  Feb,
  Mar,
  Apr,

  Jun = June,
  Jul,
  Aug,
  Sep,
  Oct,
  Nov,
  Dec,
} month_t;

//la fonction du type enum
void print_month (month_t m){
    switch (m)
    {
    case January :
        printf("Janvier\n");
        break;
    case February :
        printf("Février\n");
        break;
    case March :
        printf("Mars\n");
        break;
    case April :
        printf("avril\n");
        break;
    case May:
        printf("mai\n");
        break;
    case June :
        printf("juin\n");
        break;
    case July :
        printf("Juillet\n");
        break;
    case August :
        printf("Août\n");
        break;
    case September:
        printf("Septembre");
        break;
    case October :
        printf("octobre\n");
        break;
    case November :
        printf("Novembre\n");
        break;
    case December :
        printf("Décembre");
    default:
        printf("le mois n'existe pas !");
        break;
    }
}

//Types produits
typedef struct {
    unsigned char day;
    month_t month;
    short year;
}date_t;


//la fonction du type produit
void date_t date(unsigned char d, month_t m, short y){
    date_t date = {.day = d, .year = y, .month = m};
    return date;
}

//affiche la date
/*
void print_date(date_t d){
     print_date(date(1,Feb,3456));
}
*/
//Types sommes
typedef union {
  long sec;
  date_t = date;
}timestamp_t;




//main
int main(){
    month_t m = June;
    print_month(m);
    printf("%lld\n", sizeof(month_t));
    printf("%d\n", June);

    month_t m1 = March;
    month_t m2 = Mar;
    if (m1 != m2) {
        fprintf(stderr, "Failure!!\n");
        exit(EXIT_FAILURE);
    }
    printf("Afficher les types produits\n");
    printf("%lld\n", sizeof(date_t));

    printf("Afficher les types sommes\n");
    printf("%lld\n", sizeof(timestamp_t));
    
    return EXIT_SUCCESS;
}