// -*- c++ -*-

#ifndef __ENREGISTREUR_FICHIER_TEXTE__H__
#define __ENREGISTREUR_FICHIER_TEXTE__H__

#include <fstream>
#include <vector>
#include "consommateur.h"
#include "constantes.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class enregistreur_fichier_texte
///
/// \brief Un consommateur qui enregistre ses entr�es dans un fichier texte ; 
///        une ligne = un �chantillon de chaque canal
///
/// \author Jean Christophe Engel, Fabrice Lamarche, University Of Rennes 1
/// \date 23/04/2010
////////////////////////////////////////////////////////////////////////////////////////////////////
// enregistrer un flux dans un fichier texte
class enregistreur_fichier_texte : public consommateur {
public:
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn enregistreur_fichier_texte(std::string nf, unsigned int nbc)
  ///
  /// \brief initialise le flux de sortie
  ///
  /// \param nf  : nom du fichier de sortie
  /// \param nbc : nombre de canaux (1 = mono, 2 = st�r�o)
  enregistreur_fichier_texte(std::string nf, unsigned int nbc);

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn virtual ~enregistreur_fichier_texte();
  ///
  /// \brief  Destructeur virtuel. ; ferme le fichier
  ///
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  virtual ~enregistreur_fichier_texte();

  /// \return Le nombre d'entrees du composant. 
  unsigned int nbEntrees() const;

  /// \return L'entr�e demand�e. 
  virtual const counted_ptr<flot> & getEntree(unsigned int numentree) const;

  /// \brief  Connecte une entr�e sur ce composant. 
  ///
  /// \param  f   Le flot � connecter en entr�e du composant. 
  /// \param  numentree Le num�ro de l'entree sur laquelle connecter le flot.
  ///
  /// \pre    0 <= numentree < nbEntrees()
  virtual void connecterEntree(const counted_ptr<flot> & f, unsigned int numentree);

  /// \return Vrai si chaque entr�e poss�de au moins un �chantillon.
  virtual bool yaDesEchantillons() const;

  /// \brief  Effectue les calculs associes au composant. 
  virtual void calculer();

private:
  // attributs du consommateur
  int         m_nbE;
  std::vector<counted_ptr<flot> > m_lesEntrees;

private:
  // attributs propres
  std::string m_nomFichier;   // fichier de sortie
  std::ofstream m_fluxSortie;
};

#endif // __ENREGISTREUR_FICHIER_TEXTE__H__
