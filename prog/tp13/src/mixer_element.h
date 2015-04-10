#pragma once

#include <cassert>
#include "filtre_compose.h"

class mixer_element : public filtre_compose
{
public:
	mixer_element(unsigned int);
	virtual ~mixer_element() {};
};