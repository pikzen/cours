# Algorithmique - TP  
## TP 1  
### Tri par insertion  
**Cas: Meilleurs cas**:   
Coefficient a : 0.000003  
Valeurs d'itération:        

    int taille_init = 15000000;
    int taille_incr = 15000000;
    int taille_fin  = 150000000;

Complexité apparente: `n`

[best_case](best_case.png)

**Cas: pire cas possible** :   
Coefficient a : 0.0000004
[worst_case](worst_case.png)  
Valeurs d'itération

    int taille_init = 10000;
    int taille_incr = 10000;
    int taille_fin  = 100000;

Complexité apparente: `n²`
**Cas: valeurs aléatoires**:  
Coefficient a : 0.000000205
[random_case](random_case.png)  

    int taille_init = 10000;
    int taille_incr = 10000;
    int taille_fin  = 100000;

Complexité apparente: `n²`

#### Calcul sur 66 millions de français   
**Meilleur cas**: 0.000003 * 66000000 = 198ms (3 minutes 18 secondes)  
**Pire cas**: 0.0000004 * 66000000² = 174 240 secondes, soit environ 2 jours
**Valeurs aléatoires**: 0.000000205*66000000² : 89298 secondes, environ 1 jour

### Tri fusion
**Cas: meilleur cas possible**:  
Coefficient a : a = 0.000140;  
[best_case_fusion](best_case_fusion.png)

Complexité apparente: linéaire

**Cas: pire cas possible**:
Coefficient a : 0.000130;
[worst_case_fusion](worst_case_fusion.png)

Complexité apparente: linéaire

**Cas: valeurs aléatoires**:
Coefficient a : 0.00025
[random_case_fusion](random_case_fusion.png)

Complexité apparente: linéaire

#### Calcul sur 66 millions de français
**Meilleur cas**: 0.000140*66000000 = 9.240s
**Pire cas**: 8.580s
**Valeurs aléatoires**: 16.5s

#### Conclusion

La complexité logarithmique est une belle invention, et est à utiliser dans la plupart des cas. 

## Permutations

`permutation` trouve toutes les permutations de caractères possibles parmis une chaine de caractères.
La complexité semble être factorielle. Pour 26 caractères, il y aura 26! permutations.

Une approximation de la courbe peut être y = factorial(x)*0.0005
On peut donc esperer calculer l'intégralité après 50.000 fois l'age de l'univers.