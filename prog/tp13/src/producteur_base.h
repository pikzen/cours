#pragma once

#include "producteur.h"
#include "counted_ptr.h"
#include <deque>

class producteur_base : public producteur
{
protected:
    virtual void connecterSortie(const counted_ptr<flot>&, unsigned int) = 0;
public:
    virtual ~producteur_base() {}
    virtual unsigned int nbSorties() const = 0;
    virtual const counted_ptr<flot>& getSortie(unsigned int) const = 0;
    virtual void calculer() = 0;
};
