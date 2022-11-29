#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
typedef struct
{
int jour;
int mois;
int annee;
}date;
typedef struct
{
char id[20];
char nombres_habitants[20];
int municipalite;
char NC [20];
date d;
}Election;
typedef struct infoelecteur{
char CIN[8];
char motdepasse[10];
char Ntelephone[8];
char nom[30];
char prenom[30];
date d;
int municipalite;
int role;
int genre;
int vote;
int num_bv;
}electeur;

int ajouter(char *filename , Election E );
int modifier(char id[], char *filename, Election nouv);
int supprimer(char * filename, char id[]);
Election chercher(char * filename, char id[]);
float TPE(char *filname);
void TPHF(char *filename,float *femme,float *homme);
int nombre_electeur(char *filename,int id);


#endif // ELECTION_H_INCLUDED

