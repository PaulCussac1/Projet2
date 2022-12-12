#include "operationFile.h"


int main(int argc, char* argv[])
{
    
    File *file;
    file = initialisation();
    int duree;
    int priorite;
    int i;
    int n;
    char nom[100];
    Processus processus;
    printf("entrez le nombre de processus :\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("nom de votre processus numero %d:\n", i+1);
        scanf("%s",nom);
        printf("duree de ce processus: \n");
        scanf("%d",&duree);
        printf("priorité de ce processus :\n");
        scanf("%d",&priorite);
        
        strcpy(processus.nom,nom); 
        processus.dureeExecution = duree;
        processus.priorite = priorite;
        ajoutActivite(file,processus);
    }
    run(file);

    return 0;
}



