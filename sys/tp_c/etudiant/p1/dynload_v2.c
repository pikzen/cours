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
  RealFunction root = dlsym(handle, func);

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
