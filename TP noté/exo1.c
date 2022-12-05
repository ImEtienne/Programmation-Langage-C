#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#define UNKNOWN NULL
 
typedef struct {
    char day;
    char month;
    short year;
} date_t;
 
date_t date(char d, char m, short y) {
    date_t r;
    r.day = d;
    r.month = m;
    r.year = y;
    return r;
}
 
// d1 <= d2  <=>  cmp_date(d1,d2) <= 0
int compare_date(date_t d1, date_t d2) {
    short dy = d1.year - d2.year;
    if (dy != 0)
        return dy;
    char dm = d1.month - d2.month;
    if (dm != 0)
        return dm;
    char dd = d1.day - d2.day;
    if (dd != 0)
        return dd;
    return 0;
}
 
void print_date(date_t d) {
    printf("%02hhd/%02hhd/%04hd", d.day, d.month, d.year);
}
 
 
///////////////////////////////////////////////////////////////////////////////////////////
 
typedef const char* person_t;
typedef struct event_s event_t;
typedef struct birth_s birth_t;
typedef struct death_s death_t;
typedef struct wedding_s wedding_t;
typedef struct divorce_s divorce_t;

struct birth_t {
    person_t pere;
    person_t mere;
    person_t enfant;
};

struct death_t{
    person_t defunt;
    date_t death;
};

struct wedding_t{
    person_t m1;
    person_t m2;
};

struct divorce_t{
    event_t* wedding;
}

// Définition du type event_t
struct event_t {
    date_t date;
    event_t* precedent;
    event_t* next;
    enum
    {
        BIRTH,
        DEATH,
        MARIAGES,
        DIVORCE
    } type;
    union{
        person_t birth;
        person_t death;
        person_t wedding;
        person_t divorce;
    };
    event_t *previous;
};

// Constructeurs
event_t* event(date_t d, event_t* previous) {
    event_t *event = malloc(sizeof(event_t));
    event->date = &d;
    event->next=NULL;
    if(previous != NULL){
        if(previous->next == NULL && compare_date(previous->date, d) < 0){
            event->precedent = previous;
            previous->next = event;
        }
    }
    return event;
}

event_t* birth(date_t d, person_t mother, person_t father, person_t child, event_t* prev) {
    event_t e = event(d, prev);
    e->event = birth;
    e->birth.mother = mother;
    e->birth.father = father;
    e->birth.child = child;
    return e;
}
 
event_t* wedding(date_t d, person_t groom, person_t bride, event_t* prev) {
    event_t *e = event(d, prev);
    e->event = mariage;
    e->mariage.m1 = groom;
    e->mariage.m2 = bride;
    return e;
}
 
event_t* divorce(date_t d, event_t* wedding, event_t* prev) {
    event_t *e = event(d, prev);
    e->event = divorce;
    e->divorce.defunt = wedding;
    return e;
}
 
event_t* death(date_t d, person_t person, event_t* prev) {
    event_t *e = event(d, prev);
    e->event = death;
    e->death.defunt = person;
    return e;
}
 
 
// Destructeur
 
void delete_event(event_t* e) {
    if(e->precedent == NULL && e->next != NULL){
        e->next->precedent = NULL;
        free(e->next);
    }
    free(e);
}
 
// Afficheur
 
void print_event(event_t* e) {
    print_t date(e->date);
    printf(":\n");
    switch(e->type){
        case death:
            free(e->DEATH);
            break;
        case birth:
            free(e->BIRTH);
            break;
        case wedding:
            free(e->WEDDING);
            break;
        case divorce:
            free(e->DIVORCE);
            break;
        default: printf("type incorrect");
    }

}
 
void print_chronology(event_t* e) {
    if (e == NULL) return;
    print_event(e);
    print_chronology(e->next);
}
 
 
// Programme principal
 
int main() {
    const char* H8 = "Henri VIII";
    const char* CA = "Catherine d'Aragon";
    const char* AB = "Anne Boleyn";
    const char* E1 = "Elisabeth I";
    const char* JS = "Jane Seymour";
    const char* E6 = "Edouard VI";
    const char* AC = "Anne de Clèves";
    const char* CH = "Catherine Howard";
    const char* CP = "Catherine Parr";
 
    event_t *e, *start, *w1, *w2;
    e = NULL;
    start = e = birth(date(16,12,1485), UNKNOWN, UNKNOWN, CA, e);
    e = birth(date(28,6,1491), UNKNOWN, UNKNOWN, H8, e);
    w1 = e = wedding(date(11,6,1509), H8, CA, e);
    e = wedding(date(25,1,1533), H8, AB, e);
    e = divorce(date(23,5,1533), w1, e);
    e = birth(date(7,9,1533), AB, H8, E1, e);
    e = death(date(7,1,1536), CA, e);
    e = wedding(date(30,5,1536), H8, JS, e);
    e = birth(date(12,10,1537), JS, H8, E6, e);
    w2 = e = wedding(date(6,1,1540), H8, AC, e);
    e = divorce(date(9,7,1540), w2, e);
    e = wedding(date(28,7,1540), H8, CH, e);
    e = wedding(date(12,7,1543), H8, CP, e);
    e = death(date(28,1,1547), H8, e);
    e = death(date(6,7,1553), E6, e);
    e = death(date(24,3,1603), E1, e);
 
    print_chronology(start);
    delete_event(start);
    return EXIT_SUCCESS;
}