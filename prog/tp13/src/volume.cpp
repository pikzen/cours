#include "volume.h"
#include "imp_flot.h"

/**
* Permet de modifier le volume en le multipliant avec un signal constant
*/
volume::volume(double factor) :
    filtre_base(1, 1),
    m_mul(),
    m_vol(factor)
{
    // On relie simplement a un multiplicateur le flux de données et un
    // multiplicateur de données
    m_mul.connecterEntree(m_vol.getSortie(0), 0);
    m_mul.connecterSortie(m_output[0], 0);
}

/**
* Calcule la prochaine valeur (volume diminué)
*/
void volume::calculer()
{
    if (!yaDesEchantillons()) return;

    m_vol.calculer();
    m_mul.calculer();
}

/**
* Connecte une entrée au composant en lui appliquant le volume
*/
void volume::connecterEntree(const counted_ptr<flot>& fl, unsigned int in)
{
    m_mul.connecterEntree(fl, 1);
    consommateur_base::connecterEntree(fl, in);
}