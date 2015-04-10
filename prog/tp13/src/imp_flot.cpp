#include "imp_flot.h"
#include <assert.h>

/**
* Simple flot de données
*/
imp_flot::imp_flot()
{

}


/**
* Insère un sample dans le flot de données
*/
void imp_flot::inserer(double sample)
{
    m_samples.push_back(sample);
}

/**
* Extrait le sample à l'avant du flot et le supprime du flot.
*/
double imp_flot::extraire()
{
    assert( !vide() );
    double val = m_samples.front();
    m_samples.pop_front();

    return val;
}

/**
* Vérifie si le flot contient encore des données
*/
bool imp_flot::vide() const
{
    return m_samples.size() == 0;
}
