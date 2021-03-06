#include <stdio.h>
#include <stdlib.h>

typedef struct client client;
    struct client{
        char cin[10];
        char nom[100];
        char prenom[100];
        long int montant;
    };

    int tableindex=0;

int main()
{
    int choise,nbajout,choixtri, choixquit;
    char cinre[10], cin[10];
    client cl[1000];

    Menu:
    printf("\n\n\n");
    printf("\t\t\t*****\n");
    printf("\t\t\t** Bienvenue sur gestion du bank **\n");
    printf("\t\t\t*****\n");
    printf("\t\t\t           FATIMZAHRA SAHI \n");
    printf("\t\t\t*****\n");
    printf("\t\t\t\t\tMENU\n\n\n");
    printf("\t\t\t\ 1-Ajouter un compte  \n");
    printf("\t\t\t\ 2-Ajouter plusieurs compte \n");
    printf("\t\t\t\ 3-Chercher un compte \n");
    printf("\t\t\t\ 4-Trier por ordre \n");
    printf("\t\t\t\ 5-Fidelisation \n");
    printf("\t\t\t\ 6-Quitter l'application \n");
    printf("\t\t\t*****\n\n\n");


    printf("votre choix: ");
    scanf("%d", &choise);


    switch(choise)
    {
    case 1:
        addcompte(cl,1);

        goto Menu;
        break;
    case 2:
        printf("Nombre de client a ajouter: ");
        scanf("%d", &nbajout);

        addcompte(cl,nbajout);
        goto Menu;
        break;
    case 3:
        printf("Entrer le CIN de client: ");
        scanf("%s", &cinre);

        cherchcl(cl,tableindex,cinre);

        goto Menu;
        break;
    case 4: 
        printf("afficher les elements du tableau");
        showcl(cl,tableindex);
        printf("par ordre decroissant [1]| par ordre croissant [2]\n");
        switch (choixtri)
        {
        case 1:
        tridec(cl,tableindex);
        printf("\n\n");
        printf("afficher les elements du tableau en ordre decroissant");
        showcl(cl,tableindex);
            break;
        case 2:
        tric(cl,tableindex);
        printf("\n\n");
        printf("afficher les elements du tableau en ordre croissant");
        showcl(cl,tableindex);
            break;
        default:
            break;
        }
        goto Menu;
        break;
        case 5:
        printf("Fedilisation | ajouter un 1.3% a les 3 premiers comptes \n\n");
        printf("list avant fedilisation \n\n");
        showcl(cl,tableindex);
        goto Menu;
        break;
        case 6:
        exit(0);
        

    



   
    }

    return 0;
}

void addcompte(client cl[], int n){

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

void cherchcl(client cl[], int tbidx,char CIN[10]){

    int choix2 = 0,a;
  

    for(int i=0; i<tbidx;i++)
    {  int value=0;
    value =strcmp(cl[i].cin,CIN);
        if(value==0)
        {
            long int ret=0;
            long int dep=0;

            printf("\n Le client avec le CIN %s est:", CIN);
            printf("\n CIN: %s | Nom: %s | Prenom: %s | montant: %ld \n \n", cl[i].cin,cl[i].nom,cl[i].prenom,cl[i].montant);
            Menu2:
            printf("\n\n");
            printf("***Operations***");
            printf("\n \n Retrait [1] \t\t\ Depot [2] \t\t\ Retourner au menu principal [3]\n");

            scanf("%d", &choix2);

            switch(choix2)
            {
            case 1:

                Retrait:
                printf("Donner un montant \n NB:le retrait doit etre inferieure de %ld: ", cl[i].montant);
                scanf("%ld", &ret);
                if(ret < cl[i].montant){
                    retrait(cl, i, ret);
                }
                else
                {
                    printf("le retrait doit etre inferieure de %ld", cl[i].montant);
                    goto Menu2;
                }
                break;
            case 2:
                printf("Donner un montant: \n");
                scanf("%ld", &dep);
                depot(cl, i, dep);
                break;
            case 3:
                break;
            default:
                printf("choix incorrect!!!! \n");
                goto Menu2;
                break;
            }
            break;
        }
        else{
            printf("Not found!!!");
        }
    }
}

void retrait(client cl[], int index, long int retrait){

    cl[index].montant -= retrait;

}

void depot(client cl[], int index, long int depot){

    cl[index].montant += depot;

}
void showcl(client cl[],int taille){
    for(int i =0;i<taille;i++){
        printf("\n CIN :%s|Nom:%s|Prenom :%s|Montant:%ld \n\n",cl[i].cin,cl[i].nom,cl[i].prenom,cl[i].montant);

    }

}
void tridec(client cl[],int size){
    int i ,j ;
    client tmp[1];
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            /*pour un ordre decroissant */
            if(cl[i].montant<cl[j+1].montant){
             tmp[0]=cl[j];
             cl[j]=cl[j+1];
             cl[j+1]=tmp[0];
            }
        }
    }
}
void tric(client cl[],int size){
    int i ,j ;
    client tmp[1];
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            /*pour un ordre croissant */
            if(cl[i].montant>cl[j+1].montant){
             tmp[0]=cl[j];
             cl[j]=cl[j+1];
             cl[j+1]=tmp[0];
            }
        }
    }

}
void fedilisation(client cl[],int SIZE){
    int i,j;
    client tmp[1];
    tridec(cl,SIZE);
    for(int k=0;k<3;k++){
        cl[k].montant+=cl[k].montant*(1.3/100);
    }
    printf("list apres fidelisation\n\n");
    showcl(cl,SIZE);
}