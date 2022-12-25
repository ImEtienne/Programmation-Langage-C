typedef struct expr_s expr_t;
struct expr_s
{
    expr_t *parent;
    enum
    {
        Constante,
        Variable,
        Unaire,
        Binaire
    } type;
    union 
    {
        struct 
        {
            int entier;
        }constante;
        struct 
        {
            char *var;
        }variable;
        struct 
        {
            int (*f)(int s);
            expr_t* x;
        }unaire;
        struct 
        {
            int (*f)(int x, int y);
            expr_t* g;
            expr_t* d;
        }binaire;
    };
};

// Constructeurs

expr_t* expression() {
    expr_t *e = malloc(sizeof(expr_t));
    e->parent = NULL;
    return e; 
}

expr_t* constant(int i) {
    expr_t *e = expression();
    e->type = Constante;
    e->constante.entier = i;
    return e;
}

expr_t* variable(char x) {
    expr_t *e = expression();
    e->type = Variable;
    e->variable.var = x;
    return e;
}
 
expr_t* unary_expr(expr_t* se, int (*f)(int)) {
    expr_t *e = expression();
    
}