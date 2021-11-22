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
int tableindex = 0;

    int main(){
        int choise,nbajout,choixtri, choixquit;
    char cinre[10], cin[10];
    client cl[1000];


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
  case 1:Addcompte (cl,1);
  goto Menu;
case 2:
    printf("nombre de client a ajouter:");
    scanf("%d",nbajout);
    Addcompte(cl,nbajout);
    goto Menu;
    break;

    break;


default:
    break;
}



return 0;

    }
void Addcompte(client cl[],int n){
    for(int i=0;i<n;i++){
        printf("Entrer votre cin: ");
        scanf("%s", &cl[i].cin);
        printf("\nEntrer votre nom: ");
        scanf("%s", &cl[i].nom);
        printf("\nEntrer votre prenom: ");
        scanf("%s", &cl[i].prenom);
        printf("\nEntrer votre montant: ");
        scanf("%ld", &cl[i].montant);

        printf("\n \n \n *********\n \n");

        tableindex++;
    }
    }

