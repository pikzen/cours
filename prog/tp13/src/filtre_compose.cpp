#include "filtre_compose.h"

filtre_compose::filtre_compose(unsigned int in, unsigned int out) :
    filtre_base(in, out),
    m_filters(),
    m_dict()
{
}

void filtre_compose::ajouterComposant(counted_ptr<composant> composant)
{
    m_filters.push_back(composant);
}

void filtre_compose::connecterEntree(const counted_ptr<flot>& cmp, unsigned int in)
{
    if (m_dict.count(in) < 0) return;

    m_dict[in].first->connecterEntree(cmp, m_dict[in].second);

    consommateur_base::connecterEntree(cmp, in);
}

void filtre_compose::connecterEntreeInterne(counted_ptr<consommateur_base> cmp, unsigned int in, unsigned int inCmp)
{
    m_dict[in] = std::pair<counted_ptr<consommateur>, unsigned int>(cmp, inCmp);
}

void filtre_compose::connecterSortieInterne(counted_ptr<producteur_base> cmp, unsigned int out, unsigned int outCmp)
{
    m_output[out] = cmp->getSortie(outCmp);
}

void filtre_compose::connecterComposants(counted_ptr<producteur> prod, unsigned int outProd,
                                         counted_ptr<consommateur> cons, unsigned int consProd)
{
    cons->connecterEntree(prod->getSortie(outProd), consProd);
}
void filtre_compose::calculer()
{
    if (!yaDesEchantillons()) return;

    for (std::vector<counted_ptr<composant> >::iterator i = m_filters.begin(); i < m_filters.end(); i++)
        (*i)->calculer();
}