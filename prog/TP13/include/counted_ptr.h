// -*- c++ -*-

#ifndef COUNTED_PTR_H
#define COUNTED_PTR_H
#include <cassert>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	counted_ptr
///
/// \brief	Classe g�rant un "smart pointer". 
///
/// \author	Jean Christophe Engel, Fabrice Lamarche, University Of Rennes 1
/// \date	23/04/2010
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class counted_ptr {
public:
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn	explicit counted_ptr(T * pointer = 0)
  /// \brief	Constructeur
  /// \param	pointer Si non nul, un pointeur vers une variable allou�e dynamiquement.
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  explicit counted_ptr(T * pointer = 0) ;

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn	virtual ~counted_ptr(void)
  /// \brief	Destructeur, lib�re la donn�e s'il s'agit du dernier pointeur qui la d�signe.
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  virtual ~counted_ptr() ;

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn	counted_ptr(const counted_ptr & smartPointer)
  /// \brief	Constructeur de copie. 
  /// \param	smartPointer : le "smart pointer" � copier. 
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  counted_ptr(const counted_ptr & smartPointer) ;

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn	counted_ptr & operator = (const counted_ptr & smartPointer)
  /// \brief	Op�rateur d'affectation. 
  /// \param	smartPointer : l'op�rande de droite de l'affectation. 
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  counted_ptr & operator = (const counted_ptr & smartPointer) ;

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \brief	Constructeur de transtypage. Permet de pointer sur une instance de classe U
  ///		via un pointeur de type T, U h�ritant T.
  /// \param smartPointer 
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  template <class U>
  counted_ptr(const counted_ptr<U> & smartPointer) ;

  /// Donner � counted_ptr<U> acc�s � la partie priv�e de counted_ptr<T>
  template <class U> friend class counted_ptr;

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn	bool isnull () const
  /// \return	vrai si le pointeur ne d�signe rien
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  bool isnull() const;

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn	T & operator * () const
  /// \brief	Acc�s � la variable d�sign�e par le pointeur. 
  /// \return	La variable d�sign�e par le pointeur. 
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  T & operator * () const	;

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  /// \fn	T * operator -> () const
  /// \brief	Op�rateur d'acc�s aux attributs / m�thodes de la variable point�e. 
  /// \return	adresse de la variable d�sign�e par le pointeur.
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  T * operator -> () const ;

private:
  //------------------------------------------------------------------------
  // m�thodes d'impl�mentation
  //-----------------------------------------------------------------------

  // acqu�rir la ressource d�sign�e par cp
  void acquerir(const counted_ptr<T> & cp) ;

  // idem entre un counted_ptr<T> et un counted_ptr<U>
  template <class U>
  void acquerir(const counted_ptr<U> & cp) ;

  // lib�rer la ressource
  void liberer() ;

private:
  //------------------------------------------------------------------------
  // attributs
  //-----------------------------------------------------------------------
  unsigned int * m_counter ; // Pointeur vers le compteur de r�f�rences
  T   * m_ptr ;	    // Pointeur vers l'objet d�sign�
}; // counted_ptr<T>

///--------------------------------------------------------------------------------
/// m�thodes publiques
///--------------------------------------------------------------------------------

// constructeur "normal"
template <class T>
counted_ptr<T>::counted_ptr(T * pointer)
{
  if (pointer != 0) 
  {
    m_ptr = static_cast<T*>(pointer) ;
    m_counter = new unsigned int(1) ;
  }
  else		    
  {
    m_ptr = 0 ;
    m_counter = 0 ;
  }
}

// destructeur
template <class T>
counted_ptr<T>::~counted_ptr() { 
  liberer();
}

// constructeur de copie. 
template <class T>
counted_ptr<T>::counted_ptr(const counted_ptr<T> & smartPointer)
{ 
  acquerir(smartPointer);
}

// Op�rateur d'affectation. 
template <class T>
counted_ptr<T> & 
counted_ptr<T>::operator = (const counted_ptr<T> & smartPointer)
{
  if(m_counter != smartPointer.m_counter)
  {
    // les deux smart pointers ne d�signent pas la m�me variable
    liberer();
    acquerir(smartPointer);
  }
  return *this;
}

// constructeur de transtypage
template <class T>
template <class U>
counted_ptr<T>::counted_ptr(const counted_ptr<U> & smartPointer)
{ 
  acquerir(smartPointer);
}

// d�terminer si le pointeur d�signe quelque chose
template <class T>
bool
counted_ptr<T>::isnull() const { return m_ptr == 0; }

// op�rateur d'indirection *
template <class T>
T &
counted_ptr<T>::operator * () const 
{
  assert (! isnull());
  return *m_ptr;
}

// op�rateur d'indirection ->
template <class T>
T *
counted_ptr<T>::operator -> () const 
{
  assert (! isnull());
  return m_ptr ;
}

//------------------------------------------------------------------------
// m�thodes priv�es d'impl�mentation
//-----------------------------------------------------------------------

// acqu�rir la ressource d�sign�e par cp
template <class T>
void
counted_ptr<T>::acquerir(const counted_ptr<T> & cp)
{
  if (! cp.isnull()) {
    m_ptr = cp.m_ptr ;
    m_counter = cp.m_counter ;
    (*m_counter)++ ;
  }
  else 
  {
    m_ptr = 0 ;
    m_counter = 0 ;
  }
}

// idem entre un counted_ptr<T> et un counted_ptr<U>
template <class T>
template <class U>
void
counted_ptr<T>::acquerir(const counted_ptr<U> & cp)
{
  if (! cp.isnull()) {
    m_ptr = static_cast<T*>(cp.m_ptr) ;
    m_counter = cp.m_counter ;
    (*m_counter)++ ;	
  }
  else 
  {
    m_ptr = 0 ;
    m_counter = 0 ;
  }
}

// lib�rer la ressource
template <class T>
void
counted_ptr<T>::liberer()
{
  if (m_ptr != 0) {
    (*m_counter)-- ;
    if ((*m_counter) == 0) {
      delete m_ptr;
      delete m_counter ;
    } // d�truire la variable qui n'est plus utilis�e
  }
}
#endif // COUNTED_PTR_H
