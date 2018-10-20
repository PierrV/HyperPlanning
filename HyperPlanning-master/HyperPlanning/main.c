#include "structures.h"



int main()
{
    num_groupe=0; //a redéfinir à la lecture du fichier pour que ce soit égale au num de groupe max
    num_matricule=0; //a redéfinir à la lecture du fichier pour que ce soit égale au num de matricule max
    int nb_g,nb_f;
    Groupe g1,g2;
    Stagiaire s1;
    if (initGrp(&g1)==-1)
        return -1;
    if (initGrp(&g2)==-1)
        return -1;
    if (initStg(&s1)==-1)
        return -1;

printf("g1 %d\n",g1.num);
printf("g2 %d\n",g2.num);

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

