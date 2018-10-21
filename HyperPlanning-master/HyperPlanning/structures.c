#include "structures.h"

int initGrp(Groupe* g, int* nb_g){
    g->num=++*nb_g;
    g->matieres=malloc(sizeof(Matiere)*20);
    if (g->matieres==NULL)
        return -1;
    g->stg=malloc(sizeof(Stagiaire)*30);
    if (g->stg==NULL)
        return -1;
    g->nb_stg=0;
    g->seances=malloc(sizeof(Seance)*40);
    if (g->seances==NULL)
        return -1;
    g->nb_sean=0;
    g->nb_mat=0;

    printf("Un nouveau groupe a ete cree, vous pourrez y ajouter des stagiaires et des matieres via les interfaces proposees.\n");
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

    s->login.privilege=stag;

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

    free(s);
    printf("Le nouveau Stagiaire a ete ajoute\nSon identifiant est : %s\nSon mot de passe est : %s\n",s->login.identifiant,s->login.mdp);

    return 0;
}

int initForm(Formateur* f){
    char tmp;
    f->nom=malloc(sizeof(char)*25);
    if (f->nom==NULL)
        return -1;
    printf("Entrez le nom du Formateur : \n");
    fflush(stdin);
    scanf("%s",f->nom);

    f->prenom=malloc(sizeof(char)*25);
    if (f->prenom==NULL)
        return -1;
    printf("Entrez le prenom du Formateur : \n");
    fflush(stdin);
    scanf("%s",f->prenom);

    f->d_naissance=malloc(sizeof(char)*25);
    if (f->prenom==NULL)
        return -1;
    printf("Entrez la date de naissance du Formateur : \n");
    fflush(stdin);
    scanf("%s",f->d_naissance);

    printf("Entrez le sexe du Formateur h / f : \n");
    fflush(stdin);
    scanf("%c",&tmp);
    while (tmp!='h' && tmp !='f'){
        printf("Veuillez taper la lettre f pour Femme ou h pour Homme :\n");
        fflush(stdin);
        scanf("%c",&tmp);
    }
    if(tmp=='h')
        f->sexe=H;
    else
        f->sexe=F;

    f->tel_mobile=malloc(sizeof(char)*10);
    if (f->tel_mobile==NULL)
        return -1;
    printf("Entrez le telephone mobile du Formateur sans espaces : \n");
    fflush(stdin);
    scanf("%s",f->tel_mobile);

    f->login.identifiant=malloc(sizeof(char)*9);
    if (f->login.identifiant==NULL)
        return -1;
    strncpy(f->login.identifiant,f->nom,8);
    f->login.identifiant[8]='\0';

    f->login.mdp=malloc(sizeof(char)*20);
    if (f->login.mdp==NULL)
        return -1;
    printf("Entrez un mot de passe pour le Formateur : \n");
    fflush(stdin);
    scanf("%s",f->login.mdp);

    printf("Entrez l'habilitation du formateur\na : Administrateur\nr : Responsable Formateur\nf : Formateur\n");
    fflush(stdin);
    scanf("%c",&tmp);
    while (tmp!='a' && tmp !='r' && tmp!='f'){
        printf("Veuillez taper l'une des options ci-dessous\na : Administrateur\nr : Responsable Formateur\nf : Formateur\n");
        fflush(stdin);
        scanf("%c",&tmp);
    }
    if(tmp=='a')
        f->login.privilege=adm;
    else if(tmp=='r')
        f->login.privilege=resp;
    else
        f->login.privilege=form;
    return 0;
}

int accesStg(Groupe* ga, Login l,Groupe* g, int nb_g){
    int i=0,j,co=0;
    while (co==0 && i<nb_g){
        j=0;
        while(co==0 && j<g[i].nb_stg){
            co=compareLog(l,g[i].stg[j].login);
            j++;
        }
        i++;
    }
    if(co!=0){
        *ga=g[i];
        return g[i].stg[j].login.privilege;
    }
    else
       return aucun;
}

int accesForm(Formateur* fa, Login l,Formateur* f,int nb_f){
    int i=0,co=0;
    while (co==0 && i<nb_f){
        co=compareLog(l,f[i].login);
        i++;
    }
    if(co!=0){
        *fa=f[i];
        return f[i].login.privilege;
    }
    else
        return aucun;
}

int compareLog(Login l, Login lo){
    printf("id form : %s\nmdp form : %s\n",l.identifiant,l.mdp);
    printf("id check : %s\nmdp check : %s\n",lo.identifiant,lo.mdp);
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
        printf("Veuillez taper la lettre f pour Femme ou h pour Homme :\n");
        fflush(stdin);
        scanf("%c",&tmp);
    }
    if(tmp=='h')
        s->sexe=H;
    else
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

int initMat(Matiere* m, Formateur* f, int nb_f){
    if(nb_f<1){
        printf("Il n'existe aucun Formateur, vous devez en creer avant de creer une matière.\n");
        return 0;
    }
    int i,j,valid;
    char* tmp=malloc(sizeof(char)*25);
    char tmp2;
    int itmp;
    if(tmp==NULL)
        return -1;

    m->nom=malloc(sizeof(char)*20);
    if (m->nom==NULL)
        return -1;
    printf("Choisissez un nom pour la nouvelle Matiere :\n");
    fflush(stdin);
    scanf("%s",m->nom);

    m->volume_h=malloc(sizeof(int)*4);
    if (m->volume_h==NULL)
        return -1;
    printf("Choisissez le volume d'heure pour les TD :\n");
    fflush(stdin);
    scanf("%d",&itmp);
    while (itmp<0 || itmp%2!=0){
        printf("Choisissez un volume pair pour les TD :\n");
        fflush(stdin);
        scanf("%d",&itmp);
    }
    m->volume_h[TD]=itmp;
    printf("Choisissez le volume d'heure pour les TP :\n");
    fflush(stdin);
    scanf("%d",&itmp);
    while (itmp<0 || itmp%2!=0){
        printf("Choisissez un volume pair pour les TP :\n");
        fflush(stdin);
        scanf("%d",&itmp);
    }
    m->volume_h[TP]=itmp;
    printf("Choisissez le volume d'heure les Amphitheatre :\n");
    fflush(stdin);
    scanf("%d",&itmp);
    while (itmp<0 || itmp%2!=0){
        printf("Choisissez un volume pair pour les Amphitheatre :\n");
        fflush(stdin);
        scanf("%d",&itmp);
    }
    m->volume_h[Amphi]=itmp;
    printf("Choisissez le volume d'heure pour les DE :\n");
    fflush(stdin);
    scanf("%d",&m->volume_h[DE]);


    printf("Choisissez un Formateur Responsable (Tapez son nom) : \n");
    fflush(stdin);
    scanf("%s",tmp);

    i=0;
    while(i<nb_f && strcmp(tmp,f[i].nom)!=0){
            printf("%d  ---",i);
            printf("%s",f[i].nom);
        i++;
    }
    while(i>=nb_f){
        printf("Ce Formateur n'existe pas.\nTapez un nom de formateur correct.\n");
        fflush(stdin);
        scanf("%s",tmp);
        i=0;
        while(i<nb_f && strcmp(tmp,f[i].nom)!=0){
                        printf("%d  ---",i);
            printf("%s",f[i].nom);
        i++;
        }
    }
    m->responsable=f[i];
    if(f[i].login.privilege>resp){
        f[i].login.privilege=resp;
    }

    m->formateurs=malloc(sizeof(Formateur)*10);
    if (m->formateurs==NULL)
        return -1;

    m->nb_form=0;

    printf("Voulez-vous ajouter des formateurs ? (Vous pourrez le faire plus tard via l'interface de gestion) o/n :\n");
    fflush(stdin);
    scanf("%s",&tmp2);
    while(tmp2!='o' && tmp2 !='n'){
        printf("Reponse non pris en charge, tapez o pour oui ou n pour non\n");
        fflush(stdin);
        scanf("%s",&tmp2);
    }
    while(tmp2=='o'){
        printf("Choisissez le nom d'un Formateur a ajoute a cette matiere :\n");
        fflush(stdin);
        scanf("%s",tmp);
        i=0;
        while(i<nb_f && strcmp(tmp,f[i].nom)!=0){
            i++;
        }
        while(i>=nb_f){
            printf("Ce Formateur n'existe pas.\nTapez un nom de formateur correct.\n");
            fflush(stdin);
            scanf("%s",tmp);
            i=0;
            while(i<nb_f && strcmp(tmp,f[i].nom)!=0){
            i++;
            }
        }
        valid=1;
        for(j=0;j<m->nb_form;j++){
            if(strcmp(m->formateurs[j].nom,f[i].nom)==0){
                valid=0;
            }
        }
        if(valid!=0){
            m->formateurs[m->nb_form]=f[i];
            m->nb_form++;
        }
        else
            printf("Ce formateur est deja present dans la liste des formateurs de la matiere\n");

        printf("Voulez-vous en ajouter un autre ? o/n :");
        fflush(stdin);
        scanf("%s",&tmp2);
        while(tmp2!='o' && tmp2 !='n'){
            printf("Reponse non pris en charge, tapez o pour oui ou n pour non\n");
            fflush(stdin);
            scanf("%s",&tmp2);
        }
    }
    free(tmp);
    return 0;
}

int initSean(Groupe* g, int nb_g, int nb_m){
    if(nb_g<1){
        printf("Il n'existe pas de groupe, veuillez en creer avant de planifier une Seance.\n");
        return 0;
    }
    if(nb_m<1){
        printf("Il n'existe pas de matiere, veuillez en creer avant de planifier une Seance.\n");
        return 0;
    }
    int i,j,k,l;
    int itmp;
    int valid;
    char* stmp=malloc(sizeof(char)*25);
    if (stmp==NULL)
        return -1;

    printf("Choisissez le numeros du Groupe auquel ajouter une Seance :\n");
    fflush(stdin);
    scanf("%d",&itmp);
    i=0;
    while(i<nb_g && itmp!=g[i].num){
        i++;
    }
    while(i>=nb_g){
        i=0;
        printf("Le groupe choisit n'existe pas, selectionnez un autre numeros :\n");
        fflush(stdin);
        scanf("%d",&itmp);
            while(i<nb_g && itmp!=g[i].num){
                i++;
            }
    }
    if(g[i].nb_mat<1){
        printf("Ce groupe n'est associé a aucune matiere, veuillez lui en associer avant d'y ajouter des seances.\n");
        return 0;
    }

    g[i].seances[g[i].nb_sean].n_matiere=malloc(sizeof(char)*25);
    if (g[i].seances[g[i].nb_sean].n_matiere==NULL)
        return -1;
    printf("Choisissez une matiere pour la seance :\n");
    fflush(stdin);
    scanf("%s",stmp);
    j=0;
    while(j<g[i].nb_mat && strcmp(stmp,g[i].matieres[j].nom)!=0){
        j++;
    }
    while(j>=g[i].nb_mat){
        j=0;
        printf("Le groupe n'est pas concerne par cette matiere, selectionnez en une autre :\n");
        fflush(stdin);
        scanf("%s",stmp);
            while(j<g[i].nb_mat && strcmp(stmp,g[i].matieres[j].nom)!=0){
                j++;
            }
    }
    g[i].seances[g[i].nb_sean].n_matiere=g[i].matieres[j].nom;



    printf("Choisissez le type de la seance.\n1 : TD\n2 : TP\n3 : Amphitheatre\n4 : DE\n");
    fflush(stdin);
    scanf("%d",&itmp);
    while(itmp>4 && itmp<1){
        printf("Choisissez parmi les types de seance propose.\n1 : TD\n2 : TP\n3 : Amphitheatre\n4 : DE\n");
        fflush(stdin);
        scanf("%d",&itmp);
    }
    if (itmp==1)
        g[i].seances[g[i].nb_sean].type=TD;
    else if (itmp==2)
        g[i].seances[g[i].nb_sean].type=TP;
    else if (itmp==3)
        g[i].seances[g[i].nb_sean].type=Amphi;
    else
        g[i].seances[g[i].nb_sean].type=DE;

    if (g[i].matieres[j].volume_h[g[i].seances[g[i].nb_sean].type]==0){
        printf("Il n'est plus possible d'ajouter ce type de seance a ce groupe pour cette matiere.\n");
        return 0;
    }

    g[i].seances[g[i].nb_sean].formateur=malloc(sizeof(char)*25);
    if (g[i].seances[g[i].nb_sean].formateur==NULL)
        return -1;
    printf("Choisissez un formateur pour la seance :\n");
    fflush(stdin);
    scanf("%s",stmp);
    k=0;
    if(strcmp(stmp,g[i].matieres[j].responsable.nom)==0){
        g[i].seances[g[i].nb_sean].formateur=g[i].matieres[j].responsable.nom;
    }
    else{
        while(k<g[i].matieres[j].nb_form && strcmp(stmp,g[i].matieres[j].formateurs[k].nom)!=0){
            k++;
        }
        while(k>=g[i].matieres[j].nb_form){
            printf("Le formateur n'est pas concerne par cette matiere, selectionnez en un autre :\n");
            fflush(stdin);
            scanf("%s",stmp);
            if(strcmp(stmp,g[i].matieres[j].responsable.nom)==0){
                k=-1;
            }
            else{
                k=0;
                while(k<g[i].matieres[j].nb_form && strcmp(stmp,g[i].matieres[j].formateurs[k].nom)!=0){
                    k++;
                }
            }
        }
        if (k<0)
            g[i].seances[g[i].nb_sean].formateur=g[i].matieres[j].responsable.nom;
        else
            g[i].seances[g[i].nb_sean].formateur=g[i].matieres[j].formateurs[k].nom;
    }

    do{
        valid=1;
        printf("Choisissez une date : \nChoisissez l'annee :\n");
        fflush(stdin);
        scanf("%d",&itmp);
        while(itmp<2018 || itmp>2021){
            printf("Choisissez une annee valide pour le groupe.\n");
            fflush(stdin);
            scanf("%d",&itmp);
        }
        g[i].seances[g[i].nb_sean].date.annee=itmp;

        printf("Choisissez le mois :\n");
        fflush(stdin);
        scanf("%d",&itmp);
        while(itmp>12 || itmp<1){
            printf("Choisissez un numeros entre 1 et 12\n");
            fflush(stdin);
            scanf("%d",&itmp);
        }
        g[i].seances[g[i].nb_sean].date.mois=itmp;

        printf("Choisissez un jour :\n");
        fflush(stdin);
        scanf("%d",&itmp);
        while(itmp>31 || itmp<1){
            printf("Choisissez un numeros entre 1 et 31\n");
            fflush(stdin);
            scanf("%d",&itmp);
        }
        g[i].seances[g[i].nb_sean].date.jour=itmp;

        printf("Choisissez une heure de debut de la seance :\n");
        fflush(stdin);
        scanf("%d",&itmp);
        while(itmp>18 || itmp<8){
            printf("Choisissez un numeros entre 8 et 18\n");
            fflush(stdin);
            scanf("%d",&itmp);
        }
        g[i].seances[g[i].nb_sean].date.heure=itmp;

        for(l=0;l<nb_g;l++){
            for(k=0;k<g[j].nb_sean;k++){
                if (strcmp(g[i].seances[g[i].nb_sean].formateur,g[l].seances[k].formateur)==0 && g[i].seances[g[i].nb_sean].date.mois==g[l].seances[k].date.mois && g[i].seances[g[i].nb_sean].date.jour==g[l].seances[k].date.jour){
                    if (g[i].seances[g[i].nb_sean].type==DE){
                        if (g[i].seances[g[i].nb_sean].date.heure>g[l].seances[k].date.heure-1){
                            if (g[j].seances[k].type==DE){
                                if (g[i].seances[g[i].nb_sean].date.heure<g[l].seances[k].date.heure+1){
                                    printf("Probleme d horaire pour ce formateur\n");
                                    valid=0;
                                }
                            }
                            else{
                                if (g[i].seances[g[i].nb_sean].date.heure<g[l].seances[k].date.heure+2){
                                    printf("Probleme d horaire pour ce formateur\n");
                                    valid=0;
                                }
                            }
                        }
                    }
                    else{
                        if (g[i].seances[g[i].nb_sean].date.heure>g[l].seances[k].date.heure-2){
                            if (g[j].seances[k].type==DE){
                                if (g[i].seances[g[i].nb_sean].date.heure<g[l].seances[k].date.heure+1){
                                    printf("Probleme d horaire pour ce formateur\n");
                                    valid=0;
                                }
                            }
                            else{
                                if (g[i].seances[g[i].nb_sean].date.heure<g[l].seances[k].date.heure+2){
                                    printf("Probleme d horaire pour ce formateur\n");
                                    valid=0;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(l=0;l<g[i].nb_sean;l++){
            if(g[i].seances[g[i].nb_sean].date.mois==g[i].seances[l].date.mois && g[i].seances[g[i].nb_sean].date.jour==g[i].seances[l].date.jour){
                if (g[i].seances[g[i].nb_sean].type==DE){
                    if (g[i].seances[g[i].nb_sean].date.heure>g[i].seances[l].date.heure-1){
                        if (g[j].seances[l].type==DE){
                            if (g[i].seances[g[i].nb_sean].date.heure<g[i].seances[l].date.heure+1){
                                printf("Probleme d horaire pour ce groupe\n");
                                valid=0;
                            }
                        }
                        else{
                            if (g[i].seances[g[i].nb_sean].date.heure<g[i].seances[l].date.heure+2){
                                printf("Probleme d horaire pour ce formateur\n");
                                valid=0;
                            }
                        }
                    }
                }
                else{
                    if (g[i].seances[g[i].nb_sean].date.heure>g[j].seances[l].date.heure-2){
                        if (g[j].seances[l].type==DE){
                            if (g[i].seances[g[i].nb_sean].date.heure<g[i].seances[l].date.heure+1){
                                printf("Probleme d horaire pour ce formateur\n");
                                valid=0;
                            }
                        }
                        else{
                            if (g[i].seances[g[i].nb_sean].date.heure<g[i].seances[l].date.heure+2){
                                printf("Probleme d horaire pour ce formateur\n");
                                valid=0;
                            }
                        }
                    }
                }
            }
        }

    }while(valid!=1);

    if(g[i].seances[g[i].nb_sean].type==DE)
        g[i].matieres[j].volume_h[g[i].seances[g[i].nb_sean].type]--;
    else
        g[i].matieres[j].volume_h[g[i].seances[g[i].nb_sean].type]-=2;

    g[i].nb_sean++;
    free(stmp);
    printf("La seance a ete cree");

    return 0;
}

int addMat(Groupe* g, Matiere* m,int nb_g, int nb_m){
    if(nb_g<1){
        printf("Il n'existe pas de groupe, veuillez en creer avant de planifier une Seance.\n");
        return 0;
    }
    if(nb_m<1){
        printf("Il n'existe pas de matiere, veuillez en creer avant de planifier une Seance.\n");
        return 0;
    }
    int i,j;
    int itmp;
    char* stmp=malloc(sizeof(char)*25);
    if (stmp==NULL)
        return -1;

    printf("Choisissez le numeros du Groupe auquel ajouter une Matiere :\n");
    fflush(stdin);
    scanf("%d",&itmp);
    i=0;
    while(itmp!=g[i].num && i<nb_g){
        i++;
    }
    while(i>=nb_g){
        i=0;
        printf("Le groupe choisit n'existe pas, selectionnez un autre numeros :\n");
        fflush(stdin);
        scanf("%d",&itmp);
            while(itmp!=g[i].num && i<nb_g){
                i++;
            }
    }

    printf("Choisissez la matiere a ajouter:\n");
    fflush(stdin);
    scanf("%s",stmp);
    j=0;
    while(j<nb_m && strcmp(stmp,m[j].nom)!=0){
        j++;
    }
    while(j>=nb_m){
        j=0;
        printf("La matiere n existe pas, veuillez en selectionnez une autre :\n");
        fflush(stdin);
        scanf("%s",stmp);
            while(j<nb_m && strcmp(stmp,m[j].nom)!=0){
                j++;
            }
    }
    g[i].matieres[g[i].nb_mat]=m[j];
    g[i].nb_mat++;
    free(stmp);
    printf("La Matiere a ete ajoute au groupe.\n");
    return 0;
}

void planningH(Groupe g){
    /*time_t timestamp;
    struct tm t;
    int i,j,k;
    char*** c;
    timestamp = time(NULL);
    &t = globaltime(&timestamp);
    t->tm_mon++;
    t->tm_year+=1900;
    mktime(t);

    printf("Lundi %d/%d/%d :\n",t->tm_mday,t->tm_mon,t->tm_year);
    for(i=8;i<18;i++){
        if(g.seances[k].date.annee==t->tm_year && g.seances[k].date.mois==t->tm_mon && g.seances[k].date.jour==t->tm_mday-t->tm_wday+i){

        }
    }
    printf("Mardi %d/%d :\n",t->tm_mday,t->tm_mon);
    for(i=8;i<18;i++){

    }
    printf("Mercredi %d/%d :\n",t->tm_mday,t->tm_mon);
    for(i=8;i<18;i++){

    }
    printf("Jeudi %d/%d :\n",t->tm_mday,t->tm_mon);
    for(i=8;i<18;i++){

    }
    printf("Vendredi %d/%d :\n",t->tm_mday,t->tm_mon);
    for(i=8;i<18;i++){

    }*/


/*    c=(char***)malloc(sizeof(char)*7);
    for(i=0;i<7;i++){
        c[i]=(char**)malloc(sizeof(char)*22);
        for(j=0;j<22;j++){
            c[i][j]=(char*)malloc(sizeof(char)* 21);
            c[i][j]="";
        }
    }

    for(i=0;i<7;i++){
        for(j=0;j<22;j+=2){
            for(k=0;k<g.nb_sean;k++){
                if(g.seances[k].date.annee==t->tm_year && g.seances[k].date.mois==t->tm_mon && g.seances[k].date.jour==t->tm_mday-t->tm_wday+i && g.seances[k].date.heure==j+8){
                    if (g.seances[k].type==TD)
                        c[i][j]=strncat("TD \0",g.seances[k].n_matiere,17);
                    else if (g.seances[k].type==TP)
                        c[i][j]=strncat("TP \0",g.seances[k].n_matiere,17);
                    else if (g.seances[k].type==Amphi)
                        c[i][j]=strncat("Amphi \0",g.seances[k].n_matiere,14);
                    else
                        c[i][j]=strncat("DE \0",g.seances[k].n_matiere,17);
                    if (strcmp(c[i][j],"")!=0)
                        strcpy(c[i][j+1],g.seances[k].formateur);
                }
            }
        }
    }

    printf("    Lundi    Mardi    Mercredi Jeudi   Vendredi Samedi   Dimanche\n");
    for(i=0;i<21;i+=2){
        printf("%2d",(i/2)+8);
        printf("   %20s%20s",c[0][i],c[1][i]);
        printf("%20s%20s",c[2][i],c[3][i]);
        printf("%20s%20s",c[4][i],c[5][i]);
        printf("%20s\n",c[6][i]);
        printf("     %20s%20s",c[0][i+1],c[1][i+1]);
        printf("%20s%20s",c[2][i+1],c[3][i+1]);
        printf("%20s%20s",c[4][i+1],c[5][i+1]);
        printf("%20s\n",c[6][i+1]);
    }
*/
    /*printf
    printf("9   %20s%20s%20s%20%20s%20s%20s\n");
    printf("10  %20s%20s%20s%20%20s%20s%20s\n");
    printf("11  %20s%20s%20s%20%20s%20s%20s\n");
    printf("12  %20s%20s%20s%20%20s%20s%20s\n");
    printf("13  %20s%20s%20s%20%20s%20s%20s\n");
    printf("14  %20s%20s%20s%20%20s%20s%20s\n");
    printf("15  %20s%20s%20s%20%20s%20s%20s\n");
    printf("16  %20s%20s%20s%20%20s%20s%20s\n");
    printf("17  %20s%20s%20s%20%20s%20s%20s\n");
    printf("18  %20s%20s%20s%20%20s%20s%20s\n");*/

 /*   for(i=0;i<7;i++){
        for(j=0;j<22;j++)
            free(c[i][j]);
        free(c[i]);
    }
    free(c);*/
}

void planningM(Groupe g){
}

void planningFH(Formateur f){

}

void planningFM(Formateur f){
}

int planningSM(Groupe* g, int nb_g){

    return 0;
}

int planningSH(Groupe* g, int nb_g){
    if (nb_g<1){
        printf("Il n y a pas de groupe existant");
        return 0;
    }
    int tmp;
    int i;
    do{
        printf("Choisissez le groupe du quel vous voulez voir l'emplois du temps\n");
        fflush(stdin);
        scanf("%d",&tmp);
        i=0;
        while(i<nb_g && g[i].num != tmp){
            i++;
        }
        if(i>=nb_g)
            printf("Ce numeros de groupe n est pas valide.\n");
    }while(i>=nb_g);
    planningH(g[i]);
    return 0;
}

void modifP(Formateur f, Groupe* g, Matiere* m, int nb_g, int nb_m){
}

void modifF(Formateur* f, int nb_f){
}

void modifG(Groupe* g, int nb_g){
}

void modifM(Matiere* m, int nb_m){
}

void modifS(Groupe* g, int nb_g){
}

void deconnexion(){

}

int JourS(int jour,int mois,int an)
{
struct tm t;
t.tm_year = an+100;
t.tm_mon = mois - 1;
t.tm_mday = jour;
t.tm_hour = t.tm_min = t.tm_sec = 0;
if (mktime(&t)==-1)
    return 0;
return t.tm_wday;
}
