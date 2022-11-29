#include"election.h"
#include <string.h>
int ajouter(char *filename , Election E )
{
   FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %s %d %d %d\n",E.id,E.nombres_habitants,E.municipalite,E.NC,E.d.jour,E.d.mois,E.d.annee);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier(char id[], char *filename, Election nouv)
{
    int tr=0;
    Election E;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d %d %d\n",E.id,E.nombres_habitants,&E.municipalite,E.NC,&E.d.jour,&E.d.mois,&E.d.annee)!=EOF)
        {
            if(strcmp( E.id , id )==0)
            {
                fprintf(f2,"%s %s %d %s %d %d %d\n",nouv.id,nouv.nombres_habitants,nouv.municipalite,nouv.NC,nouv.d.jour,nouv.d.mois,nouv.d.annee);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %s %d %d %d\n",E.id,E.nombres_habitants,E.municipalite,E.NC,E.d.jour,E.d.mois,E.d.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, char id[])
{
    int tr=0;
    Election E;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d %d %d\n",E.id,E.nombres_habitants,&E.municipalite,E.NC,&E.d.jour,&E.d.mois,&E.d.annee)!=EOF)
        {
         if(strcmp( E.id , id)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %d %s %d %d %d\n",E.id,E.nombres_habitants,E.municipalite,E.NC,E.d.jour,E.d.mois,E.d.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
Election chercher(char * filename, char id[])
{
    Election E;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %d %s %d %d %d\n",E.id,E.nombres_habitants,&E.municipalite,E.NC,&E.d.jour,&E.d.mois,&E.d.annee)!=EOF)
        {
          if(strcmp( E.id , id )==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(E.id,"-1");
    return E;

}
float TPE(char *filename)
{
 electeur E;

 float j=0;
 int i=0;
 float NP=0;
FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d %d %d\n",E.CIN,E.motdepasse,E.Ntelephone,E.nom,E.prenom,&E.d.jour,&E.d.mois,&E.d.annee,&E.municipalite,&E.role,&E.genre,&E.vote,&E.num_bv)!=EOF)
       {
           j=j+1;

           if(E.vote!=-1)
            i++;
       }

    }
    NP=(i/j)*100;
 fclose(f);
    return NP;
}
void TPHF(char *filename,float *femme,float *homme)
{
 electeur E;

 float j=0;
 int i=0;

FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d %d %d\n",E.CIN,E.motdepasse,E.Ntelephone,E.nom,E.prenom,&E.d.jour,&E.d.mois,&E.d.annee,&E.municipalite,&E.role,&E.genre,&E.vote,&E.num_bv)!=EOF)
       {
           j=j+1;

           if(E.genre==10)
            i++;
       }

    }

    *homme=(i/j)*100;
    *femme=((j-i)/j)*100;
      fclose(f);
    return;
}
int nombre_electeur(char *filename,int id)
{
    int i=0;
    electeur E;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d %d %d \n",E.CIN,E.motdepasse,E.Ntelephone,E.nom,E.prenom,&E.d.jour,&E.d.mois,&E.d.annee,&E.municipalite,&E.role,&E.genre,&E.vote,&E.num_bv)!=EOF)
       {
           if(E.num_bv==id)
            i++;
       }

    }
    fclose(f);
    return i;

}

