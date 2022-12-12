
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 


typedef struct Processus Processus;
typedef struct Element Element;
typedef struct File File;

//Processus
struct Processus
{
    char nom[100];
    int dureeExecution;
    int priorite;
};


//File
struct Element
{
    Processus processus;
    Element *suivant;
};

struct File
{
    Element *premier;
};






File *initialisation();
void ajoutActivite(File *file, Processus activite);
Processus defiler(File *file);
int longueurFile(File *file);
int recupTopPriorite(File *file);
void step(File *file);
void run(File *file);