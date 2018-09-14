#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum e_sexe {H,F};

typedef struct s_matricule{
    int annee;
    int ordre;
} Matricule;

typedef struct s_stagiaire {
    Matricule matricule;
    char* nom;
    char* prenom;
    struct tm d_naissance;
    enum e_sexe sexe;
    struct tm d_inscription;
    int num_rue;
    char* nom_rue;
    char* code_postal;
    char* Ville;
    char* tel_domicile;
    char* tel_mobile;
    int* groupe;
} Stagiaire;

typedef struct employe{
    char* identifiant;
} Employe;

typedef struct s_login{
    char* identifiant;
    char* mdp;
    enum e_privilege privilege;
} Login;

typedef struct s_groupe_stagiaire{
    char* nom;
    int* stagiaires;
} Groupe;

typedef struct s_matiere{
    char* nom;
    int volume_h;

} Matiere;

typedef struct s_seance{
    char* nom_groupe;
    char* matiere;
    char* formateur;
    struct tm jour;
} Seance;

