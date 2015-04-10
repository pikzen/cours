#pragma once
#include "filtre_base.h"
#include "composant.h"
#include <vector>

class filtre_compose : public filtre_base
{
private:
    std::vector<composant> m_filters;
    std::vector<counted_ptr<flot>> m_input;
    std::vector<counted_ptr<flot>> m_output;
    unsigned int m_max_input;
    unsigned int m_max_output;

public:
    filtre_compose(unsigned int, unsigned int);
    void connectAtEnd(const composant);
    void connectComposants(composant out, unsigned int outNum, composant in,  unsigned int inNum);
    void calculer();

    virtual unsigned int nbEntrees() const = 0;
    virtual unsigned int nbSorties() const = 0;

    virtual const counted_ptr<flot>& getSortie(unsigned int) const = 0;
    virtual const counted_ptr<flot>& getEntree(unsigned int) const = 0;

    virtual void connecterEntree(const counted_ptr<flot>&, unsigned int) = 0;
    virtual bool yaDesEchantillons() const = 0;
}
