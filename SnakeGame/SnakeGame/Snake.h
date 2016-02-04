#ifndef _SNAKE_H
#define _SNAKE_H

#include "Main.h"

class Snake {
public:
	int Size;

	void Move();

	void Draw();

	void GainSize();
private:
	COORD Position;
};

#endif //_SNAKE_H