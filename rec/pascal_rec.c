#include <stdio.h>

//pour calculer la Nieme ligne,
//il faut connaitre la n-1 ligne.
//pour connaitre list[i], 

//1
//11
//121
//1331
//14641

void format(int list[]){
    for(int i=0;i<=100;i++){
        list[i]=0;

    }
}

void affiche(int tab[]){
    int i;
    i=0;
    while (tab[i]!=0){
       printf ("%d ",tab[i]);
       i++;
    }
   printf ("\n"); 
}
///////CORE_FUNCTION/////////////////////
int *pascal_rec(int iteration, int list[],int listn1[]){
    
    if(iteration==1){
        listn1[0]=1;
	listn1[1]=1;
        return listn1;
    }
    else{
    	 int i;
    	 listn1=pascal_rec(iteration-1,listn1, list);
    	 //format(list);
   	 //remplir la liste
   	 //Dans le cas i= 0 dans la boucle on fais listn1[-1] donc pas bon
	 //format(list);
    	 list[0]=listn1[0]=1;
   	 for (i=1; i<iteration;i++){
        	list[i]=listn1[i-1]+listn1[i];
    	 }
    	 //i++;
    	 list[i]=1;
    	 affiche(list);
    	 //affiche(listn1);
    	 //listn1
    	 i=0; 
    	 return list;
    }


}

///////CORE_FUNCTION//////////////////////



/*int pascal_rec(int n)
{   
   int list[100];
   list[1]=1;

    int i;
    i=9;
 //Cas elementaire
    if (n==1){
    return 1;
    }
    else{
       for (int a=0;a<i;a++){
       list[i]=pascal_rec(n-1);
       }
       affiche(list);
    }
}*/

int main(){
    int list[100];
    format(list);

    int listn1[100];
    format(listn1);
    printf("1\n1 1\n");
    pascal_rec(7,list, listn1);
    return 0;
 }
