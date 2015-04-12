# Bases de données

Stockage persistant, qui survit à l'extinction des machines. Il survit également aux crashs, possède une certaine atomicité, etc.

### Données partagées

Données accessibles par de nombreux utilisateurs, depuis de nombreux systèmes.

### Données régulières

Les données sont organisées en *colonnes*. Chaque colonne correspond à un attribut (nom, âge, adresse). Une fois définies, ces données sont figées dans un **schéma**
Ensuite, chaque *ligne* correspond à une entrée dans la table.

### Possibilité de mise à jour

Changer le **schéma**: rarement
Changer le **contenu**: aussi souvent que l'on veut

### Abstraction

Par rapport à la représentation physique, à l'ensemble du schéma et par rapport à l'application

### Données en masse

Les bases de données permettent de traiter de très gros ensembles de données de façon efficace et de scaling

### Notion de relation et de table

**Relation** : Ensemble de n-uplets conformes à un schéma
    {{x1; ...; xn}; ...; {z1; ...; zn}}
Pas d'ordre et pas de multiplicité. Une relation est une propriété de la table.

### Opérations relationnelles

Ce sont des opérations *ensemblistes* sur des tables calculées et/ou stockées. Ces opérations sont approximées en SQL.
**Opérations binaires** : doivent être appliquées sur deux mêmes schémas
    ex: INTERSECT, UNION, MINUS
**Opérations unaires**: s'appliquent sur un jeu de données
    SELECT

