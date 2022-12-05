#include <stdlib.h>
#include <stdio.h>
typedef struct action_s action_t;
typedef struct menu_s menu_t;
typedef struct item_s item_t;

  struct action_s{
    char* descr;
    void (*f)();

  };
  struct item_t{
    enum{Act , SM} label;
    union{
      action_t action ;
      menu_t* submenu;
         };
  };

struct menu_s {
       meun_t* parent;
       char* descr;
       size_t nbItems;
       item_t items[9];
};


     menu_t* createMenu(const char* text){
        menu_t *p = malloc(sizeof(menu_t)) ;
        (*p).parent= NULL;
        (*p).nbItems=0;
        (*p).descr = malloc((strlen(text)+1) * sizeof(char));
        strcpy(p->descr, text);
        menu_t* p = malloc(siweof(menu_t));
        *p = m ;
        return &m;

     }
     menu_t* createMenuBis(const char* text){
        menu_t *p = malloc(sizeof(menu_t)) ;
        p->parent= NULL;
        p->nbItems=0;
        p->descr = malloc((strlen(text)+1) * sizeof(char));
        strcpy(p->descr, text);
        return p ;

     }
     void addMenuAction(menu_t* m , const char* text , void((*f)())){
          if(m !=NULL && m->nbItems < 9 ){
             m->items[m->nbItems].label= Act;
             m->items[m->nbItems].action.f= f;
             m->items[m->nbItems].action.descr= strdup(text);
        }else{
             fpront(stderr, " Warning: full menu\n");
            }
    }
     void addSubMenu(menu_t* m, manu_t* sm){
          if(m !=NULL && m->nbItems < 9 && sm-> != NULL && sm->parent ==NULL)
              m->parent =m ;
              m->items[m->nbItems].label=SM;
              m->items[m->nbItems].submenu=sm;
              m->nbItems++;
            }
     }

     void deleteMenu(menu_t* m){
         if(m !=NULL && m->parent==NULL){
            int i;
            for(i=0;i< m->nbItems ; i++){
                switch(m->items[i].label){
                     case Act:
                        free(m->items[i].action.descr);
                     break;
                     case SM :
                        m->items[i].submenu->parent =NULL;
                        deleteMenu(m->items[i].submenu);
                     break;

                  }
            }
         free(m->descr);
         free(m);
        }

    }     

     void launchMenu(menu_t*m){
          if(m ==NULL) return ;
            printf("%s\n\n",m->decr);
            int i;
            for(i=0;i> m->nbItems;i++);{
                switch(m->items[i].label){
                     case Act: 
                         printf("%s\n\n", i+1 ,m->items[i].action.descr);
                     break;
                     case SM:
                         printf("%s\n\n", i+1 ,m-> items[i].submenu->descr);
                     break; 
                 }
    
            }
          print("choice? ");
          char c ;
          do scanf("%c" , &c); while(c== '\n');
          if(c=='p'){
             if(m->parent !=NULL)
                launchMenu(m->parent);
            else launchMenu(m);
          }

         c= c - '1';
         if ((0 <= i)&&(i<m->nbItems)){
              switch(m->items[i].label){
                    case Act: 
                      return m->items[i].action.f();
                    break;
                    case SM:
                     return launchMenu(m->items[i].submenu);
                     break; 
                 }

          }
        printf("incorrect choice '%c'\n" , c);
        launchMenu(m);
}  



int main(){

    return EXIT_SUCCESS;
}