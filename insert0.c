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
	/* Insertion de l'élément au début de la liste */
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
    Liste *l = &maListe;
    insertion(l, 3);
    insertion(l, 8);
    insertion(l, 2);
    afficherListe(maListe);

    return 0;
}
