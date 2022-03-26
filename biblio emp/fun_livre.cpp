#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include "econio.h"
#include "econio.cpp"

liv *insert_livre(liv **tete)
{
liv* p; char er;
p=NULL;
p=(liv *) malloc(sizeof(liv));
printf("Donner l'identifiant de livre (id_liv)\n");
scanf("%d%c",&p->id_liv,&er);
printf("Donner le titre du livre\n");
gets(p->titre);
printf("Donner le nom du d'auteur\n");
gets(p->nom_auteur);
printf("Donner le nombre d'exemplaire de ce livre (id_liv)\n");
scanf("%d",&p->nbre_exp1);
p->suivant=*tete;
*tete=p;
return (*tete);
}