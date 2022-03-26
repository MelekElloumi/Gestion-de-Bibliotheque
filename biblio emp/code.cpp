/*#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include "econio.h"
#include "econio.cpp"

typedef struct
{
	int jj,mm,aaaa;
}date;

typedef struct
{
 char auteur[30];
 char titre[30];
 date datep;
} livre;

typedef struct
{
	bool b;
	int T[2];
	int taille;
} prob;
FILE* biblio;
char nomfich[]="biblio.txt";
char opt,er;


void layout()
{
gotoxy(48,1);printf("Gestion d'une bibliotheque");
	gotoxy(1,2); for (int i=0;i<110;i++)  printf("%c",196);	
		for (int i=0;i<22;i++)
		{
			gotoxy(15,3+i); printf("%c",179);
		}
	gotoxy(1,3);printf("Creation");
	gotoxy(1,5);printf("Insertion");
	gotoxy(1,7);printf("Consultation");
	gotoxy(1,9);printf("Suppression");
	gotoxy(1,11);printf("Quitter");
}
void creation()
{
	biblio=fopen(nomfich,"r");
	layout();
	gotoxy(1,3);printf("Creation->");
	gotoxy(50,3);printf("Creation de la bibliotheque");
	if (biblio)
	{
		
		gotoxy(20,5);printf("Attention! Le fichier bibliotheque existe deja."); int i=0; char optc[10];
		do{
		gotoxy(20,6+i);printf("Voulez-vous vraiment l'ecraser (o/n):");
			gotoxy(60,6+i);
			
			gets(optc);
			fflush(stdin);i++;
		} while ((optc[0]!='o' && optc[0] !='n' )|| strlen(optc)!=1);
		if (optc[0]=='o')
		{
			fclose(biblio);
			biblio=fopen(nomfich,"w");
			fclose(biblio);
		}
		gotoxy(20,7+i);printf("Appuyez sur une touche pour continuer.");
	}
	else
	{
		gotoxy(20,5);printf("Le fichier bibliotheque n'existe pas,");
		gotoxy(20,6);printf("Il vient d'etre creer avec succes");
		gotoxy(20,8);printf("Appuyer sur une touche pour continuer.");
		biblio=fopen(nomfich,"w"); fclose(biblio);
	}
}

prob test(livre unlivre)
{
	prob prob1; prob1.b=false; int l=-1,i,esp=0,chif=0,maj=0;
	if (unlivre.datep.aaaa<1000 || unlivre.datep.aaaa>2017)
	{l++; prob1.T[l]=1;}
	if (unlivre.datep.mm<1 || unlivre.datep.mm>12)
		{l++; prob1.T[l]=2;}
	if (unlivre.datep.jj<=0)
		{l++; prob1.T[l]=3;}
	if ((unlivre.datep.mm==4 || unlivre.datep.mm==6 || unlivre.datep.mm==11 || unlivre.datep.mm==9)&& unlivre.datep.jj>30)
		{l++; prob1.T[l]=4;}
	if ((unlivre.datep.mm==1 || unlivre.datep.mm==3 || unlivre.datep.mm==5 || unlivre.datep.mm==7 || unlivre.datep.mm==8 || unlivre.datep.mm==10 || unlivre.datep.mm==12)&& unlivre.datep.jj>31)
		{l++; prob1.T[l]=5;}
	if (unlivre.datep.mm==2 && unlivre.datep.aaaa%4==0 && unlivre.datep.jj>29)
		{l++; prob1.T[l]=6;}
	if (unlivre.datep.mm==2 && unlivre.datep.aaaa%4!=0 && unlivre.datep.jj>28)
		{l++; prob1.T[l]=7;}
	for (i=1;unlivre.auteur[i];i++)
	{
		if (unlivre.auteur[i]=='.')
			esp++;
		else if ((unlivre.auteur[i-1]=='.'&&islower(unlivre.auteur[i])) || (unlivre.auteur[i-1]!='.'&&isupper(unlivre.auteur[i])))
			maj++;
		if (!isalpha(unlivre.auteur[i])&&unlivre.auteur[i]!='.')
			chif++;		
	}
	if (esp!=1)
	{l++; prob1.T[l]=8;}
	if (chif!=0)
	{l++; prob1.T[l]=9;}
	if (!isupper(unlivre.auteur[0]) || maj!=0)
		{l++; prob1.T[l]=10;}
	esp=0,chif=0,maj=0;
	for (i=1;unlivre.titre[i];i++)
	{
		if (unlivre.titre[i]=='.')
			esp++;
		else if ((unlivre.titre[i-1]=='.'&&islower(unlivre.titre[i])) || (unlivre.titre[i-1]!='.'&&isupper(unlivre.titre[i])))
			maj++;
		if (!isalpha(unlivre.titre[i])&&unlivre.titre[i]!='.')
			chif++;		
	}
	if (esp==0)
	{l++; prob1.T[l]=11;}
	if (chif!=0)
	{l++; prob1.T[l]=12;}
	if (!isupper(unlivre.titre[0]) || maj!=0)
		{l++; prob1.T[l]=13;}
	if (l!=-1) prob1.b=true;
	prob1.taille=l+1;
	return prob1;
}

livre saisir(int i,int n)
{
	livre unlivre;
	int j;
	prob prob1;
	do
	{
	clrscr();
	layout();
	gotoxy(1,5);printf("Insertion->");
	gotoxy(50,3);printf("Insertion de livres");
	gotoxy(20,5);printf("Livre %d:",i);
	gotoxy(25,7);printf("Nom de l'auteur   : ");
	gotoxy(25,9);printf("Titre du livre    : ");
	gotoxy(25,11);printf("Date de parution :   /  /");
	gotoxy(45,7);gets(unlivre.auteur);
	gotoxy(45,9);gets(unlivre.titre);
	gotoxy(44,11);scanf("%d",&unlivre.datep.jj);
	gotoxy(47,11);scanf("%d",&unlivre.datep.mm);
	gotoxy(50,11);scanf("%d%c",&unlivre.datep.aaaa,&er);
	prob1=test(unlivre);
	if (prob1.b)
	{
		gotoxy(20,13); printf("Votre saisie est erronne:");
		for (j=0;j<prob1.taille;j++)
		{
			gotoxy(22,14+j);
		switch(prob1.T[j])
		{
		case 1:printf("-L'annee doit etre entre 1000 et 2017.");break;
		case 2:printf("-Le mois doit etre un entier entre 1 et 12.");break;
		case 3:printf("-Le jour doit etre strictement positif.");break;
		case 4:printf("-Le jour doit etre inferieur a 30.");break;
		case 5:printf("-Le jour doit etre inferieur a 31.");break;
		case 6:printf("-Le jour doit etre inferieur a 29.");break;
		case 7:printf("-Le jour doit etre inferieur a 28.");break;
		case 8:printf("-Le nom d'auteur doit contenir 2 mots separe par un point.");break;
		case 9:printf("-Le nom d'auteur doit etre forme uniquement par des lettres et un point.");break;
		case 10:printf("-Chaque mot du nom d'auteur doit commencer par une lettre majuscule.");break;
		case 11:printf("-Le titre doit contenir au moins 2 mots separe par des points.");break;
		case 12:printf("-Le titre doit etre forme uniquement par des lettres et un point.");break;
		case 13:printf("-Chaque titre  doit commencer par une lettre majuscule.");break;
		}}
		gotoxy(20,15+j); printf("Appuyez sur une touche pour recommencer");
		getch();
	}
	}while(prob1.b);
	if (i==n)
	{gotoxy(20,13);printf("Insertion termine ! Appuyez sur une touche pour continuer.");}
	else
	{gotoxy(20,13);printf("Appuyez sur une touche pour passer vers le livre suivant.");getch();}
	return unlivre;
	}

void insert()
{
	biblio=fopen(nomfich,"r");
	livre unlivre;
	layout();
	gotoxy(1,5);printf("Insertion->");
	gotoxy(50,3);printf("Insertion de livres");
	if (!biblio)
	{
		gotoxy(20,5);printf("Attention! Le fichier bibliotheque n'existe pas.");
		gotoxy(20,6);printf("Desole, vous ne pouvez pas ajouter des livres");
		gotoxy(20,8);printf("Appuyer sur une touche pour retourner.");
		fclose(biblio);
	}
	else
	{
		int n,i;
		fclose(biblio);
		biblio=fopen(nomfich,"a");
			gotoxy(20,5); printf("Saisir le nombre de livres a saisir : ");
			gotoxy(58,5);scanf("%d%c",&n,&er);
			for (i=0;n<=0;i++)
			{
				gotoxy(20,6+i);
			printf("Veuillez de saisir un nombre strictement positif : ");
			gotoxy(71,6+i);scanf("%d%c",&n,&er);
			}
		for (i=0;i<n;i++)
		{
			unlivre=saisir(i+1,n);
			fprintf(biblio,"%s\t%s\t%d\t%d\t%d\n",unlivre.auteur,unlivre.titre,unlivre.datep.jj,unlivre.datep.mm,unlivre.datep.aaaa);
		}
		fclose(biblio);
	}

}

void consult()
{
	biblio=fopen(nomfich,"r");
	layout();
	gotoxy(1,7);printf("Consultation->");
	gotoxy(50,3);printf("Consultation des livres");
	livre unlivre;
	if (!biblio)
	{
		gotoxy(20,5);printf("Attention: Le fichier bibliotheque n'existe pas.");
		gotoxy(20,6);printf("Desole, vous ne pouvez pas consulter des livres");
		gotoxy(20,8);printf("Appuyer sur une touche pour retourner.");
		fclose(biblio);
	}
	else 
	{	int dd;
		fscanf(biblio,"%d",&dd);
		if (feof(biblio))
	{
		
		gotoxy(20,5);printf("La bibliotheque est vide, veuillez inserer des livres.");
		gotoxy(20,7);printf("Appuyer sur une touche pour retourner.");
	}
	else
	{		
		int i;
			gotoxy(25,5);printf("Nom auteur");
			gotoxy(55,5);printf("Titre du livre");
			gotoxy(90,5);printf("Date de parution");
			for (int i=0;i<20;i++)
		{
			gotoxy(43,5+i); printf("%c",179);
		}
			for (int i=0;i<20;i++)
		{
			gotoxy(80,5+i); printf("%c",179);
		}
		gotoxy(19,6); for (int i=0;i<90;i++)  printf("%c",196);
		for (i=0;!feof(biblio);i++)
		{
			fscanf(biblio,"%s\t%s\t%d\t%d\t%d\n",unlivre.auteur,unlivre.titre,&unlivre.datep.jj,&unlivre.datep.mm,&unlivre.datep.aaaa);
			gotoxy(20,7+i);puts(unlivre.auteur);
			gotoxy(45,7+i);puts(unlivre.titre);
			gotoxy(91,7+i);printf("%02d/%02d/%02d",unlivre.datep.jj,unlivre.datep.mm,unlivre.datep.aaaa);
		}
		fclose(biblio);
		gotoxy(20,25);printf("Appuyer sur une touche pour continuer.");
		}}
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

void ec1(int a)
{
	cadre(1,1,80,1,WHITE,0);
	switch(a)
	{
case 1: textbackground(15);
		clrscr();
		layout();
        textbackground(9);
		textcolor(15);
		gotoxy(1,3);
		cprintf("Creation");
		break;
case 2: textbackground(WHITE);	
		clrscr();
		layout();
        textbackground(9);
		textcolor(15);
		gotoxy(1,5);
		cprintf("Insertion");
		
		break;

case 3: textbackground(WHITE);
		clrscr();
		layout();
        textbackground(9);
		textcolor(15);
		gotoxy(1,7);
		cprintf("Consultation");
		break;

case 4: textbackground(WHITE);
		clrscr();
		layout();
        textbackground(9);
		textcolor(15);
		gotoxy(1,9);
		cprintf("Suppression");
		break;

case 5: textbackground(WHITE);
		clrscr();
		layout();
        textbackground(9);
		textcolor(15);
		gotoxy(1,11);
		cprintf("Quitter");
		break;
	}
}

void suppr()
{
	layout();
	gotoxy(1,9);printf("Suppression->");
	gotoxy(50,3);printf("Suppression des livres");
	biblio=fopen(nomfich,"w");
	fclose(biblio);
	gotoxy(20,5);printf("Le fichier a ete supprime avec succes.");
	gotoxy(20,6);printf("Appuyer sur une touche pour continuer.");
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
					m=5;
				if (m>5)
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
	m14=m1(m14);
	switch(m14)
	{
	case 1: while (kbhit())
				getch;
		clrscr();
		textbackground(15);
		textcolor(0);
		clrscr();
		creation();
		getch();
		break;
	case 2: while (kbhit())
				getch;
		clrscr();
		textbackground(15);
		textcolor(0);
		clrscr();
		insert();
		getch();
		break;
	case 3: while (kbhit())
				getch;
		clrscr();
		textbackground(15);
		textcolor(0);
		clrscr();
		consult();
		getch();
		break;
	case 4: while (kbhit())
				getch;
		clrscr();
		textbackground(15);
		textcolor(0);
		clrscr();
		suppr();
		getch();
		break;
	case 5: while (kbhit())
				getch;
		car();
		clrscr();
		textbackground(15);
		textcolor(0);
		clrscr();
		gotoxy(50,12);
		printf("Au revoir ^_^");
		getch();
		break;
	}
}while (m14!=5);
}*/