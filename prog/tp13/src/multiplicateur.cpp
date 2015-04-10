#include "multiplicateur.h"
#include "imp_flot.h"

multiplicateur::multiplicateur() :
    m_output(new imp_flot)
{
}

unsigned int multiplicateur::nbEntrees() const
{
    return 2;
}

unsigned int multiplicateur::nbSorties() const
{
    return 1;
}

const counted_ptr<flot>& multiplicateur::getSortie(unsigned int sortie) const
{
    return m_output;
}

const counted_ptr<flot>& multiplicateur::getEntree(unsigned int entree) const
{
    return m_input[entree];
}

void multiplicateur::connecterEntree(const counted_ptr<flot>& fl, unsigned int entree)
{
    m_input[entree] = fl;
}

void multiplicateur::connecterSortie(const counted_ptr<flot>& fl, unsigned int sortie)
{
    m_output = fl;
}

bool multiplicateur::yaDesEchantillons() const
{
    return !(m_input[0]->vide() || m_input[1]->vide());
}

void multiplicateur::calculer()
{
    m_output->inserer(m_input[0]->extraire() * m_input[1]->extraire());
}
