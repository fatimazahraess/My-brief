#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
typedef struct client client ;
struct client{
    char cin [10];
    char nom [100];
    char prenom[10];
    double montant ;
    
};
int tabindex = 0;
void Addcompte( ){
         client cl;
        printf("enter votre cin:");
        scanf("%s",cl.cin);
        printf("enter votre nom:");
        scanf("%s",cl.nom);
        printf("enter votre prenom:");
        scanf("%s",cl.prenom);
        printf("enter votre montant:");
        scanf("%lf",&cl.montant);
        
    };
    int main(){
        int choise,client;

    //menu//
Menu:
printf("\t\t\t************************\n");
printf("\t\t\t******  Bienvenue ******\n");
printf("\t\t\t******Menu******\n");
printf("\t\t\t******1:Ajouter un compte\n");
printf("\t\t\t******2:Ajouter plusieurs compte\n");
printf("\t\t\t******3:Chercher un compte\n");
printf("\t\t\t******4:Trier !!per ordre\n");
printf("\t\t\t******5:Fidelisation\n");
printf("\t\t\t******6:Quitter le programme\n");
printf("\t\t\t************************\n");


printf("enter votre choix :");
scanf("%d",&choise);

switch (choise)
{
case 1:Addcompte ();
  goto Menu;
    break;
  

default:
    break;
}



return 0;

    }




