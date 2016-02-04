#ifndef _FOOD_H
#define _FOOD_H

#include "Main.h"

class CFood {
public:

	CFood();

	void GenerateFood();

	int FoodPosition(int a, int b);

	COORD Position;
};

#endif //_FOOD_H