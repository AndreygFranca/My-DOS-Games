#include "Food.h"

/**
* Food implementation
*/

CFood::CFood() {

}

void CFood::GenerateFood(void) {
	srand((unsigned int)time(NULL));
	rand();  rand();  rand(); rand();
}

int CFood::FoodPosition(int a, int b) {
	//Gera um numero aleatorio em um determinado intervalo, e retorna esse numero.

	double r;
	r = (double)rand() / RAND_MAX;
	return (int)(a + (r*(b - a)));
}