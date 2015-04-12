// -*- c++ -*-

#ifndef __FILTRE__H__
#define __FILTRE__H__

#include "producteur.h"
#include "consommateur.h"

// sp�cification d'un filtre

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	filtre
///
/// \brief	Interface associ�e � un filtre sonore. Ce filtre est consid�r� comme un producteur /
///		consommateur d'�chantillons sonores. Il poss�de donc des entr�es et des sorties.
///
/// \author	Jean Christophe Engel, Fabrice Lamarche, University Of Rennes 1
/// \date	23/04/2010
////////////////////////////////////////////////////////////////////////////////////////////////////
class filtre : public virtual producteur, public virtual consommateur {
public:

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn	virtual ~filtre()
  ///
  /// \brief	Destructeur virtuel. 
  ///
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  virtual ~filtre() {}
};

#endif // __FILTRE__H__
