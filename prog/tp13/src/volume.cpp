#include "volume.h"
#include "imp_flot.h"

volume::volume(double factor) :
    filtre_base(1, 1),
    m_vol(factor)
{
    m_mul.connecterEntree(m_vol.getSortie(0), 1);
    m_mul.connecterSortie(this->getSortie(0), 0);
}

void volume::calculer()
{
    m_vol.calculer();
    m_mul.calculer();
}
