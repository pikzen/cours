#pragma once
#include "filtre_base.h"
#include "composant.h"
#include <vector>
#include <map>

class filtre_compose : public filtre_base
{
private:
    std::vector<counted_ptr<composant> > m_filters;
    std::map<unsigned int, std::pair<counted_ptr<consommateur>, unsigned int> > m_dict;
public:
    filtre_compose(unsigned int, unsigned int);
    void connecterComposants(counted_ptr<producteur>, unsigned int, counted_ptr<consommateur>,  unsigned int);
    void ajouterComposant(counted_ptr<composant>);
    void connecterSortieInterne(counted_ptr<producteur_base>, unsigned int, unsigned int);
    void connecterEntreeInterne(counted_ptr<consommateur_base>, unsigned int, unsigned int);
    void connecterEntree(const counted_ptr<flot>&, unsigned int);
    void calculer();
};
