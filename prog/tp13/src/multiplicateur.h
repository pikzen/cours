#pragma once

#include "filtre_base.h"
#include "counted_ptr.h"

class multiplicateur : public filtre_base
{
private:
    counted_ptr<flot> m_input[2];
    counted_ptr<flot> m_output;
    
public:
    multiplicateur();
    unsigned int nbEntrees() const;
    unsigned int nbSorties() const;

    const counted_ptr<flot>& getSortie(unsigned int sortie) const;
    const counted_ptr<flot>& getEntree(unsigned int entree) const;

    void connecterEntree(const counted_ptr<flot>& fl, unsigned int entree);
    void connecterSortie(const counted_ptr<flot>&, unsigned int);

    bool yaDesEchantillons() const;

    void calculer();
};
