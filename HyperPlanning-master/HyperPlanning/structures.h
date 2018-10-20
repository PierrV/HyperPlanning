#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum e_sexe {H,F};
enum e_privilege {adm, resp, form, stag};
enum e_jour {lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche};
enum e_tseance {TD, TP, Amphi, DS};
int num_groupe;
int num_matricule;

typedef struct s_matricule{
    char* annee;
    int ordre;
} Matricule;

typedef struct s_login{
    char* identifiant;
    char* mdp;
    enum e_privilege privilege;
} Login;

typedef struct s_stagiaire {
    char* matricule;
    Login login;
    char* nom;
    char* prenom;
    char* d_naissance; // a modifier en date si possible
    enum e_sexe sexe;
    char* d_inscription; //a modifier en date si possible
    int num_rue;
    char* nom_rue;
    char* code_postal;
    char* ville;
    char* tel_domicile;
    char* tel_mobile;
} Stagiaire;

typedef struct s_formateur {
    Login login;
    char* nom;
    char* prenom;
    char* date_naissance; // a modifier en date si possible
    enum e_sexe sexe;
    char* tel_mobile;
} Formateur;

typedef struct s_matiere{
    char* nom;
    Formateur responsable;
    Formateur* formateurs;
    int volume_h;
} Matiere;

typedef struct s_groupe{
    int num;
    Stagiaire* stg;
    Matiere* matieres;
    int nb_stg;
} Groupe;

typedef struct s_date{
    enum e_jour jour;
    int semaine;
    int heure;
} Date;

typedef struct s_seance{
    Groupe groupe;
    Matiere matiere;
    Formateur formateur;
    Date date;
    enum e_tseance type;
} Seance;

int initGrp(Groupe*, int*);
int destrGrp(Groupe *);
int initStg(Stagiaire*, Groupe*, int);
int majNom(Stagiaire*);
int majPrenom(Stagiaire*);
int majSexe(Stagiaire*);
int majNaissance(Stagiaire*);
int majInscription(Stagiaire*);
int majNumRue(Stagiaire*);
int majNomRue(Stagiaire*);
int majCP(Stagiaire*);
int majVille(Stagiaire*);
int majTelDom(Stagiaire*);
int majTelMob(Stagiaire*);
int addToGrp(Stagiaire*, Groupe*, int);
int destrStg(Stagiaire *);
int initForm(Formateur*);
int destrForm(Formateur*);

Stagiaire accesStg(Login, Groupe*, int);
Formateur accesForm(Login, Formateur*, int);
int compareLog(Login, Login);

#endif // STRUCTURES_H_INCLUDED
