#include "structures.h"



int main()
{
    num_groupe=0; //a redéfinir à la lecture du fichier pour que ce soit égale au num de groupe max
    num_matricule=0; //a redéfinir à la lecture du fichier pour que ce soit égale au num de matricule max
    int nb_g=0,nb_f=0,nb_m=0; //a redefinir a la lecture du fichier pour que cela corresponde au nombre de matiere, groupe, formateur existant.
    char rep;
    int acces;
    Formateur fa;
    Groupe ga;
    Formateur* f=malloc(sizeof(Formateur)*30);
    if (f==NULL)
        return -1;
    Groupe* g=malloc(sizeof(Groupe)*3);
    if (g==NULL)
        return -1;
    Matiere* m=malloc(sizeof(Matiere)*20);
    if (g==NULL)
        return -1;
    Login l;
    l.identifiant=malloc(sizeof(char)*9);
    if(l.identifiant==NULL)
        return -1;
    l.mdp=malloc(sizeof(char)*20);
    if(l.mdp==NULL)
        return -1;

    ///TEST
    f[0].login.identifiant=malloc(sizeof(char)*9);
    f[0].login.identifiant="adm";
    f[0].login.mdp=malloc(sizeof(char)*5);
    f[0].login.mdp="adm";
    f[0].login.privilege=adm;
    nb_f++;
    g[0].num=1;
    g[0].seances=malloc(sizeof(Seance)*3);
    g[0].seances[0].formateur=malloc(sizeof(char)*9);
    g[0].seances[0].formateur="Marcel";
    g[0].seances[0].n_matiere=malloc(sizeof(char)*9);
    g[0].seances[0].n_matiere="Maths";
    g[0].seances[0].type=TD;
    g[0].seances[0].date.annee=2018;
    g[0].seances[0].date.mois=10;
    g[0].seances[0].date.jour=24;
    g[0].seances[0].date.heure=9;
    g[0].nb_sean=1;
    nb_g++;
    ///TEST
    do{
        do{
            printf("Selectionnez votre acces :\ns : Stagiaire\nf : Formateur\n");
            fflush(stdin);
            scanf("%c",&rep);
        }while(rep!='s' &&  rep!='f');

        printf("Identifiant : ");
        fflush(stdin);
        scanf("%s",l.identifiant);
        printf("Mot de passe : ");
        fflush(stdin);
        scanf("%s",l.mdp);

        if(rep=='s')
            acces=accesStg(&ga, l, g, nb_g);
        else
            acces=accesForm(&fa, l, f, nb_f);

        if (acces==aucun)
            printf("Vous n'avez pas acces a l application.\n");
    }while(acces==aucun);
    printf("Bienvenue sur l'application");
    if(acces==stag){
        do{
            do{
                printf("Voulez vous voir votre planning mensuel ou votre planning hebdomadaire ?\nm : Mensuel\nh : Hebdomadaire\ne : Exit\n");
                fflush(stdin);
                scanf("%c",&rep);
            }while(rep!='m' && rep !='h' && rep!='e');
            if (rep=='h')
                planningH(ga);
            else if (rep=='m')
                planningM(ga);
        }while(rep!='e');
    }
    else if (acces==form){
        do{
            do{
                printf("Voulez vous voir votre planning mensuel ou votre planning hebdomadaire ?\nm : Mensuel\nh : Hebdomadaire\ns : Planning des Stagiaires\ne : Exit\n");
                fflush(stdin);
                scanf("%c",&rep);
            }while(rep!='m' && rep !='h' && rep!='e' && rep!='s');
            if (rep=='h')
                planningFH(fa);
            else if (rep=='m')
                planningFM(fa);
            else if (rep=='s'){
                do{
                    printf("Quel planning :\nm : Mensuel\nh : Hebdomadaire\ne : Exit\n");
                    fflush(stdin);
                    scanf("%c",&rep);
                }while(rep!='m' && rep !='h' && rep!='e');
                if (rep=='m')
                    planningSM(g, nb_g);
                else if (rep=='h')
                    planningSH(g, nb_g);
                rep='a';
            }
        }while(rep!='e');
    }
    else if (acces==resp){
        do{
            do{
                printf("Choisissez votre option :\nm : Voir le planning Mensuel\nh : Voir le planning Hebdomadaire\ns : Planning des Stagiaires\ng : Gestion du planning de sa matiere\ne : Exit\n");
                fflush(stdin);
                scanf("%c",&rep);
            }while(rep!='m' && rep !='h' && rep!='e' && rep!='g' && rep!='s');
            if (rep=='h')
                planningFH(fa);
            else if (rep=='m')
                planningFM(fa);
            else if (rep=='g')
                modifP(fa, g, m, nb_g, nb_m);
            else if (rep=='s'){
                do{
                    printf("Quel planning :\nm : Mensuel\nh : Hebdomadaire\ne : Exit\n");
                    fflush(stdin);
                    scanf("%c",&rep);
                }while(rep!='m' && rep !='h' && rep!='e');
                if (rep=='m')
                    planningSM(g, nb_g);
                else if (rep=='h')
                    planningSH(g, nb_g);
                rep='a';
            }
        }while(rep!='e');
    }
    else{
        do{
            do{
                printf("Choisissez votre option :\nm : Voir le planning Mensuel\nh : Voir le planning Hebdomadaire\ns : Planning des Stagiaires\ng : Gestion Formateurs / Stagiaires / Matieres / Planning\ne : Exit\n");
                fflush(stdin);
                scanf("%c",&rep);
            }while(rep!='m' && rep !='h' && rep!='e' && rep!='g' && rep!='s');
            if (rep=='h')
                planningFH(fa);
            else if (rep=='m')
                planningFM(fa);
            else if (rep=='s'){
                do{
                    printf("Quel planning :\nm : Mensuel\nh : Hebdomadaire\ne : Exit\n");
                    fflush(stdin);
                    scanf("%c",&rep);
                }while(rep!='m' && rep !='h' && rep!='e');
                if (rep=='m')
                    planningSM(g, nb_g);
                else if (rep=='h')
                    planningSH(g, nb_g);
                rep='a';
            }
            else if (rep=='g'){
                do{
                    do{
                        printf("Choisissez l objet de la gestion :\nf : Formateurs\ng : Groupes\nm : Matieres\np : Planning\ns : Stagiaires\ne : Exit\n");
                        fflush(stdin);
                        scanf("%c",&rep);
                    }while(rep!='f' && rep !='g' && rep!='m' && rep!='p' && rep!='s' && rep!='e');
                    if(rep=='f')
                        modifF(f, nb_f);
                    else if (rep=='g')
                        modifG(g, nb_g);
                    else if (rep=='m')
                        modifM(m, nb_m);
                    else if (rep=='p')
                        modifP(fa, g, m, nb_g, nb_m);
                    else if (rep=='s')
                        modifS(g, nb_g);
                }while(rep!='e');
                rep='a';
            }
        }while(rep!='e');
    }
    deconnexion();
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

