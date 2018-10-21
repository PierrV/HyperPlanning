#include "structures.h"



int main()
{
    num_groupe=0; //a redéfinir à la lecture du fichier pour que ce soit égale au num de groupe max
    num_matricule=0; //a redéfinir à la lecture du fichier pour que ce soit égale au num de matricule max
    int nb_g=0,nb_f=0; //a redefinir a la lecture du fichier pour que cela corresponde au nombre de matiere, groupe, formateur existant.
    Formateur* f=malloc(sizeof(Formateur)*30);
    if (f==NULL)
        return -1;
    Groupe* g=malloc(sizeof(Groupe)*3);
    if (g==NULL)
        return -1;
    //Stagiaire s1;
    if (initGrp(&g[0],&nb_g)==-1)
        return -1;
    if (initGrp(&g[1],&nb_g)==-1)
        return -1;

    printf("%d\n",g[0].num);
    printf("%d\n",g[0].nb_stg);

    if (initForm(&f[0],&nb_f)!=0)
        return -1;

    /*if (initStg(&s1,g,nb_g)==-1)
        return -1;*/
    printf("%s\n",f[0].nom);
    printf("%s\n",f[0].prenom);
    printf("%s\n",f[0].login.identifiant);
    printf("%s\n",f[0].login.mdp);

/*printf("%s\n",s1.prenom);
printf("%s\n",s1.nom);
printf("%s\n",s1.matricule);
printf("%s\n",s1.login.identifiant);
printf("%s\n",s1.login.mdp);
if (s1.sexe==H)
    printf("Homme\n");
if (s1.sexe==F)
    printf("Femme\n");
printf("%s\n",s1.d_naissance);
printf("%s\n",s1.d_inscription);
printf("%d\n",s1.num_rue);
printf("%s\n",s1.nom_rue);
printf("%s\n",s1.code_postal);
printf("%s\n",s1.ville);
printf("%s\n",s1.tel_domicile);
printf("%s\n",s1.tel_mobile);  */

 /*   Login* log;
    int droit;
    printf("Hello world!\n");
    printf("\n------- Connexion -------\n");
    printf("Login : ");
    scanf("%s", log->identifiant);
    printf("\n");

    droit = connexion(log);

    switch (droit){
    case 1 : printf("admin");
        break;
    default: break;
    }
*/
    return 0;
}

/*int connexion(Login* login){
    int fd = fopen("log.txt", "r");
    int r;
    char* string;
    char* regex = "["+login->identifiant+";[:digit:]]";
    if(fd == NULL){
        initLog();
        fd = fopen("log.txt", "r");
    }
    string = fscanf((FILE*)fd, "%s", string);
    r = strstr(string, regex);
    printf("%d",r);
    if (r != NULL){

    }

}*/

/*void initLog(){
        char* base = "[admin;1]"
        fd = fopen("log.txt", "w");
        if(fd == NULL){
            perror("ERROR : BDD comptes inaccessibles");
            return(-1);
        }
        r = fprintf((FILE*)fd, "%s", base);
        fclose(fd);
}*/

