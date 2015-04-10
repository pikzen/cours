#include "mixeur.h"
#include "volume_compose.h"
#include "mixer_element.h"
#include "imp_flot.h"
#include "counted_ptr.h"

/**
* Représente une suite de composants, avec chacun un volume
* entrées étant le nombre d'entrées de ce composant
* vols[] le volume de chaque composant
*/
mixeur::mixeur(unsigned int entrees, double vols[]) : 
	filtre_compose(entrees, 1)
{
	counted_ptr<filtre_base> elem(new mixer_element(entrees));

	// On assigne chaque sous-composant (modificateur de volume) à notre
	// mixer_element, qui se chargera de les chainer. On relie juste
	// les entrées au bon endroit.
	for (unsigned int i = 0; i < entrees; i++)
	{
		counted_ptr<volume_compose> vol(new volume_compose(vols[i]));
		ajouterComposant(vol);

		connecterEntreeInterne(vol, i, 0);
		connecterComposants(vol, 0, elem, i);
	}

	ajouterComposant(elem);
	connecterSortieInterne(elem, 0, 0);
}