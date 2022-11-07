#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "function.h"
//function pour ajouter electeur
int ajouterListe(char * filename, electeur L)
{

    FILE * f=fopen(filename,"a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %s %s %d %d %d %d %d %d\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role);
        fclose(f);
        return 1;
    }
    else
        return 0;
}
//function pour modifier electeur
int modifierListe( char * filename,int CIN,electeur nouvL )
{
    int tr=0;
    electeur L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d \n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role)!=EOF)
        {
            if(L.CIN== CIN)
            {
                fprintf(f2,"%d %d %d %s %s %d %d %d %d %d %d\n",nouvL.CIN,nouvL.Nempreinte,nouvL.Ntelephone,nouvL.nom,nouvL.prenom,nouvL.d.jour,nouvL.d.mois,nouvL.d.annee,nouvL.municipalite,nouvL.genre,nouvL.role);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %s %s %d %d %d %d %d %d\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt",filename);
    return tr;

}

//function pour supprimer liste
int supprimer(char * filename, int CIN)
{
    int tr=0;
    electeur L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d \n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role)!=EOF)
        {
            if(L.CIN== CIN)
                tr=1;
            else
                fprintf(f2,"%d %d %d %s %s %d %d %d %d %d %d\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
//function pour chercher liste
electeur chercher(char * filename, int CIN)
{
    electeur L;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role)!=EOF)
        {
            if(L.CIN== CIN)
                tr=1;

        }
    }
    fclose(f);
    if(tr==0)
        L.CIN=-1;
    return L;

}
