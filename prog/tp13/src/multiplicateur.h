#pragma once

#include "filtre_base.h"
#include "counted_ptr.h"

class multiplicateur : public filtre_base
{   
public:
    multiplicateur();
    virtual ~multiplicateur() {};
    virtual void calculer();
};
