#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define prl { printf("\n"); }

typedef struct {
    double x;
    double y;
}coord_t;

void print_coord(coord_t c){
    printf("(%lf,%lf)", c.x, c.y);
}

coord_t coordinate(double x, double y){
    coord_t t;
    t.x = x;
    t.y = y;
    return t;
}

coord_t inv_translate_point(coord_t p, coord_t v){
   return coordinate(p.x - v.x, p.y - v.y);
}

coord_t inv_rotate_point(coord_t p, double t){
    return coordinate((p.x * cos(-t) - p.y * sin(-t)), (p.x * sin(-t) + p.y * cos(-t)));
}

//Fugures

typedef enum {
    CERCLE;
    RECTANGLE;
    LINE;
}shape_t;

typedef struct {
    double rayon;
}circle_t;

struct rectangle_s {
    double demie_largeur;
    double demie_hauteur;
};
typedef struct rectangle_s rectangle_t;

typedef struct {
    double demie_longueur;
}line_t;

typedef char color_t;

typedef struct {
    color_t color;
    double centre_de_gravite;
    double angle_de_rotation;
    double forme;

}figure_t;



int main(){
    //premier exo1
    /*coord_t pt = coordinate(10,20);
    print_coord(pt); prl;
    print_coord(inv_translate_point(pt,pt)); prl;
    print_coord(inv_rotate_point(pt,M_PI_2)); prl;
    print_coord(inv_rotate_point(pt,-M_PI_4)); prl;
    return EXIT_SUCCESS;*/
    //{{=======End======}

    //Deuxième exo2

    figure_t f;
    color_t c;
 
  f = rectangle(10,7);
  f = translate(f, 10, 8);
  f = rotate(f, 45 * M_PI / 180);
 
  c = intersect(coordinate(5,5),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(10,10),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(18,18),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
 
  f = circle(12);
  f = translate(f, 20, 13);
  f = color(f, 'O');
 
  c = intersect(coordinate(5,5),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(10,10),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(18,18),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
 
  f = line(20);
  f = translate(f, 18, 18);
  f = rotate(f, -60 * M_PI / 180);
  f = color(f, '*');
 
  c = intersect(coordinate(5,5),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(10,10),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
  c = intersect(coordinate(18,18),f,1);
  if (c) printf("Intersection with color %c\n",c); else printf("No intersection\n");
 
  return EXIT_SUCCESS;

}