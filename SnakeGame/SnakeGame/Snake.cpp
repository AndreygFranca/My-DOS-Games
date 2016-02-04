#include "Snake.h"

/**
* Snake implementation
*/


void Snake::Move() {
	//Inputs handle
	HANDLE input_handle;
	HANDLE output_handle;


	INPUT_RECORD input;

	DWORD Events = 0;

	ReadConsoleInput(input_handle, &input, 1, &Events);

	if (input.Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
	{


	}


}

void Snake::Draw() {

}

void Snake::GainSize() {

}