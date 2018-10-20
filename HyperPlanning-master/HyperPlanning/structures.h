#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum e_sexe {H,F};
enum e_privilege {adm, resp, form, stag};

typedef struct s_groupe{
    static int num;
    Stagiaire* stagiaires;
    Matiere* matieres;
} Groupe;

typedef struct s_seance{
    Groupe groupe;
    Matiere matiere;
    Formateur formateur;
    Date date;
    enum typeseance type;
} Seance;

typedef struct s_matiere{
    char* nom;
    Formateur responsable;
    Formateur* formateurs;
    int volume_h;
} Matiere;

typedef struct s_matricule{
    char* annee;
    static int ordre;
} Matricule;

typedef struct s_stagiaire {
    Matricule matricule;
    Login login;
    char* nom;
    char* prenom;
    char* date_naissance; // a modifier en date si possible
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
} Formateur

typedef struct s_login{
    char* identifiant;
    char* mdp;
    enum e_privilege privilege;
} Login;








#endif // STRUCTURES_H_INCLUDED
