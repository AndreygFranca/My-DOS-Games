#include "Snake.h"

/**
* Snake implementation
*/


void Snake::Move() {
	INPUT_RECORD input;

	DWORD Events = 0;

	ReadConsoleInput(input_handle, &input, 1, &Events);

	if (input.Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
	{


	}


}

void Snake::Draw(int draw) {
	if (draw == 1)
	{
		SetConsoleCursorPosition(output_handle, Position);
		cout << 
	}


}

void Snake::GainSize() {

}