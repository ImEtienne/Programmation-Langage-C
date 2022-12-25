#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
 
// Définition du type expr_t
typedef struct expr_s expr_t;
typedef struct binaire_s binaire_t;
typedef struct entier_s entier_t;
typedef struct variable_s variable_t;
typedef struct unaire_s unaire_t;

/*struct entier_t{
    int i;
};

struct variable_t{
    char *v;
};

struct binaire_t{
   int (*f)(int x, int y);
   expr_t* left;
   expr_t* right;
};

struct unaire_t{
    int (*f)(int s);
    expr_t* x;
};*/

struct expr_t{
    expr_t *parent;
    enum
    {
        CONSTANT, VARIABLE, UNAIRE, BINAIRE;
    }type;
    union{
        struct constant{
            int en;
        };
        struct variable{
            char *v;
        };

        struct unaire {
            int (*f)(int z);
            expr_t* t;
        };

        struct binaire{
            int (*f)(int x, int y);
            expr_t* left;
            expr_t* right;
        };
    };
};

// Constructeurs
expr_t* expression() {
    expr_t *exp = malloc(sizeof(expr_t));
    exp->parent=NULL;
    return exp;
}
 
expr_t* constant(int i) {
    expr_t *e = expression();
    e->type = constant;
    e->constant.en = i;
    return e;
}
 
expr_t* variable(char x) {
    expr_t *e = expression();
    e->type = variable;
    e->variable.v = x;
    return e;
}
 
expr_t* unary_expr(expr_t* se, int (*f)(int)) {
    expr_t* e = expression();
    e->type = unaire;
    se->parent = e;

    return e;
}
 
expr_t* binary_expr(expr_t* se1, expr_t* se2, int (*f)(int, int)) {
    expr_t* e = expression();
    e->type = binaire;
    e->binaire.se1 = se1;
    e->binaire.se2 = se2;
    e->binaire
    return e;
}

expr_t* binary_expr(expr_t* se1, expr_t* se2, int (*f)(int, int)) {
    expr_t *e = expression();
    if (se1->parent!=NULL &&se2->parent!=NULL){
        return NULL;
    }
    else{
        se1->parent = e;
        se2->parent = e;
        e->type = Binaire;
        e->binaire.f = f;
        e->binaire.left = se1;
        e->binaire.right = se2;
        return e;
    };
}
 
 
// Destructeur
 
void delete_expr(expr_t* e) {
    if(e->parent == NULL && e->exp != NULL){
        e->exp = NULL;
        free(e->parent);
    }
    free(e);
}
 
 
// Evaluateur
 
int eval_expr(expr_t* e, int* env) {
    switch (e->type){
    case CONSTANT:
        free(e->constant);
        break;
    case VARIABLE:
        free(e->varaible);
        break;
    case UNAIRE:
        free(e->unaire);
        break;
    case BINAIRE:
        free(e->binaire);
        break;
    
    default:
        printf('erreur type');
        break;
    }
}
 
 
// Programme principal
 
int neg(int a) { return -a; }
int add(int a, int b) { return a+b; }
int mult(int a, int b) { return a*b; }
 
int main() {
    // Expression: -(3 * x + y)
    expr_t* e = 
        unary_expr(
            binary_expr(
                binary_expr(
                    constant(3),
                    variable('x'),
                    mult),
                variable('y'), add),
            neg);
 
    int env[256];
    int x, y;
    for(x = -2; x <= 3; x++)
        for(y = -2; y <= 3; y++) {
            env['x'] = x;
            env['y'] = y;
            printf("(x = %d, y = %d) -> %d\n", x, y, eval_expr(e, env));
        }
 
    return EXIT_SUCCESS;
}