#ifndef _SNAKE_H
#define _SNAKE_H

#include "Main.h"

class CSnake {
public:
	CSnake(); 

	int lenght;

	void Move();

	void Draw(bool draw);

	void GainSize();

	void Logic();
private:
	HANDLE input_handle;
	HANDLE output_handle;
	COORD Position;

	//Directions
	bool L, R, D, U, A; // LEFT, RIGHT, DOWN, UP, A just a bool
};

#endif //_SNAKE_H