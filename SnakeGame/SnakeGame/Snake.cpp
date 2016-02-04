#include "Snake.h"

/**
* Snake implementation
*/

CSnake::CSnake()
{
	R = 1; L = 0; U = 0; D = 0;
}

void CSnake::Logic() {
	INPUT_RECORD input;

	DWORD Events = 0;

	ReadConsoleInput(input_handle, &input, 1, &Events);

	if (input.Event.KeyEvent.wVirtualKeyCode == VK_LEFT){
		if (R = 0) {
			L = 1; R = 0; U = 0; D = 0;
		}
	}
	if (input.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT) {
		if (L = 0) {
			L = 0; R = 0; U = 0; D = 1;
		}
	}
	if (input.Event.KeyEvent.wVirtualKeyCode == VK_UP) {
		if (D = 0) {
			L = 0; R = 0; U = 1; D = 0;
		}
	}
	if (input.Event.KeyEvent.wVirtualKeyCode == VK_DOWN) {
		if (U = 0) {
			L = 0; R = 0; U = 0; D = 1;
		}
	}


}

void CSnake::Draw(bool draw) {
	if (draw == 1){
		SetConsoleCursorPosition(output_handle, Position);
		cout << "@";
	}
	else{
		SetConsoleCursorPosition(output_handle, Position);
		cout << " ";
	}


}

void CSnake::GainSize() {
	if (Position.X == char(5) {
		lenght++;
		//Iniciar aleatorio. 
	}

}

void CSnake::Move() {
	if (R == 1) {
		Draw(0);
		Position.X++;
		Draw(1);
	}
	if (L == 1) {
		Draw(0);
		Position.X--;
		Draw(1);
	}
	if (U == 1) {
		Draw(0);
		Position.Y++;
		Draw(1);
	}
	if (D == 1) {
		Draw(0);
		Position.Y--;
		Draw(1);
	}

}