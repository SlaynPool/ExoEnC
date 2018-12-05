#include <stdio.h>
//int tab [100];
//int a = 1;
//tab[1]= a;
//int tab_temp[100];
void affiche(int tab[]){
    int i;
    i=0;
//    printf("%d\n",i);
    while(tab[i]!=0){
        
        printf("%d ",tab[i]);
        i++;
    }
    printf("\n");
 
}
void cpy(int origine[],int dest[]){
    int i;
    i=0;
    while (origine[i]!=0){
        dest[i]=origine[i];
        i++;
    }
}

void pascal(int nb_iteration,int tab[],int tab_new[]){
    int i;
    int y;
    y=0;
    for (i=0; i<nb_iteration;i++){
       y=0;
        while(tab[y]!=0){
            tab_new[0]=1;
            tab_new[y+1]=tab[y]+tab[y+1];
            y++;
        }
    tab_new[y]=1;
    affiche(tab_new);
    cpy(tab_new,tab);
}

}




int main(){
    int tab[1000];
    int tab_temp[1000];
    tab[0]=1;
    tab_temp[0]=1;
    printf("%d\n",tab[0]);
    pascal(20,tab,tab_temp);
//    printf("lo");
    return 0;
}
