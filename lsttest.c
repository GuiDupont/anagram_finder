# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

/* Element est un element de la liste que l'on peut dupliquer autant de fois que voulu */

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

/* on peut controler l'ensemble de la liste avec Liste */

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));
    
    if (!liste || !element)
        return (NULL);
        
    element->nombre = 0; /* nombre est mis a 0 */
    element->suivant = NULL; /* suivant pointe vers NULL */
    liste->premier = element; 
    
    return liste;
}

void    insertion(Liste *liste, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (!liste || !nouveau)
        return ;
    nouveau->nombre = nvNombre;
    
    nouveau->suivant = liste->premier; 
    liste->premier = nouveau;
}

void    afficherListe(Liste *liste)
{
    if (!liste)
        return ;
        
    Element *actuel = liste->premier;
    
    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

int main()
{
    Liste *maListe = initialisation();
    
    insertion(maListe, 4);
    insertion(maListe, 8);
    
    afficherListe(maListe);
    
    return 0;
}
