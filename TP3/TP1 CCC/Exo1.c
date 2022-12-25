#include <stdio.h>
#include <stdlib.h>

class Noeud {
     Noeud filsg;
     Noeud filsd;
     Noeud pere;
     String car;
     int freq;
    this.freq = n1.freq + n2.freq;
}

Noeud(Noeud n1,Noeud n2){
    this.filsg = n1;
    this.filsd = n2;
    this.pere = null;
    n1.pere = this;
    n2.pere = this;
}

Noeud min(Noeud [] liste){
    //gérer le cas où la liste.length = 0
    Noeud m = liste[0];
    for(int i=1; i < liste.length; i++){
        if(m.freq > liste[i].freq) m = liste[i];
    }
    return m;
}

class Huffman{
    Noeud racine;
    Noeud[] feuilles;
    Huffman(String[] car, int [] tabfreq);
    String codage(String car);
    String decodage(String code);
}

Noeud [] supp(Noeud n, Noeud [] liste){
    // créer une nouvelle liste = liste
    Noeud [] noliste = new Noeud [liste.length -1];
    int cpt = 0;
    for(int i=0; i< liste.length; i++){
        if(liste[i] != n){
            noliste[c]= liste [i];
            c++;
        }
    }
    return noliste;
}
/*
    tant que liste noeuds courante != singleton
    n1 = min (liste)
    liste = supp(n1, liste)
    n2 = min (liste)
    liste = supp (n2, liste)
*/

Noeud [] insertion(Noeud n, Noeud [] liste){
    Noeud [] noliste = new Noeud[liste.length -1]
    for(int i=0; i <liste.length; i++){
        noliste[i]= liste[i];
        noliste [liste.length] = n;
    }
    return noliste;
}

/*
    huffman(String[] n1, int [] freq)
    //création de la listedes feuilles
    1. longueur = car.length(car freq2,.length)
    2. création Noeud[Longueur]
    3. NOeud[i] créer un noeud 
                --> Noeud (String, int)


    while(liste.length > 1){
        n1 = min(liste)
        lsite = supp (n1, liste)
        n2 = min (liste)
        lsite = supp(n2, liste)
        Noeud n = new Noeud(n1, n2)
        liste = insertion(n, liste)
    }
    liste.racine = liste[0]
*/


int main(){

}