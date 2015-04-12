# Système - TP C

### Charger dynamiquement une bibliothèque
Pour charger une librairie, il faut inclure `dlfcn.h`. Il faut la bibliothèque `ld.so` pour cela.

**dynload_v2.c**  
```
// Charger la bibliothèque mathématique (libm.so)
// et calculer racine carrée de 2

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef
double (* RealFunction)(double);

int
main(int argc, char * argv[])
{
  // ouverture de la bibliothèque mathématique
  void * handle = dlopen("libm.so", RTLD_LAZY);
  if (handle == NULL) {
    fprintf(stderr, "%s\n", dlerror());
    exit(EXIT_FAILURE);
  }

  dlerror();    /* Clear any existing error */
  
  printf("Sélectionnez une fonction à charger: ");
  char func[16];
  scanf("%s", func);

  // chercher la fonction sqrt dans la bibliothèque
  RealFunction root =  dlsym(handle, func);

  char * error = dlerror();
  if ((error) != NULL)  {
    // erreur : fonction non trouvée
    fprintf(stderr, "%s\n", error);
    exit(EXIT_FAILURE);
  }
  // tout est correct
  printf("Saisir un nombre réel >= 0 : ");
  double x;
  scanf("%lf", &x);
  printf("%s de %lf = %lf\n",func, x, root(x));
  dlclose(handle);
  exit(EXIT_SUCCESS);
}
```

### Fabriquer une bibliothèque dynamique  
**calcul.c** :   
```
double plus (double first, double second) {
    return first + second;
}

double moins(double first, double second) {
    return first - second;
}

double mult (double first, double second) {
    return first * second;
}
```

**Table des symboles** :  
```
Symbol table '.dynsym' contains 15 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     ...
     7: 00000000000006c5    44 FUNC    GLOBAL DEFAULT   11 plus
     8: 0000000000201030     0 NOTYPE  GLOBAL DEFAULT   21 _edata
     9: 0000000000201038     0 NOTYPE  GLOBAL DEFAULT   22 _end
    10: 00000000000006f1    44 FUNC    GLOBAL DEFAULT   11 moins
    11: 000000000000071d    44 FUNC    GLOBAL DEFAULT   11 mult
    ...
```

**main_calcul.c, première version**:  
```
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef double (* fn)(double, double);

void afficher   (char [], fn, double, double);

/*------------------------------------------------------------
    Programme principal
  -----------------------------------------------------------*/
int main(int argc, char * argv[])
{
    int funcVal = -1;
    int a, b;
    char* func;

    printf("=======================================\n");
    printf("= Sélectionnez la fonction à utiliser =\n");
    printf("=======================================\n");
    printf(" 1    plus\n");
    printf(" 2    moins\n");
    printf(" 3    mult\n");

    scanf("%d", &funcVal);
    if (funcVal <= 0 || funcVal >= 4) {
        printf("%d ne fait référence à aucune fonction. Exiting.", funcVal);
        exit(EXIT_SUCCESS);
    }

    if      (funcVal == 1) { func = "plus" ;}
    else if (funcVal == 2) { func = "moins";}
    else if (funcVal == 3) { func = "mult" ;}

    void* handle = dlopen("./libcalcul.so", RTLD_LAZY);
    if (handle == NULL) {
        fprintf(stderr, "Could not load library.\n");
        exit(EXIT_FAILURE);
    }

    dlerror();
    fn loaded_func = dlsym(handle, func);
    char* error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    printf("Donner deux nombres entiers: ");
    scanf("%d%d", &a, &b);

    afficher("Fonction: ", loaded_func, a, b);
    
    return 0;
}

/*------------------------------------------------------------
    Afficher le résultat
  -----------------------------------------------------------*/
void afficher(char txt[], fn calculer, double x, double y)
{
    printf("%-10s de %2lf et %2lf : %4lf\n", txt, x, y, calculer(x, y));
}
```

**main_calcul.c, deuxième version** :   
```
#include "afficher.h"

int main(int argc, char** argv)
{
    ...
    double result = loaded_func(a, b);
    afficher(func, a, b, result);
    ...
}

void afficher(char txt[], double x, double y, double result)
{
    printf("%-10s de %2lf et %2lf : %4lf\n", txt, x, y, result);
}
```

**calcul.c, deuxième version** :  
```
#include "afficher.h"

double plus (double first, double second) {
    afficher("plus  : ", first, second, first + second);
    return first + second;
}

double moins(double first, double second) {
    afficher("moins : ", first, second, first - second);
    return first - second;
}

double mult (double first, double second) {
    afficher("mult  : ", first, second, first * second);
    return first * second;
}
```

