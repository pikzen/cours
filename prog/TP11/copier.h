#pragma once

#include "liste.hh"


template<class T>
typename Liste<T>::iterator chercherTri(Liste<T>& list, T const& elem)
{
	typename Liste<T>::iterator iter = list.begin();
	while (iter != list.end() && *iter != elem)
	{
		++iter;
	}

	return iter;
}

template <class T>
Liste<T>* copierTri(Liste<T> const& list)
{
	Liste<T>* copy = new Liste<T>();
	for (typename Liste<T>::const_iterator iter = list.begin(); iter != list.end(); ++iter) {
		copy->insert(chercherTri(*copy, *iter), *iter);
	}

	return copy;
}

template<class T>
typename Liste<T>::iterator
find (typename Liste<T>::iterator premier, typename Liste<T>::iterator dernier, const T& x)
{
	bool found = false;

	while (!found && premier != dernier) 
	{
		if (*premier == x)
		{
			found = true;
		}
		else {
			++premier;
		}
	}

	return premier;
}

