#include "structures.c"

int main()
{
    Login* log;
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

    return 0;
}

int connexion(Login* login){
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

}

void initLog(){
        char* base = "[admin;1]"
        fd = fopen("log.txt", "w");
        if(fd == NULL){
            perror("ERROR : BDD comptes inaccessibles");
            return(-1);
        }
        r = fprintf((FILE*)fd, "%s", base);
        fclose(fd);
}
