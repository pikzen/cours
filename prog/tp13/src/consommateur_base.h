#pragma once

#include "consommateur.h"
#include "counted_ptr.h"
#include "flot.h"

class consommateur_base : public consommateur
{
public:
    virtual ~consommateur_base() {};
    virtual unsigned int nbEntrees() const = 0;
    virtual const counted_ptr<flot>& getEntree(unsigned int) const = 0;
    virtual void connecterEntree(const counted_ptr<flot>&, unsigned int) = 0;
    virtual bool yaDesEchantillons() const = 0;
};
