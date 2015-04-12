// -*- c++ -*-

#ifndef _FERRY_H
#define _FERRY_H
// choisir selon le conteneur utilisé
//#include <vector>
//#include <deque>
//#include <list>
#include "vehicule.h"
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include "tcomparator.h"
#include "comparerlongueurvehicule.h"
#include "comparerpassagersvehicule.h"

/**
 * Un ferry transporte des véhicules
 */
class Ferry {
public:
  typedef std::vector<const Vehicule*> container_t;
  /**
     constructeur : initialiser un ferry vide
     @param longueur  : capacité du ferry en unités de longueur
     @param personnes : capacité du ferry en nombre de passagers
  */
  Ferry (unsigned int lg, unsigned int nbp);

  /// destructeur
  virtual ~Ferry(void);

  /** ajouter un véhicule dans le ferry.
      sans effet s'il n'y a plus de place
      @param pv : désigne le véhicule à ajouter
      @return vrai si l'ajout a eu lieu, faux sinon
  */
  virtual bool   ajouter(const Vehicule * pv);

  //! déterminer le tarif de l'ensembles des véhicules présents dans le ferry
  virtual double calculerTarif(void) const;

  //! afficher les informations sur le contenu du ferry
  virtual void   afficher(std::ostream & s = std::cout) const;
  
  template <class TComparator>
          void   trier(TComparator comparer = TComparator())
  {
    std::sort(this->vehicules.begin(), this->vehicules.end(), comparer);
  }

private :
  unsigned int longueur;
  unsigned int longueurMax;

  unsigned int personnes;
  unsigned int personnesMax;

  container_t vehicules;
};

// opérateur d'affichage
std::ostream & operator << (std::ostream & sortie, const Ferry & ferry);

#endif // _FERRY_H
