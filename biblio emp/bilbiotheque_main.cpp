#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include "econio.h"
#include "econio.cpp"
#include "Struture.cpp"

liv *tete_liv=NULL;
adr *tete_adr=NULL;
emp *tete_emp=NULL;
liv *inc=NULL;
void gxy(int x,int y, char ch[])
{
	gotoxy(x,y);
	printf("%s",ch);
}
void layout()
{
gotoxy(48,1);printf("Gestion d'une bibliotheque");
	gotoxy(1,2); for (int i=0;i<110;i++)  printf("%c",196);	
		for (int i=0;i<7;i++)
		{
			gotoxy(15,3+i); printf("%c",179);
		}
	gotoxy(1,10); for (int i=0;i<110;i++)  printf("%c",196);	
	gxy(1,3,"G.livres");
	gxy(1,5,"G.adherants");
	gxy(1,7,"G.emprunts");
	gxy(1,9,"Quitter");
}
void cadre (int a,int b,int c,int d,char e, char f)
{
	textbackground(e);
	textcolor(f);
}

void car()
{
	int i,j;
	for (i=2;i<=24;i++)
		for (j=1;j<=80;j++)
		{
			gotoxy(j,i);
			printf("%c",178);
		}
}

emp *insert_emp(emp **tete,adr **a, liv **l)
{   
	gotoxy(1,15);
	emp *p=NULL; 
	dat *d1,*d2; int x1=0,y1=0;
	int code_livre_entre ;  
    int code_adherant_entre ; 
	p=(emp*) malloc (sizeof(emp));
	printf("Donner le code d'emprunt");
	scanf("%d",&p->code_emp);
	do
	{
		adr *q=*a;
	printf("Donner le code de l'adherant");
	scanf("%d",&code_adherant_entre);
	while (q!=NULL && x1==0)
	{
		if (code_adherant_entre==q->id_ad)
		{	x1++;  p->code_adherant=q;}
		else
			q=q->suivant;
	}}while(x1==0);
	do
	{
		liv *r=*l;
	printf("Donner le code du livre");
	scanf("%d",&code_livre_entre);
	while (r!=NULL && y1==0)
	{
		if (code_livre_entre==r->id_liv)
		{	y1++;  p->code_livre=r; inc=r;}
		else
			r=r->suivant;
	}}while(y1==0);
	p->date_deb_pret=(dat*)malloc(sizeof(dat));
	p->date_fin_pret=(dat*)malloc(sizeof(dat)); 
	printf("Donner la date debut de l'emprunt");
	scanf("%d",&p->date_deb_pret->jj);
	scanf("%d",&p->date_deb_pret->mm);
	scanf("%d",&p->date_deb_pret->aaaa);
	printf("Donner la date fin de l'emprunt");
	scanf("%d",&p->date_fin_pret->jj);
	scanf("%d",&p->date_fin_pret->mm);
	scanf("%d",&p->date_fin_pret->aaaa);
	
	
	p->suivant=*tete;
	*tete=p;
	inc->nbre_exp1--;
	return *tete;
}
void affiche_emp(emp **tete)
{
	emp *courant; int i;
	clrscr();
	gxy(48,11,"Consultation des emprunts");
	layout();
	gxy(1,7,"G.emprunts->");
	gxy(17,7,"Insertion  Consultation  Modification  Suppression  Quitter");
	gxy(33,8,"|"); gxy(33,9,"V");
	gotoxy(1,12); for ( i=0;i<110;i++)  printf("%c",196);
	if (*tete==NULL)
	{
		gxy(1,13,"Il n'y a aucun emprunt, veuillez inserer des emprunts.");
		gxy(1,14,"Appuyer sur une touche pour retourner.");
	}
	else
	{
     gxy(2,13,"code emprunt"); gxy(20,13,"code adherant"); gxy(40,13,"code livre");gxy(60,13,"date debut"); gxy(80,13,"date fin");
	 for ( i=0;i<10;i++)
		{
			gotoxy(15,13+i); printf("%c",179);
		}
			for ( i=0;i<10;i++)
		{
			gotoxy(32,13+i); printf("%c",179);
		}
			for ( i=0;i<10;i++)
		{
			gotoxy(56,13+i); printf("%c",179);
		}
		gotoxy(1,14); for (i=0;i<110;i++)  printf("%c",196);
	for (courant=*tete,i=0;courant!=NULL;courant=courant->suivant,i++)
	{
		gotoxy(6,15+i);printf("%d",courant->code_emp);
		gotoxy(20,15+i);printf("%d",courant->code_adherant->id_ad);
		gotoxy(40,15+i);printf("%d",courant->code_livre->id_liv);
		gotoxy(66,15+i);printf("%d/%d/%d",courant->date_deb_pret->jj,courant->date_deb_pret->mm,courant->date_deb_pret->aaaa);
		gotoxy(80,15+i);printf("%d/%d/%d",courant->date_fin_pret->jj,courant->date_fin_pret->mm,courant->date_fin_pret->aaaa);
	}
    gxy(1,24,"Appuyer sur une touche pour continuer.");
	}
}
adr *insert_adr(adr **tete)
{
	int n,i,j;adr* p; char er;
	gxy(48,11,"Insertion des adherants");
	layout();
	gxy(1,5,"G.adherants->");
	gxy(17,5,"Insertion  Consultation  Modification  Suppression  Quitter");
	gxy(21,6,"|"); gxy(21,7,"V");
	gotoxy(1,12); for ( i=0;i<110;i++)  printf("%c",196);
	gotoxy(1,13); printf("Saisir le nombre d'adherants a saisir : ");
			gotoxy(41,13);scanf("%d%c",&n,&er);
			for (i=0;n<=0;i++)
			{
				gotoxy(1,14+i);
			printf("Veuillez de saisir un nombre strictement positif : ");
			gotoxy(52,14+i);scanf("%d%c",&n,&er);
			}

for (i=0;i<n;i++)
{
	p=NULL;
p=(adr *) malloc(sizeof(adr));
	clrscr();
gxy(48,11,"Insertion des adherants");
	layout();
	gxy(1,5,"G.adherants->");
	gxy(17,5,"Insertion  Consultation  Modification  Suppression  Quitter");
	gxy(21,6,"|"); gxy(21,7,"V");
	gotoxy(1,12); for ( j=0;j<110;j++)  printf("%c",196);
	gotoxy(3,13);printf("Adherants %d:",i+1);
gxy(1,14,"Donner l'identifiant de l'adherant: ");
gxy(1,15,"Donner le nom de l'adherant: ");
gxy(1,16,"Donner le prenom de l'adherant: ");
gxy(1,17,"Donner le nombre d'emprunts: ");
gotoxy(37,14);scanf("%d%c",&p->id_ad,&er);
gotoxy(37,15);scanf("%s",p->nom);
gotoxy(37,16); scanf("%s", p->prenom);
gotoxy(37,17);scanf("%d",&p->nbre_liv_emp);
if (i==n-1)
gxy(1,19,"Appuyez sur une touche pour continuer.");
else {gxy(1,19,"Appuyez sur une touche pour passer au livre suivant.");getch();}
p->suivant=*tete;
*tete=p;
}
return (*tete);
}

void affiche_adr(adr **tete)
{
	adr *courant; int i;
	clrscr();
	gxy(48,11,"Consultation des adherants");
	layout();
	gxy(1,5,"G.adherants->");
	gxy(17,5,"Insertion  Consultation  Modification  Suppression  Quitter");
	gxy(33,6,"|"); gxy(33,7,"V");
	gotoxy(1,12); for ( i=0;i<110;i++)  printf("%c",196);
	if (*tete==NULL)
	{
		gxy(1,13,"Aucun adherant n'est inscrit, veuillez inscrire des adherants.");
		gxy(1,14,"Appuyer sur une touche pour retourner.");
	}
	else
	{
     gxy(2,13,"Identifiant"); gxy(20,13,"Nom"); gxy(40,13,"Prenom");gxy(60,13,"Nombre d'emprunts");
	 for ( i=0;i<10;i++)
		{
			gotoxy(15,13+i); printf("%c",179);
		}
			for ( i=0;i<10;i++)
		{
			gotoxy(32,13+i); printf("%c",179);
		}
			for ( i=0;i<10;i++)
		{
			gotoxy(56,13+i); printf("%c",179);
		}
		gotoxy(1,14); for (i=0;i<110;i++)  printf("%c",196);
	for (courant=*tete,i=0;courant!=NULL;courant=courant->suivant,i++)
	{
		gotoxy(6,15+i);printf("%d",courant->id_ad);
		gotoxy(20,15+i);printf("%s",courant->nom);
		gotoxy(40,15+i);printf("%s",courant->prenom);
		gotoxy(66,15+i);printf("%d",courant->nbre_liv_emp);
	}
    gxy(1,24,"Appuyer sur une touche pour continuer.");
	}
}
liv *insert_liv(liv **tete)
{
	int n,i,j;liv* p; char er;
	gxy(48,11,"Insertion des livres");
	layout();
	gxy(1,3,"G.livres->");
	gxy(17,3,"Insertion  Consultation  Modification  Suppression  Quitter");
	gxy(21,4,"|"); gxy(21,5,"V");
	gotoxy(1,12); for ( i=0;i<110;i++)  printf("%c",196);
	gotoxy(1,13); printf("Saisir le nombre de livres a saisir : ");
			gotoxy(39,13);scanf("%d%c",&n,&er);
			for (i=0;n<=0;i++)
			{
				gotoxy(1,14+i);
			printf("Veuillez de saisir un nombre strictement positif : ");
			gotoxy(52,14+i);scanf("%d%c",&n,&er);
			}

for (i=0;i<n;i++)
{
	p=NULL;
p=(liv *) malloc(sizeof(liv));
	clrscr();
gxy(48,11,"Insertion des livres");
	layout();
	gxy(1,3,"G.livres->");
	gxy(17,3,"Insertion  Consultation  Modification  Suppression  Quitter");
	gxy(21,4,"|"); gxy(21,5,"V");
	gotoxy(1,12); for ( j=0;j<110;j++)  printf("%c",196);
	gotoxy(3,13);printf("Livre %d:",i+1);
gxy(1,14,"Donner l'identifiant de livre: ");
gxy(1,15,"Donner le titre du livre: ");
gxy(1,16,"Donner le nom du d'auteur: ");
gxy(1,17,"Donner le nombre d'exemplaires: ");
gotoxy(35,14);scanf("%d%c",&p->id_liv,&er);
gotoxy(35,15); scanf("%s", p->titre);
gotoxy(35,16); scanf("%s", p->nom_auteur);
gotoxy(35,17);scanf("%d",&p->nbre_exp1);
if (i==n-1)
gxy(1,19,"Appuyez sur une touche pour continuer.");
else {gxy(1,19,"Appuyez sur une touche pour passer au livre suivant.");getch();}
p->suivant=*tete;
*tete=p;
}
return (*tete);
}

void affiche_liv(liv **tete)
{
	liv *courant; int i;
	clrscr();
	gxy(48,11,"Consultation des livres");
	layout();
	gxy(1,3,"G.livres->");
	gxy(17,3,"Insertion  Consultation  Modification  Suppression  Quitter");
	gxy(33,4,"|"); gxy(33,5,"V");
	gotoxy(1,12); for ( i=0;i<110;i++)  printf("%c",196);
	if (*tete==NULL)
	{
		gxy(1,13,"La bibliotheque est vide, veuillez inserer des livres.");
		gxy(1,14,"Appuyer sur une touche pour retourner.");
	}
	else
	{
     gxy(2,13,"Identifiant"); gxy(20,13,"Titre"); gxy(40,13,"Nom d'auteur");gxy(60,13,"Nombre d'exemplaires");
	 for ( i=0;i<10;i++)
		{
			gotoxy(15,13+i); printf("%c",179);
		}
			for ( i=0;i<10;i++)
		{
			gotoxy(32,13+i); printf("%c",179);
		}
			for ( i=0;i<10;i++)
		{
			gotoxy(56,13+i); printf("%c",179);
		}
		gotoxy(1,14); for (i=0;i<110;i++)  printf("%c",196);
	for (courant=*tete,i=0;courant!=NULL;courant=courant->suivant,i++)
	{
		gotoxy(6,15+i);printf("%d",courant->id_liv);
		gotoxy(20,15+i);printf("%s",courant->titre);
		gotoxy(40,15+i);printf("%s",courant->nom_auteur);
		gotoxy(66,15+i);printf("%d",courant->nbre_exp1);
	}
    gxy(1,24,"Appuyer sur une touche pour continuer.");
	}
}
void ec_emp(int a)
{
cadre(1,1,80,1,WHITE,0);
	textbackground(15);
		clrscr();
		layout();
		gxy(1,7,"G.emprunts->");
		gxy(17,7,"Emprunte  Consultation  Retourner un livre  Quitter");
        textbackground(9);
		textcolor(15);
	switch(a)
	{
case 1: 
		gotoxy(17,7);
		cprintf("Emprunte");
		break;
case 2: gotoxy(27,7);
		cprintf("Consultation");		
		break;
case 3: gotoxy(41,7);
		cprintf("Retourner un livre");
		break;
case 4: gotoxy(61,7);
		cprintf("Quitter");
		break;}
}

int m4(int sc)
{
	int m=sc,o,i;
	ec_emp(m);
	do
	{
		o=getch();
		if (o)
		{
			if ((o==75)||(o==77))
			{
				if (o==75)
					--m;
				else
					++m;
				if (m<1)
					m=4;
				if (m>4)
					m=1;
			}
			ec_emp(m);
		}
	} while (o!=13);
	return m;
}

void ma4()
{
 int m44=1;
	do
{
	textbackground(WHITE);clrscr();
	cadre(1,2,80,24,WHITE,0);
	clrscr();
	m44=m4(m44);
	while (kbhit())	getch;
	clrscr();
	textbackground(15);
	textcolor(0);
	clrscr();
	switch(m44)
	{
	case 1:
		tete_emp=insert_emp(&tete_emp,&tete_adr,&tete_liv);
		getch();
		break;
	case 2: 
		affiche_emp(&tete_emp);
		getch();
		break;
	case 3: 
		//modification();
		getch();
		break;

	case 4: 
		break;
	}
}while (m44!=4);
}
void ec_ad(int a)
{
cadre(1,1,80,1,WHITE,0);
	textbackground(15);
		clrscr();
		layout();
		gxy(1,5,"G.adherants->");
		gxy(17,5,"Insertion  Consultation  Modification  Suppression  Quitter");
        textbackground(9);
		textcolor(15);
	switch(a)
	{
case 1: 
		gotoxy(17,5);
		cprintf("Insertion");
		break;
case 2: gotoxy(28,5);
		cprintf("Consultation");		
		break;
case 3: gotoxy(42,5);
		cprintf("Modification");
		break;
case 4: gotoxy(56,5);
		cprintf("Suppression");
		break;
case 5: gotoxy(69,5);
		cprintf("Quitter");
		break;}
}

int m3(int sc)
{
	int m=sc,o,i;
	ec_ad(m);
	do
	{
		o=getch();
		if (o)
		{
			if ((o==75)||(o==77))
			{
				if (o==75)
					--m;
				else
					++m;
				if (m<1)
					m=5;
				if (m>5)
					m=1;
			}
			ec_ad(m);
		}
	} while (o!=13);
	return m;
}

void ma3()
{
 int m34=1;
	do
{
	textbackground(WHITE);clrscr();
	cadre(1,2,80,24,WHITE,0);
	clrscr();
	m34=m3(m34);
	while (kbhit())	getch;
	clrscr();
	textbackground(15);
	textcolor(0);
	clrscr();
	switch(m34)
	{
	case 1:
		tete_adr=insert_adr(&tete_adr);
		getch();
		break;
	case 2: 
		affiche_adr(&tete_adr);
		getch();
		break;
	case 3: 
		//modification();
		getch();
		break;

	case 4: 
		//suppression();
		getch();
		break;
	case 5: 
		//quitter();
		break;
	}
}while (m34!=5);
}
void ec_liv(int a)
{
cadre(1,1,80,1,WHITE,0);
	textbackground(15);
		clrscr();
		layout();
		gxy(1,3,"G.livres->");
		gxy(17,3,"Insertion  Consultation  Modification  Suppression  Quitter");
        textbackground(9);
		textcolor(15);
	switch(a)
	{
case 1: 
		gotoxy(17,3);
		cprintf("Insertion");
		break;
case 2: gotoxy(28,3);
		cprintf("Consultation");		
		break;
case 3: gotoxy(42,3);
		cprintf("Modification");
		break;
case 4: gotoxy(56,3);
		cprintf("Suppression");
		break;
case 5: gotoxy(69,3);
		cprintf("Quitter");
		break;}
}

int m2(int sc)
{
	int m=sc,o,i;
	ec_liv(m);
	do
	{
		o=getch();
		if (o)
		{
			if ((o==75)||(o==77))
			{
				if (o==75)
					--m;
				else
					++m;
				if (m<1)
					m=5;
				if (m>5)
					m=1;
			}
			ec_liv(m);
		}
	} while (o!=13);
	return m;
}

void ma2()
{
 int m24=1;
	do
{
	textbackground(WHITE);clrscr();
	cadre(1,2,80,24,WHITE,0);
	clrscr();
	m24=m2(m24);
	while (kbhit())	getch;
	clrscr();
	textbackground(15);
	textcolor(0);
	clrscr();
	switch(m24)
	{
	case 1:
		tete_liv=insert_liv(&tete_liv);
		getch();
		break;
	case 2: 
		affiche_liv(&tete_liv);
		getch();
		break;
	case 3: 
		//modification();
		getch();
		break;

	case 4: 
		//suppression();
		getch();
		break;
	case 5: 
		//quitter();
		break;
	}
}while (m24!=5);
}
void ec1(int a)
{
	cadre(1,1,80,1,WHITE,0);
	textbackground(15);
		clrscr();
		layout();
        textbackground(9);
		textcolor(15);
	switch(a)
	{
case 1: 
		gotoxy(1,3);
		cprintf("G.livres");
		break;
case 2: gotoxy(1,5);
		cprintf("G.adherants");		
		break;
case 3: gotoxy(1,7);
		cprintf("G.emprunts");
		break;
case 4: gotoxy(1,9);
		cprintf("Quitter");
		break;
	}
}	
int m1(int sc)
{
	int m=sc,o,i;
	ec1(m);
	do
	{
		o=getch();
		if (o)
		{
			if ((o==72)||(o==80))
			{
				if (o==72)
					--m;
				else
					++m;
				if (m<1)
					m=4;
				if (m>4)
					m=1;
			}
			ec1(m);
		}
	} while (o!=13);
	return m;
}


void main ()
{
	int m14=1;
	printf("\a");
	do
{
	textbackground(WHITE);clrscr();
	cadre(1,2,80,24,WHITE,0);
	clrscr();
	car();
	while (kbhit())
				getch;
	clrscr();
		textbackground(15);
		textcolor(0);
		clrscr();
	m14=m1(m14);
	switch(m14)
	{
	case 1:
		ma2();
		break;
	case 2:
		ma3();
		break;
	case 3: 		
		ma4();
		break;
	case 4:
		while (kbhit())
				getch;
	clrscr();
		textbackground(15);
		textcolor(0);
		clrscr();
		gxy(50,12,"Au revoir ^_^");
		getch();
		break;
	}
}while (m14!=4);
}