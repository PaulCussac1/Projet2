
#include "operationFile.h"



// Initialiser la file
File *initialisation()
{
    File *file = malloc(sizeof(*file));
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    file->premier = NULL;

    return file;
}



//AJOUT D'UNE ACTIVITE PASSEE
void ajoutActivite(File *file, Processus activite)
{
    Element *nouveauElement = malloc(sizeof(*nouveauElement));
    if (file == NULL || nouveauElement == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveauElement->processus = activite;
    nouveauElement->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveauElement;
    }
    else /* La file est vide, notre élément est le premier */
    {
        file->premier = nouveauElement;
    }
}



//DEFILER LA FILE
Processus defiler(File *file)
{
    if (file == NULL)
    {
        printf("La file est vide");
        exit(EXIT_FAILURE);
    }

    Processus processus;

    // On vérifie si il y a quelque chose à défiler 
    if (file->premier != NULL)
    {
        Element *elementDefile = file->premier;

        processus = elementDefile->processus;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return processus;
}



// Longueur de la file
int longueurFile(File *file)
{
    int compteur = 1;
    Element *elementActuel = file->premier;
    while (elementActuel->suivant != NULL)
    {
        elementActuel = elementActuel->suivant;
        compteur ++;
    }
    return compteur;

}



//On recupere la priorite de l'element avec la top priorite

int recupTopPriorite(File *file){
    int priorite;
    int i; 
    int j;
    int min;
    int k;
    int n = longueurFile(file);
    int tab[n];
    int tmp;
    Processus p;
    for(k=0;k<n;k++)
    {
        p = defiler(file);
        tab[k] = p.priorite;
        ajoutActivite(file,p);
    }
    // tri par selection pour avoir la plus petite priorite en premier
    for(i=0;i<n; i++)
    {  
        for (j=i+1; j<n ;j++)
        {
            if (tab[i]> tab[j])
            {  
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        
        }
    }
    return tab[0];
}


//EXECUTION DU PROCESSUS

void step(File *file)
{
    int i;
    int duree, priorite;
    char nom[100];
    int n = longueurFile(file);
    int topProcessus = recupTopPriorite(file);
    Processus processus;
    for(i=0;i<n;i++)
    {
        processus = defiler(file);
        // si le processus correspond a celui avec la top priorite 
        if(processus.priorite == topProcessus)
        {  
            duree = processus.dureeExecution;
            priorite = processus.priorite;
            strcpy(nom,processus.nom);
            // on attend la duree d'execution du processus
            sleep(duree);  
            printf("le processus %s a été executé pendant %d secondes\n",processus.nom, processus.dureeExecution);
        }
        else{
            ajoutActivite(file,processus);
        }
    }

}



// iteration de step
void run(File *file)
{
    while(file->premier != NULL){
        step(file);
    }
    printf("Tous les processus ont été executé\n");
}   





