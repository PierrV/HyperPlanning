#include "structures.h"

int initGrp(Groupe* g, int* nb_g){
    g->num=++*nb_g;
    g->matieres=malloc(sizeof(Matiere)*10);
    if (g->matieres==NULL)
        return -1;

    g->stg=malloc(sizeof(Stagiaire)*30);
    if (g->stg==NULL)
        return -1;
    g->nb_stg=0;
    return 0;
}

int initStg(Stagiaire* s, Groupe* g, int nb_g){
    if (nb_g==0){
        printf("Il n'y a aucun groupe, commencer par en creer un.");
        return 0;
    }
    char * tmp;
    s->matricule=malloc(sizeof(char)*9);
    if (s->matricule==NULL)
        return -1;

    tmp=malloc(sizeof(char)*5);
    if (tmp==NULL)
        return -1;
    sprintf(tmp,"%04d",++num_matricule);
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
    if (majNom(s)!=0)
        return -1;

    s->prenom=malloc(sizeof(char)*25);
    if (s->prenom==NULL)
        return -1;
    if (majPrenom(s)!=0)
        return -1;

    if (majSexe(s)!=0)
        return -1;

    s->d_naissance=malloc(sizeof(char)*10);
    if (s->d_naissance==NULL)
        return -1;
    if (majNaissance(s)!=0)
        return -1;

    s->d_inscription=malloc(sizeof(char)*10);
    if (s->d_inscription==NULL)
        return -1;
    if (majInscription(s)!=0)
        return -1;

    if (majNumRue(s)!=0)
        return -1;

    s->nom_rue=malloc(sizeof(char)*30);
    if (s->nom_rue==NULL)
        return -1;
    if (majNomRue(s)!=0)
        return -1;

    s->code_postal=malloc(sizeof(char)*5);
    if (s->code_postal==NULL)
        return -1;
    if (majCP(s)!=0)
        return -1;

    s->ville=malloc(sizeof(char)*25);
    if (s->ville==NULL)
        return -1;
    if (majVille(s)!=0)
        return -1;

    s->tel_domicile=malloc(sizeof(char)*10);
    if (s->tel_domicile==NULL)
        return -1;
    if (majTelDom(s)!=0)
        return -1;

    s->tel_mobile=malloc(sizeof(char)*10);
    if (s->tel_mobile==NULL)
        return -1;
    if (majTelMob(s)!=0)
        return -1;

    if(addToGrp(s, g, nb_g)!=0)
        return -1;

    printf("Le nouveau Stagiaire a ete ajoute\nSon identifiant est : %s\nSon mot de passe est : %s\n",s->login.identifiant,s->login.mdp);

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

int majNom(Stagiaire* s){
    printf("Entrez le nouveau Nom du Stagiaire :\n");
    fflush(stdin);
    scanf("%s",s->nom);
    return 0;
}
int majPrenom(Stagiaire* s){
    printf("Entrez le nouveau Prenom du Stagiaire :\n");
    fflush(stdin);
    scanf("%s",s->prenom);
    return 0;
}

int majSexe(Stagiaire* s){
    char tmp;
    printf("Entrez le nouveau Sexe du Stagiaire h/f :\n");
    fflush(stdin);
    scanf("%c",&tmp);
    while (tmp!='h' && tmp !='f'){
        printf("Veuillez taper la lettre F pour Femme ou H pour Homme :\n");
        fflush(stdin);
        scanf("%c",&tmp);
    }
    if(tmp=='h')
        s->sexe=H;
    s->sexe=F;
    return 0;
}

int majNaissance(Stagiaire* s){
    printf("Entrez la nouvelle date de naissance du Stagiaire en format JJ/MM/AAAA :\n");
    fflush(stdin);
    scanf("%s",s->d_naissance);
    return 0;
}

int majInscription(Stagiaire* s){
    printf("Entrez la nouvelle date d'inscription du Stagiaire en format JJ/MM/AAAA :\n");
    fflush(stdin);
    scanf("%s",s->d_inscription);
    return 0;
}

int majNumRue(Stagiaire* s){
    printf("Entrez le nouveau numeros de rue du Stagiaire :\n");
    fflush(stdin);
    scanf("%d",&s->num_rue);
    return 0;
}

int majNomRue(Stagiaire* s){
    printf("Entrez le nouveau nom de rue du Stagiaire :\n");
    fflush(stdin);
    scanf("%s",s->nom_rue);
    return 0;
}

int majCP(Stagiaire* s){
    printf("Entrez le nouveau code postal du Stagiaire :\n");
    fflush(stdin);
    scanf("%s",s->code_postal);
    return 0;
}
int majVille(Stagiaire* s){
    printf("Entrez la nouvelle ville du Stagiaire :\n");
    fflush(stdin);
    scanf("%s",s->ville);
    return 0;
}

int majTelDom(Stagiaire* s){
    printf("Entrez le nouveau numeros de telephone du domicile du Stagiaire sans espaces :\n");
    fflush(stdin);
    scanf("%s",s->tel_domicile);
    return 0;
}

int majTelMob(Stagiaire* s){
    printf("Entrez le nouveau numeros de telephone mobile du Stagiaire sans espaces:\n");
    fflush(stdin);
    scanf("%s",s->tel_mobile);
    return 0;
}

int addToGrp(Stagiaire* s, Groupe* g, int nb_g){
    int tmp,i=0;
    printf("Entrez le numeros du groupe auquel ajouter le nouveau Stagiaire : \n");
    fflush(stdin);
    scanf("%d",&tmp);
    while(tmp!=g[i].num && i<nb_g){
        printf("%d\n",g[i].num);
        i++;
    }
    while(i>=nb_g){
        i=0;
        printf("Le groupe choisit n'existe pas, selectionnez un autre numeros :\n");
        fflush(stdin);
        scanf("%d",&tmp);
            while(tmp!=g[i].num && i<nb_g){
                i++;
            }
    }
    g[i].stg[g[i].nb_stg]=*s;
    return 0;
}
