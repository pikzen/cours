#include "volume_compose.h"
#include "counted_ptr.h"
#include "signal_constant.h"
#include "multiplicateur.h"
#include <iostream>

/**
* Répresente un facteur de volume construit à partir d'un filtre composé
* NOTE: vol = 0.5 : -3dB
*/
volume_compose::volume_compose(double vol) :
	filtre_compose(1, 1)
{
	counted_ptr<signal_constant> sig(new signal_constant(vol));
	counted_ptr<multiplicateur> mul(new multiplicateur());

	ajouterComposant(sig);
	ajouterComposant(mul);

	connecterComposants(sig, 0, mul, 0);
	connecterSortieInterne(mul, 0, 0);
	connecterEntreeInterne(mul, 0, 1);
}