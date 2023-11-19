#include <stdio.h>
#include <stdlib.h>
typedef struct Element Element;
struct Element{
	int val;
	Element *suivant;
};

typedef Element* Liste;

Liste initialisation(){
	Liste liste;
	Element *element;
	element = (Element*)malloc(sizeof(Element));
	element->val = 0;
	element->suivant = NULL;
	liste = element;
	return liste;
}

void insertion(Liste **liste, int nvNombre){
	Element *nouveau;
	nouveau = (Element*)malloc(sizeof(Element));
	nouveau->val = nvNombre;
	nouveau->suivant = *liste;
	*liste = nouveau;
}

void insertionMilieudeListe(Liste **liste, int nvNombre,int pos){
	int i;
	Element *nouveau = (Element*)malloc(sizeof(Element));
	Element *courant = (Element*)malloc(sizeof(Element));
	courant = *liste;
	for(i=1; i<pos-1; i++)
		courant = courant->suivant;
	nouveau->val = nvNombre;
	nouveau->suivant = courant->suivant;
	courant->suivant = nouveau;
}

void suppression(Liste **liste){
	Element *aSupprimer = *liste;
	*liste = aSupprimer->suivant;
	free(aSupprimer);
}

void SuppressionMilieuListe(Liste **liste, int pos){
	int i;
	Element *courant = *liste;
	for (i=1; i<pos-1; i++)
		courant = courant->suivant;
	if (courant->suivant != NULL){
		Element *aSupprimer = courant->suivant;
		courant->suivant = courant->suivant->suivant;
		free(aSupprimer);
	}
}

void detruire (Liste **liste){
	Element *actuel = *liste;
	while (actuel != NULL){
		actuel = actuel->suivant;
		suppression(liste);
	}
	free(actuel);
}

void afficherListe(Liste liste){
	Element *actuel = liste;
	while(actuel != NULL){
		printf("%d ->", actuel->val);
		actuel = actuel->suivant;
	}
	printf("NULL\n");
}

int main()
{
    Liste maListe = initialisation();
    insertion(&maListe, 4);
    insertion(&maListe, 8);
    insertion(&maListe, 15);
    suppression(&maListe);
    insertionMilieudeListe(&maListe, 16, 2);
    SuppressionMilieuListe(&maListe, 2);
    afficherListe(maListe);
    detruire(&maListe);
    afficherListe(maListe);

    return 0;
}
