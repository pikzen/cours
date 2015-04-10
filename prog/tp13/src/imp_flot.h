#pragma once

#include "flot.h"
#include <deque>

class imp_flot: public flot
{
private:
	/**
	* Liste des samples
	*/
    std::deque<double> m_samples;

public:
    imp_flot();
    virtual ~imp_flot() {};
    virtual void inserer(double);
    virtual double extraire();
    virtual bool vide() const;
};
