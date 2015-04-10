#include "mixer_element.h"
#include "filtre_base.h"
#include "operation_binaire.h"
#include <functional>

/**
* Représente un élément de mixeur, formé de plusieurs composants
* Simplifie la création de n-1 multiplicateurs pour relier les composants ensemble
* entrées est le nombre d'entrées de cet élément
*/
mixer_element::mixer_element(unsigned int entrees) : 
	filtre_compose(entrees,1)
{
	assert(entrees >= 2);

	if(entrees == 2)
	{
		// Si on à juste deux entrées, on peut simplement créer une opération binaire +
		// et l'appliquer
		// NOTE: Techniquement, il n'y a pas de raison de séparer ce cas de l'autre, une 
		// simple modification de l'algorithme le ferait marcher dans tous les cas
		// Pas le temps.
		counted_ptr<filtre_base> elem(new operation_binaire<std::plus<double> >());
		ajouterComposant(elem);
		connecterEntreeInterne(elem, 0, 0);
		connecterEntreeInterne(elem, 1, 1);
		connecterSortieInterne(elem, 0, 0);
	}
	else
	{
		// Sinon, on recréé un multiplicateur pour l'appliquer à tous les éléments en cascade
		// Appels récursifs du constructeur.
		counted_ptr<filtre_base> elem(new operation_binaire<std::plus<double> >());
		counted_ptr<filtre_base> elemMul(new mixer_element(entrees - 1));
		ajouterComposant(elem);
		ajouterComposant(elemMul);
		connecterEntreeInterne(elem, 0, 0);
		connecterComposants(elemMul, 0, elem, 1);
		connecterSortieInterne(elem, 0, 0);
		for(unsigned int i = 1; i < entrees; i++)
		{
			connecterEntreeInterne(elemMul, i, i-1);
		}
	}
}