#include "structures.h"

int initGrp(Groupe* g){
    g->num=++num_groupe;
    printf("%d\n",g->num);

    g->matieres=malloc(sizeof(Matiere)*10);
    if (g->matieres==NULL)
        return -1;

    g->stg=malloc(sizeof(Stagiaire)*30);
    if (g->stg==NULL)
        return -1;
    g->nb_stg=0;
    return 0;
}

int initStg(Stagiaire* s){
    char * tmp;
    s->matricule=malloc(sizeof(char)*9);
    if (s->matricule==NULL)
        return -1;

    tmp=malloc(sizeof(char)*5);
    if (tmp==NULL)
        return -1;
    sprintf(tmp,"%04d\0",++num_matricule);
    s->matricule[0]='2';
    s->matricule[1]='0';
    s->matricule[2]='1';
    s->matricule[3]='8';
    s->matricule[4]='\0';
    strncat(s->matricule,tmp,4);
    free(tmp);
    s->login.identifiant=s->matricule;
    s->login.mdp=malloc(sizeof(char)*20);
    if (s->login.mdp==NULL)
        return-1;
    s->login.mdp="Password123";

    s->nom=malloc(sizeof(char)*25);
    if (s->nom==NULL)
        return -1;
    if (majNom(&s)==-1)
        return -1;

    s->prenom=malloc(sizeof(char)*25);
    if (s->prenom==NULL)
        return -1;
    if (majPrenom(&s)==-1)
        return -1;

    if (majSexe==-1)
        return -1;

    s->code_postal=malloc(sizeof(char)*5);
    if (s->code_postal==NULL)
        return -1;
    if (majCP(&s)==-1)
        return -1;



    return 0;
}

int initForm(Formateur* f){

}

Stagiaire accesStg(Login l,Groupe* g, int nb_g){
    int i=0,j,co=0;
    while (co==0 && i<nb_g){
        j=0;
        while(co==0 && j<g[i].nb_stg){
            co=compareLog(l,g[i].stg[j].login);
            j++;
        }
        i++;
    }
    if(co!=0)
        return g[i].stg[j];
    //else
      //  return NULL;
}

Formateur accesForm(Login l,Formateur* f,int nb_f){
    int i=0,co=0;
    while (co==0 && i<nb_f){
        co=compareLog(l,f[i].login);
        i++;
    }
    if(co!=0)
        return f[i];
        //else ??
        //
}

int compareLog(Login l, Login lo){
    if (strcmp(l.identifiant,lo.identifiant)==0){
        if(strcmp(l.mdp,lo.mdp)==0)
            return 1;
        return 0;
    }
    return 0;
}
