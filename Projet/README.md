
# Ordonnancement de processus

Ce projet est un simulateur d'ordonnanceur dont le but est de modéliser le
fonctionnement des ordonnanceurs modernes qui utilisent des files. Les processus 
seront définis par des structures dont les caractéristiques (nom,durée,priorité) 
seront rentrés par l'utilisateur. L'ordonnanceur executera ainsi chaque processus 
selon sa priorité et sa durée d'exécution.


## Compilation et éxécution
Pour compiler ce projet, allez dans le terminal et tapez la commande 

```bash
  make all
```
Puis pour éxécuter, tapez
```bash
  ./prog
```
## Description des fonctions
Nous avons groupé nos fonctions dans un fichier appelé "operationFile", qui contient toutes
les fonctions necéssaires pour le traitement des files. 

Nous avons commencé par créer la structure "Processus" dont les caractéristiques 
sont: nom, duree, priorite. Nous avons après créer le type "File" qui contiendra des 
éléments de type "Processus" et qui nous permettera de modéliser le fonctionnement
d'ordonnanceur.

La première fonction "initialisation()", qui prend en paramètre une file, permert 
de retourner une file initialisée, ce qui équivaut au premier pointeur qui pointe 
vers NULL.

La procédure "ajoutActivite()" permet d'enfiler des processus dans notre file. 
Nous créeons  d'abord de l'espace pour notre élément grace à la fonction "malloc".
On étudie après le cas où la file serait vide, notre élement serait donc le premier.
Dans le cas contraire, on se positionne à la fin de notre file pour ajouter notre processus.

Par le même principe, nous définissons la fonction "defiler()", qui prend une file comme
argument et permet de retourner un processus, et qui comme son nom l'indique
nous permet de défiler nos processus.

La fonction "longueurFile()" permet de calculer la longueur de la file en la parcourant
grace à une boucle while.

La fonction "recupTopPriorite" aide à récupérer les caractéristiques "priorite" 
de nos processus et de les stocker dans un tableau. Nous procéderons ensuite à trier 
ce tableau dans l'ordre croissant grace à un tri par sélection, afin de récuperer la priorité 
minimale, qui sera la première à être executée par notre ordonnanceur.
 
La procédure "step()" nous permet d'executer nos processus un par un par ordre
de priorite. Nous nous aidons d'une boucle "for" pour défiler à chaque fois un 
processus et comparer sa priorité avec "recupTopPriorite". on procède à executer 
le processus correspondant et à enfiler le reste.

Notre dernière procédure "run()" fait des itérations de step pour modéliser le role
de l'ordonnanceur. Nous nous aidons d'une boucle while, et nous affichons que tous les
processus ont été executés à la fin.




## Auteurs

- [@PaulCussac1](https://www.github.com/PaulCussac1)
- [@Aminachib](https://www.github.com/Aminachib)
