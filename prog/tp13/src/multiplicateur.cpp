#include "multiplicateur.h"
#include "imp_flot.h"

multiplicateur::multiplicateur() :
    filtre_base(2, 1)
{
}

void multiplicateur::calculer()
{
	if (!yaDesEchantillons()) return;
    m_output[0]->inserer(m_input[0]->extraire() * m_input[1]->extraire());
}
