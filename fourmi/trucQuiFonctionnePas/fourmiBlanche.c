# include <stdio.h> 
# include <stdlib.h> 

#define KRED "\x1b[31m"
#define KNORM "\x1b[0m"
//what we want:
//on a un damier
//        ligne0 0101010101
//        ligne1 1010101010
//        ligne2 0101010101

//Une fourmi est a la ligne 0 premier case
//    Si la fourmi est sur une case noire, elle tourne de 90° vers la gauche, change la couleur de la case en blanc et avance d'une case.
//    Si la fourmi est sur une case blanche, elle tourne de 90° vers la droite, change la couleur de la case en noir et avance d'une case.

void affiche(int** tab,int fourmi_x, int fourmi_y,int x,int y){
    for(int l=0;l<x;l++){
        for(int c=0;c<y;c++){
            if ((l==fourmi_x)&&(c==fourmi_y)) {
                printf("%s%d%s",KRED,tab[l][c],KNORM);
            } else {
                printf("%d",tab[l][c]);
            }
       }
       printf("\n");
    }
}


void createTab(int** tab, int x,int y ){
    int i,j ;
    int nc ;    // numerocase
    for (i=0; i<x;i++) {
        for (j=0; j<y;j++) {
            
           
                tab[i][j]=1 ;
          
            }
        }
    }


/*
void affiche_damier(int dimensionTab,int *ligne){
    for (int i=0; i>dimensionTab;i++){
        printf("%s",ligne[i]);
    }
    printf("\n");
}
*/
void bouge(int *fourmi_x,int *fourmi_y, int *orientation, int tab_x, int tab_y){
    if(*orientation==0){
        *fourmi_y=*fourmi_y-1;
        if (*fourmi_y==-1){
            *fourmi_y=tab_y-1;
        }
   }
    if(*orientation==1){
        *fourmi_x=*fourmi_x+1;
        if (*fourmi_x==tab_x+1){
            *fourmi_y=1;
        }
    }
    if(*orientation==2){
        *fourmi_y=*fourmi_y+1;
        if(*fourmi_y==tab_y+1){
            *fourmi_y=1;
        }

    }
    if(*orientation==3){
        *fourmi_x=*fourmi_x-1;
        if(*fourmi_x==-1){
            *fourmi_x==tab_x-1;
        }
    }
 //   return fourmi_x,fourmi_y;
}

/*
int eval(int x, int y,int tab){


    int val=tab[y][x];
    return val;


}
*/
void  switch_case(int** tab,int *fourmi_x, int *fourmi_y,int *orientation, int tab_x, int tab_y){
    
    //La fourmi est sur une case 1 
    if (tab[*fourmi_x][*fourmi_y]==1){
        if (*orientation==-1){
            *orientation=3;
            tab[*fourmi_x][*fourmi_y]=0;
        }
        else{
        *orientation=*orientation-1;
        tab[*fourmi_x][*fourmi_y]=0;
        }
        bouge( fourmi_x, fourmi_y, orientation, tab_x, tab_y);
    }


    
    //La fourmi est sur une case 0 
    if (tab[*fourmi_x][*fourmi_y]==0){
        if (*orientation==4){
            *orientation=0;
        }
        else{
            *orientation=*orientation+1;
        }
        tab[*fourmi_x][*fourmi_y]=1;
        bouge( fourmi_x, fourmi_y, orientation, tab_x, tab_y);

    }
}
//on fera l'inverse 


void main(){
    
    int fourmi_x ;
    int fourmi_y ;
    int orientation ;         // On defini 0->nord 1-> est 2->sud 3->ouest
    int tab_x ;               // Taille en X du tableau
    int tab_y ;               // Taille en Y du tableau
    int i;
    int** damier ;
    int a;
    fourmi_x = 5 ;
    fourmi_y = 5 ;
    tab_x = 50 ;
    tab_y = 50 ;
    orientation = 0;

    damier = malloc( tab_x * sizeof(int*) ) ;
    for (i=0; i<tab_x;i++ )
        damier[i] = malloc ( tab_y * sizeof(int) ) ;

    createTab(damier,tab_x,tab_y);
    affiche(damier, fourmi_x, fourmi_y, tab_x, tab_y) ;
    for (a=0;a<50;a++){
        switch_case(damier, &fourmi_x, &fourmi_y, &orientation, tab_x, tab_y); 
        printf("\n"); 
        affiche(damier,fourmi_x,fourmi_y, tab_x, tab_y) ;
    }
/*    affiche(tab,10,10);
    printf("\n");
    for (int i=0; i<5; i++){
        mouvement(fourmi_x, fourmi_y, orientation,tab);
        affiche(tab,10,10);
        printf("\n");
    }
*/
    for (i=0; i<tab_x;i++)
        free(damier[i]) ;
    free(damier) ;


}
