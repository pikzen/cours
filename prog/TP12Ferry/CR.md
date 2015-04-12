# Question 1

**Méthodes virtuelles** :  
Ces méthodes devront être rédéfinies dans chaque classe les héritant car leur résultat change en fonction de la classe
 * Le destructeur, puisque certains attributs seront différents selon les classes
 * calculerTarif() puisque le tarif est différent selon le type de Véhicule
 * afficher() puisque certains attributs sont différents

**Méthodes non virtuelles** :  
 * getLongueur() et getPassagers() font reférence à des attributs qui seront toujours présents

**Opérateur d'affichage** :  
On passe en paramètre de operator<< un objet de type Vehicule. Ainsi, tous les classes en héritant pourront être affichées. On peut également le déclarer dans Vehicule pour utiliser uniquement les propriétés communes à tous les véhicules.


