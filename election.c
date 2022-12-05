#include"election.h"
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
enum
{
	
	EID,
	ENOMBRES_HABITANTS,
	ENOMBRES_COSEILLE,
	EMUNICIPALITE,
	EJOUR,
	EMOIS,
	EANNEE,
	COLUMNS,
};
void ajouter_Election(Election E )
{
   FILE * f=fopen("election.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s\n",E.id,E.nombres_habitants,E.municipalite,E.NC,E.d.jour,E.d.mois,E.d.annee);
        fclose(f);
      
    }
   return;
}
int modifier(char id[], Election nouv)
{
    int tr=0;
    Election E;
    FILE * f=fopen("election.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s\n",E.id,E.nombres_habitants,E.municipalite,E.NC,E.d.jour,E.d.mois,E.d.annee)!=EOF)
        {
            if(strcmp( E.id , id )==0)
            {
                fprintf(f2,"%s %s %s %s %s %s %s\n",nouv.id,nouv.nombres_habitants,nouv.municipalite,nouv.NC,nouv.d.jour,nouv.d.mois,nouv.d.annee);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s %s\n",E.id,E.nombres_habitants,E.municipalite,E.NC,E.d.jour,E.d.mois,E.d.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove("election.txt");
    rename("nouv.txt", "election.txt");
    return tr;

}
int supprimer_elec(char id[20])
{
    int tr=0;
    Election E;
    FILE * f=fopen("election.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s\n",E.id,E.nombres_habitants,E.municipalite,E.NC,E.d.jour,E.d.mois,E.d.annee)!=EOF)
        {
         if(strcmp( E.id , id)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s %s %s\n",E.id,E.nombres_habitants,E.municipalite,E.NC,E.d.jour,E.d.mois,E.d.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove("election.txt");
    rename("nouv.txt", "election.txt");
    return tr;
}
Election chercher(char * filename, char id[])
{
    Election E;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %s %s %s\n",E.id,E.nombres_habitants,E.municipalite,E.NC,E.d.jour,E.d.mois,E.d.annee)!=EOF)
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
void afficher_Election(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char idelc[20];
	char nb_habitants[30];
	char municipalite[30];
	char nombre_conseille[20];
	char jour[30];
	char mois[30];
	char annee[30];
	
	store=NULL;
	FILE* f=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{



	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text", EID , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Nombre Habitants", renderer, "text", ENOMBRES_HABITANTS , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Municipalite", renderer, "text", EMUNICIPALITE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Nombre_Conseille", renderer, "text", ENOMBRES_COSEILLE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", EJOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", EMOIS , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", EANNEE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("election.txt","r");
	if(f==NULL)
	{return;
	}	
	else 
	{
		f=fopen("election.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s\n",idelc,nb_habitants,municipalite,nombre_conseille,jour,mois,annee)!=EOF)
		{	gtk_list_store_append(store, &iter);
			gtk_list_store_set(store, &iter, EID, idelc, ENOMBRES_HABITANTS, nb_habitants,EMUNICIPALITE,municipalite, ENOMBRES_COSEILLE, nombre_conseille,EJOUR, jour,EMOIS,mois,EANNEE,annee, -1);
		}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
int test_id(char id[])
{

Election E;
    int t=0;
    FILE * f=fopen("election.txt", "r");
    if(f!=NULL)
    {
        while(t==0 &&  fscanf(f,"%s %s %s %s %s %s %s\n",E.id,E.nombres_habitants,E.municipalite,E.NC,E.d.jour,E.d.mois,E.d.annee)!=EOF)
        {
          if(strcmp( E.id , id )==0)
           {     t=1;}
	else 
 	{t=0;}
        }
	
    }
    fclose(f);

       
    return t;

}

/*float TPE(char *filename)
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
*/
