#include "filtre_compose.h"

filtre_compose::filtre_compose(unsigned int in, unsigned int out) :
    m_max_input(in),
    m_max_output(out)
{

}

void filtre_compose::connectAtEnd(const counted_ptr<filtre>& fl, const int[] on_in, const int[] on_out)
{
    if (m_filters.size() == 0)
    {
        m_filters.push_back(fl);
        for (int i = 0; i < fl.nbEntrees(); i++)
            fl.connecterEntree(m_input.get(i), on_in[i]);

        return;
    }

    // Récupère les sorties du dernier composant et essaie de les connecter
    // au nouveau composant.
    counted_ptr<flot> last = m_filters.back();
    if (last.nbSorties() > fl.nbEntrees())
    {
        // panic
    }

    for (int i = 0; i < last.nbSorties(); i++)
        fl.connecterEntree(last.getSortie(i), on_in[i]);

    if (fl.nbSorties() > m_max_output)
    {
        // panic
    }

    for (int i = 0; i < fl.nbSorties(); i++)
        m_output[on_out[i]] = fl.getSortie(i);

    m_filters.push_back(fl);
}

void filtre_compose::connectComposants(composant& out, unsigned int outNum,
                                       composant& in, unsigned int inNum)
{
    in.connecterEntree(out.getSortie(outNum), inNum);
}

void filtre_compose::calculer()
{
    for (int i = 0; i < m_filters.size(); i++)
        m_filters[i].calculer();
}

bool filtre_compose::yaDesEchantillons() const
{
    for (int i = 0; i < m_input.size(); i++)
        if (m_input[i].vide()) return false;

    return true;
}

void filtre_compose::connecterEntree(const counted_ptr<flot>& fl, unsigned int in)
{
    m_input[in] = fl;
}

const counted_ptr<flot>& filtre_compose::getEntree(unsigned int in) const
{
    return m_input[in];
}

const counted_ptr<flot>& filtre_compose::getSortie(unsigned int out) const
{
    return m_output[out];
}

unsigned int filtre_compose::nbEntrees() const
{
    return m_max_input;
}

unsigned int filtre_compose::nbSorties() const
{
    return m_max_output;
}
