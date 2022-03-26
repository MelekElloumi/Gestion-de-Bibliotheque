typedef struct date
{
	int jj;
	int mm;
	int aaaa;
} dat;

typedef struct livre
{
	int id_liv;
	char titre[15];
	char nom_auteur[15];
	int nbre_exp1;
	struct livre *suivant;
} liv;

typedef struct adherant
{
	int id_ad;
	char nom[15];
	char prenom[15];
	int nbre_liv_emp;
	struct adherant*suivant;
} adr;

typedef struct emprunter
{
 int code_emp;
 liv* code_livre;
 adr* code_adherant;
 dat* date_deb_pret;
 dat* date_fin_pret;
 struct emprunter*suivant;
}emp;

