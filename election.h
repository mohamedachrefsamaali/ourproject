#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct
{
char jour[20];
char mois[20];
char annee[20];
}date;
typedef struct
{
char id[20];
char nombres_habitants[20];
char municipalite[20];
char NC[20];
date d;
}Election;
int test_id(char id[]);
void afficher_Election(GtkWidget *liste);
void ajouter_Election(Election E );
int modifier(char id[],Election nouv);
int supprimer_elec(char id[]);
Election chercher(char * filename, char id[]);
float TPE(char *filname);
void TPHF(char *filename,float *femme,float *homme);
int nombre_electeur(char *filename,int id);


#endif // ELECTION_H_INCLUDED

