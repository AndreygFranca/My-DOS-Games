#ifndef _SNAKE_H
#define _SNAKE_H

#include "Main.h"

class Snake {
public:
	int Size;

	void Move(int draw);

	void Draw();

	void GainSize();
private:
	HANDLE input_handle;
	HANDLE output_handle;
	COORD Position;
};

#endif //_SNAKE_H