#include "volume.h"
#include "imp_flot.h"

volume::volume(double factor) :
    m_vol(factor),
    m_output(new imp_flot)
{
    m_mul.connecterEntree(m_vol.getSortie(0), 1);
    m_mul.connecterSortie(m_output, 0);
}

void volume::connecterSortie(const counted_ptr<flot>& fl, unsigned int out)
{
    m_output = fl;
    m_mul.connecterSortie(fl, 0);
}

unsigned int volume::nbEntrees() const
{
    return 1;
}

unsigned int volume::nbSorties() const
{
    return 1;
}

const counted_ptr<flot>& volume::getSortie(unsigned int num) const
{
    return m_output;
}

const counted_ptr<flot>& volume::getEntree(unsigned int num) const
{
    return m_input;
}

void volume::connecterEntree(const counted_ptr<flot>& fl, unsigned int num)
{
    m_input = fl;
    m_mul.connecterEntree(fl, 0);
}

bool volume::yaDesEchantillons() const
{
    return !m_input->vide();
}

void volume::calculer()
{
    m_vol.calculer();
    m_mul.calculer();
}
