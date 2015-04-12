#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "afficher.h"

typedef double (* fn)(double, double);

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

    void* handle = dlopen("./libcalcul_v2.so", RTLD_LAZY);
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

    double result = loaded_func(a, b);
    afficher(func, a, b, result);
    
    return 0;
}

/*------------------------------------------------------------
    Afficher le résultat
  -----------------------------------------------------------*/
void afficher(char txt[], double x, double y, double result)
{
    printf("%-10s de %2lf et %2lf : %4lf\n", txt, x, y, result);
}