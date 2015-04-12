#pragma once

#include "cyclicnode.h"
#include <assert.h>

template<typename T>
class Liste {
protected:
	typedef DataStructure::cyclicNode<T> Chainon;
private:
	int m_size;
	Chainon* m_first;
public:

	///////////////////////////////////////////////////////////////////////////
	// Liste::iterator
	// Permet d'itérer sur tous les éléments d'une liste et de les modifier
	// Pour un itérateur constant, voir const_iterator
	///////////////////////////////////////////////////////////////////////////
	class iterator{
	protected:
		Chainon* m_current;
		Liste<T>* m_list;
	private:
		iterator(Chainon* pointing_to, Liste<T>* list) :
			m_current(pointing_to),
			m_list(list)
		{
		};
		iterator()
		{
		};

	public:
		T& operator*(void)
		{
			return m_current->data();
		};

		T* operator->(void)
		{
			return &m_current->data();
		}

		bool operator==(const iterator iter)
		{
			return iter.m_current == this->m_current;
		}
		bool operator!=(const iterator iter)
		{
			return iter.m_current != this->m_current;
		}

 		iterator& operator++(void)
		{
			assert(*this != m_list->end());

			m_current = m_current->next();
			return *this;
		}

		iterator& operator--(void)
		{
			assert(*this != m_list->begin());

			m_current = m_current->previous();
			return *this;
		}


	friend class Liste;
	};

	class const_iterator{
	private:
		Chainon* m_current;
		const Liste<T>* m_list;
		const_iterator(Chainon* pointing_to, const Liste<T>* list) :
			m_current(pointing_to),
			m_list(list)
		{
		};
	public:
		const_iterator& operator++(void) {
			assert(*this != m_list->end());

			m_current = m_current->next();
			return *this;
		};

		const_iterator& operator--(void) {
			assert(*this != m_list->begin());

			m_current = m_current->previous();
			return *this;
		}

		const T& operator*(void) {
			assert(!m_list->empty());
			return m_current->data();
		};

		const T* operator -> (void) {
			assert(!m_list->empty());
			return &this->m_current->data();
		}

		bool operator == (const const_iterator iter1) {
			return iter1.m_current == this->m_current;
		};

		bool operator != (const const_iterator iter1) {
			return iter1.m_current != this->m_current;
		}

	friend class Liste;
	};

	/*
	 * ctor
	 * Construit une liste vide
	 */
	Liste() :
		m_first(new Chainon())
	{
		m_size = 0;
	};

	/*
	 * dtor
	 * Détruit la liste, en libérant
	 */
	~Liste() {
		while (!this->empty())
			this->pop_back();
		delete m_first;
	};

	void mergeList(Liste<T> const &other)
	{
		for (Liste<T>::const_iterator it = other.begin(); it != other.end(); ++it)
			this->push_back(*it);
	}

	Liste<T>& operator=(Liste<T> const& other)
	{
		if (this != &other)
		{
			if (this->m_first != NULL)
				delete this->m_first;
			this->m_first = new Chainon();
			this->mergeList(other);
		}
		return *(this);
	}

	Liste<T>& operator+(const Liste<T>& other) const
	{
		Liste<T>* copy = new Liste<T>();
		copy->mergeList(*this);
		copy->mergeList(other);

		return *copy;
	}

	const_iterator begin(void) const{
		return const_iterator(m_first->next(), this);
	};

	const_iterator end(void) const {
		return const_iterator(m_first, this);
	};

	iterator begin(void) {
		return iterator(m_first->next(), this);
	}

	iterator end(void) {
		return iterator(m_first, this);
	}

	/*************************************************************
	 * Vérifie si la liste est vide.
	 *************************************************************/
	const bool empty() const{
		return m_first->next() == m_first && m_first->previous() == m_first;
	};

	/*************************************************************
	 * Renvoie la taille de la liste
	 *************************************************************/
	const int size() const{
		return m_size;
	}

	const T front() const {
		assert(!empty());

		return m_first->next()->data();
	}

	T& front() {
		assert(!empty());

		return m_first->next()->data();
	}

	const T back() const {
		assert(!empty());
		return m_first->previous()->data();
	}

	T& back() {
		assert(!empty());

		return m_first->previous()->data();
	}

	void push_front(T data) {
		m_first->insertAfter(new Chainon(data));
		m_size++;
	}

	void push_back(T data) {
		m_first->previous()->insertBefore(new Chainon(data));
		m_size++;
	}

	void pop_front() {
		assert(!empty());

		Chainon* copy = m_first->next();
		copy->detach();
		m_size--;
		delete copy;
	}

	void pop_back() {
		assert(!empty());

		Chainon* copy = m_first->previous();
		copy->detach();
		delete copy;
		m_size--;
	}

	Liste<T>::iterator insert(Liste<T>::iterator, const T&);
	Liste<T>::iterator erase(Liste<T>::iterator);
};

template<class T>
typename Liste<T>::iterator Liste<T>::insert(typename Liste<T>::iterator position, const T& x)
{
	if(position == this->end())
	{
		Liste<T>::push_back(x);
		Liste<T>::iterator enditer(this->end());

		return --enditer;
	}
	else
	{
		Chainon* tmp = new Chainon(x);
		position.m_current->insertBefore(tmp);

		return --position;
	}
}

template<class T>
typename Liste<T>::iterator Liste<T>::erase(typename Liste<T>::iterator position) {
	Chainon* cpy = position.m_current;
	++position;
	cpy->detach();
	delete cpy;
	return position;
}

template <class T>
std::ostream & operator << (std::ostream& os, Liste<T> const& l)
{
	os << "<";
	for (typename Liste<T>::const_iterator i = l.begin(); i != l.end(); ++i)
		os << *i << " ";
	os << ">";
	return os;
}