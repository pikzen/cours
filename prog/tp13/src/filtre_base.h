#pragma once

#include "filtre.h"
#include "counted_ptr.h"
#include "producteur_base.h"
#include "consommateur_base.h"

class filtre_base : public filtre, public producteur_base, public consommateur_base
{
public:
    virtual ~filtre_base() {}

    virtual unsigned int nbEntrees() const = 0;
    virtual unsigned int nbSorties() const = 0;

    virtual const counted_ptr<flot>& getSortie(unsigned int) const = 0;
    virtual const counted_ptr<flot>& getEntree(unsigned int) const = 0;

    virtual void connecterEntree(const counted_ptr<flot>&, unsigned int) = 0;
    virtual bool yaDesEchantillons() const = 0;

    virtual void calculer() = 0;
};
