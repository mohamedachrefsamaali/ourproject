#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

typedef struct Date{
int jour;
int mois;
int annee;
} date;
//struct liste
typedef struct infoelecteur{
int CIN;
int Nempreinte;
int Ntelephone;
char nom[30];
char prenom[30];
int municipalite;
int role;
int genre;
 date d;
}electeur;
//les fonctions

int ajouterListe(char * filename, electeur L);
int modifierListe( char * filename,int CIN,electeur nouvL );
int supprimerListe(int CIN, char * filename);
electeur chercher(char * filename, int CIN);


#endif // FUNCTION_H_INCLUDE
