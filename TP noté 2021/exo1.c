#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define prl { printf("\n"); }
typedef struct json_element_s json_element_t;

typedef enum
{
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
} json_type_t;

struct json_element_s {
    json_element_t* parent;
    json_type_t type; 
    union{
        bool boolean; 
        double nombre; 
        char* s; 
        json_element_t* tab; 
    };
}; 


json_type_t json_type(const json_element_t* e) {
    if(e!=  NULL){
        return e->type;
    }else{
        return JSON_NULL; 
    }
}

json_element_t* json_null() {
    json_element_t* json = NULL; 
    return json; 
}
json_element_t* json_boolean(bool b) {
    json_element_t* json = malloc(sizeof(json_element_t));
    json->type = JSON_BOOLEAN; 
    json->boolean = b; 
    return json;
}
json_element_t* json_number(double d) {
    json_element_t* json = malloc((sizeof(json_element_t)*sizeof(double)));
    json->type = JSON_NUMBER; 
    json-> nombre = d; 
    return json;
}
json_element_t* json_string(const char* s) {
    json_element_t* json = malloc(sizeof(json_element_t)*sizeof(char*)); 
    json -> type  = JSON_STRING; 
    json -> s = strdup(s); 
    return json; 
}
json_element_t* json_array(size_t sz) {
    json_element_t* json = malloc((sizeof(json_element_t)*sz)); 
   
    for(int i=0; i< sz; i++){
        json[i].type = JSON_NULL; 
    }
}
json_element_t* json_get(const json_element_t* e, size_t i) {
    json_element_t* json = malloc(sizeof(json_element_t));  
    if(e->type != JSON_ARRAY){
         fprintf(stderr, "erreur\n"); 
    }
    if(e->tab+i != NULL){
        json = e->tab+i; 
    }
return json; 
}
void json_set(json_element_t* e, size_t i, json_element_t* se) {
    if((e->type) == JSON_ARRAY && se -> parent == NULL && i> sizeof(e->tab) && (e->tab+i)==NULL){
        e->tab[i] = *se; 
        se -> parent = e; 
    } else{
        fprintf(stderr, "erreur\n"); 
    }
}


void json_free(json_element_t* e) {
if(e-> parent == NULL){
    if(e->type == JSON_ARRAY){
        for(int i=0; i< sizeof(e->tab); i++){
            e->tab[i].parent =NULL; 
            json_free(e->tab+i); 
        }
    }else{
        free(e); 
    }
}
}
void json_put(FILE* fd, json_element_t* e) {
    fd = fopen ("name", "w"); 
    switch (e->type){
    case JSON_NULL: fprintf(fd, "tatata"); break; 
    case JSON_BOOLEAN: if(e-> boolean == true){
        fprintf(fd, "true");}
        else{
        fprintf(fd, "false");
        } break; 
    default: fprintf(fd, "toto"); 

}
fclose(fd); 
}
int main() {
json_element_t* e = NULL;
e = json_null(); json_put(stdout, e); prl; json_free(e);
e = json_boolean(true); json_put(stdout, e); prl; json_free(e);
e = json_boolean(false); json_put(stdout, e); prl; json_free(e);
e = json_number(123456.987654); json_put(stdout, e); prl; json_free(e);
e = json_string("Un petit texte"); json_put(stdout, e); prl; json_free(e);
e = json_array(4); json_put(stdout, e); prl;
json_set(e, 0, json_number(1928374566L));
json_set(e, 1, json_string("Un autre texte"));
json_set(e, 3, json_boolean(false));
json_put(stdout, e); prl; json_free(e);
return EXIT_SUCCESS; 
}