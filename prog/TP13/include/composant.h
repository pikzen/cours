// -*- c++ -*-

#ifndef __COMPOSANT__H__
#define __COMPOSANT__H__

// sp�cification d'un composant du syst�me sonore

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	composant
///
/// \brief	Interface d'un composant du systeme sonore. 
///
/// \author	Jean Christophe Engel, Fabrice Lamarche, University Of Rennes 1
/// \date	23/04/2010
////////////////////////////////////////////////////////////////////////////////////////////////////
class composant {
public:

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn	virtual ~composant()
  ///
  /// \brief	Finaliser.
  ///
  /// \author	Jean Christophe Engel, Fabrice Lamarche, University Of Rennes 1
  /// \date	23/04/2010
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  virtual ~composant() {}

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn	virtual void calculer() = 0
  ///
  /// \brief	Effectue les calculs associes au composant.
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  virtual void calculer() = 0;
};

#endif // __COMPOSANT__H__