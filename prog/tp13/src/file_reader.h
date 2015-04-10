#pragma once

#include "producteur_base.h"
#include <fstream>

class file_reader : public producteur_base
{
private:
	/**
	* Handle vers le fichier à lire
	*/
	std::ifstream m_handle;

	/**
	* Nombre de canaux dans ce fichier
	*/
	unsigned int m_canals;

public:
	file_reader(char*, unsigned int);
	virtual ~file_reader() { m_handle.close(); };
	virtual void calculer();
};