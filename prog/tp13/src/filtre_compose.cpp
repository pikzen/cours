#include "filtre_compose.h"
#include <iostream>
#include <cstdlib>

/**
* Filtre composé de plusieurs composants reliés les uns les autres.
* in représente le nombre d'entrées
* out représente le nombre de sorties
*/
filtre_compose::filtre_compose(unsigned int in, unsigned int out) :
    filtre_base(in, out),
    m_filters(),
    m_dict()
{
}

/**
* Ajoute un composant dans le filtre
*/
void filtre_compose::ajouterComposant(counted_ptr<composant> composant)
{
    m_filters.push_back(composant);
}

/**
* Connecte un flot à une entrée du filtre
*/
void filtre_compose::connecterEntree(const counted_ptr<flot>& cmp, unsigned int in)
{
    if (m_dict.count(in) > 0)
        m_dict[in].first->connecterEntree(cmp, m_dict[in].second);

    consommateur_base::connecterEntree(cmp, in);
}

/**
* Connecte une entrée d'un composant interne à une entrée du filtre
* cmp est le composant interne
* in l'entrée du filtre
* inCmp l'entrée du composant
*/
void filtre_compose::connecterEntreeInterne(counted_ptr<consommateur_base> cmp, unsigned int in, unsigned int inCmp)
{
    m_dict[in] = std::pair<counted_ptr<consommateur>, unsigned int>(cmp, inCmp);
}

/**
* Connecte une sortie d'un composant externe à une sortie du filtre
* cmp est le composant externe
* in la sortie du filtre
* inCmp la sortie du composant
*/
void filtre_compose::connecterSortieInterne(counted_ptr<producteur_base> cmp, unsigned int out, unsigned int outCmp)
{
    m_output[out] = cmp->getSortie(outCmp);
}

/**
* Connecte deux composants internes ensemble.
*/
void filtre_compose::connecterComposants(counted_ptr<producteur> prod, unsigned int outProd,
                                         counted_ptr<consommateur> cons, unsigned int consProd)
{
    cons->connecterEntree(prod->getSortie(outProd), consProd);
}

/**
* Calcule les valeurs à sortir en traversant tous les composants et en appliquand les filtres.
*/
void filtre_compose::calculer()
{
    if (!yaDesEchantillons()) {
        return;
    }

    for (std::vector<counted_ptr<composant> >::iterator i = m_filters.begin(); i < m_filters.end(); i++) 
    {
        (*i)->calculer();
    }
}