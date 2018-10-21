#include "structures.h"



int main()
{
    num_groupe=0; //a redéfinir à la lecture du fichier pour que ce soit égale au num de groupe max
    num_matricule=0; //a redéfinir à la lecture du fichier pour que ce soit égale au num de matricule max
    int nb_g=0,nb_f=0,nb_m=0; //a redefinir a la lecture du fichier pour que cela corresponde au nombre de matiere, groupe, formateur existant.
    char rep;
    int acces;
    Formateur* f=malloc(sizeof(Formateur)*30);
    if (f==NULL)
        return -1;
    Groupe* g=malloc(sizeof(Groupe)*3);
    if (g==NULL)
        return -1;
    Matiere* m=malloc(sizeof(Matiere)*20);
    if (g==NULL)
        return -1;
    Login

    do{
        printf("Selectionnez votre acces :\ns : Stagiaire\nf : Formateur\n");
        fflush(stdin);
        scanf("%c",&rep);
    }while(rep!='s' ||  rep!='f');

    if(rep==s)
        acces=accesStg()

    printf("Bienvenue sur l'application")
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

