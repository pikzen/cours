#include "../include/pluginmanager.h"
#include <dlfcn.h>
#include <stdio.h>
#include <dirent.h>

extern "C" {

  //------------------------------------------------------------------------
  // les constantes
  //------------------------------------------------------------------------
  // suffixe des bibliothèques de plugin
  char plugin_suffix[] = "_plugin.so";
  // nom de la fonction d'initialisation d'un plugin
  char initfunc_name[] = "init_";

  //------------------------------------------------------------------------
  // les types (À COMPLÉTER)
  //------------------------------------------------------------------------

  // type des éléments de la liste des plugins
  struct simply_linked_list_elem{
    plugin_descriptor descriptor;
    struct simply_linked_list_elem* next;
  };

  struct simply_linked_list {
    simply_linked_list_elem* first;
    int count;
  };

  struct plugin_manager_t {
    simply_linked_list* plugins;
  };
  // le manager

  typedef 
  int (* init_plugin)(plugin_manager*);

  //------------------------------------------------------------------------
  // fonctions destinées à l'application
  //------------------------------------------------------------------------

  // initialiser un manager
  plugin_manager *
  make_manager()
  {
    simply_linked_list* plugins;
    plugins = (struct simply_linked_list*) malloc(sizeof(struct simply_linked_list));

    plugin_manager* manager;
    manager = (struct plugin_manager_t*) malloc(sizeof(struct plugin_manager_t));

    manager->plugins = plugins;
    manager->plugins->first = NULL;

    return manager;
  }

  // libérer les ressources du gestionnaire
  void
  release_manager(plugin_manager * pm)
  {
    simply_linked_list_elem* iter;
    iter = pm->plugins->first;
    simply_linked_list_elem* cpy;


    while (iter != NULL) {
      cpy = iter;
      iter = iter->next;

      free(cpy);
    }

    free(pm->plugins);

    free(pm);
  }

  // découvrir les plugins ; résultat = nombre de plugins
  unsigned int
  discover_plugins(const char dirname[], plugin_manager * pm)
  {
    DIR* directory = opendir(dirname);
    dirent* handle;
    unsigned int plugins_loaded = 0;
    while ((handle = readdir(directory)) != NULL)
    {
      if (strstr(handle->d_name, plugin_suffix) != NULL)
      {
        char plugin_path[255];
        strcpy(plugin_path, dirname);
        strcat(plugin_path, handle->d_name);

        void * so_handle = dlopen(plugin_path, RTLD_LAZY);
        // Impossible de charger la librairie, on passe au prochain.
        if (so_handle == NULL) {
          char* error = dlerror();
          fprintf(stderr, "Could not open a handle to %s, skipping.\n", plugin_path);
          fprintf(stderr, "Reason : %s\n", error);
          continue;
        }

        init_plugin init = (init_plugin)dlsym(so_handle, initfunc_name);

        char* error = dlerror();
        if (error != NULL) {
          fprintf(stderr, "Could not find an %s function in the module, skipping.\n", error);
          continue;
        }
        plugins_loaded++;

        init(pm);
      }
    }

    return plugins_loaded;
  }

  // chercher et renvoyer le plugin de numéro donné
  plugin_descriptor *
  get_plugin(plugin_manager * pm, unsigned int plugin_number)
  {
    unsigned int counter = 0;
    int overflow = 0;
    simply_linked_list_elem* iter;
    iter = pm->plugins->first;

    while (counter < plugin_number && overflow == 0)
    {
      if (iter == NULL)
        overflow = 1;

      iter= iter->next;
      counter++;
    }

    return &iter->descriptor;
  }

  // afficher le menu des plugins disponibles
  void
  display_menu(plugin_manager * pm)
  {
    int counter = 0;
    simply_linked_list_elem* iter;
    iter = pm->plugins->first;

    printf("=====================================\n");
    printf("=   Liste de plugins enregistrés    =\n");
    printf("=====================================\n");

    do
    {
      if (iter != NULL)
      {
        printf("%d - %s - %s\n", counter, iter->descriptor.m_name, iter->descriptor.m_description);
      }
      iter = iter->next;
      counter++;
    }
    while (iter != NULL);
  }

  //------------------------------------------------------------------------
  // fonction destinée aux plugins
  //------------------------------------------------------------------------

  // enregistrer un plugin
  void
  register_plugin(plugin_manager * pm,
		  const char filter_name[],
		  const char filter_description[],
		  filter_function the_filter)
  {
    plugin_descriptor descriptor;
    descriptor.m_name        = filter_name;
    descriptor.m_description = filter_description;
    descriptor.m_filtre      = the_filter;

    simply_linked_list_elem* newElem;
    newElem = (struct simply_linked_list_elem*) malloc(sizeof(struct simply_linked_list_elem));
    newElem->descriptor = descriptor;
    newElem->next = NULL;

    simply_linked_list_elem* last = pm->plugins->first;

    if (pm->plugins->first == NULL)
      pm->plugins->first = newElem;
    else 
    {
      while (last->next != NULL)
      {
        last = last->next;
      }

      last->next = newElem;
    }

    printf("Registering plugin: %s - %s\n", filter_name, filter_description);
  }
};
