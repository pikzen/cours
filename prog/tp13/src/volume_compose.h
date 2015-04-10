#pragma once

#include "filtre_compose.h"

class volume_compose : public filtre_compose
{
public:
	volume_compose(double);
	virtual ~volume_compose() {};
};