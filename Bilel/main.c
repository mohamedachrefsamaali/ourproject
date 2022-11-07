#include <stdio.h>
#include <string.h>
#include "function.h"

int main()
{
     electeur L1={12,11,1,"bilel","yousfi",1,1,2,3,1,2};
     electeur L3={10,10,10,"noursine","nassim",10,10,10,10,10,10};

     int x ;




   x=ajouterListe("electeur.txt",L3);

    if(x==1)
        printf("\najout de Liste avec succees!!!!!!!!!");
    else printf("\nechec ajout");

 /*x=modifierListe("electeur.txt",12,L3);
    if(x==1)
        printf("\nModification de point avec succes");
    else printf("\nechec Modification");*/
 /*x=supprimer("electeur.txt",10);
    if(x==1)
        printf("\nSuppression de point avec succes");
    else printf("\nechec Suppression");*/
 L3=chercher("electeur.txt",10);
    if(L3.CIN==-1)
    {
        printf("introuvable");
    }else if (L3.CIN!=-1)
     {
         printf("existe!!!\n");
    }
    return 0;
}
