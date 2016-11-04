#include <iostream>
#include "Cell.h"

using namespace std;

int main(){
	int const size = 9;
	
	Board board("../data/s01a.txt");
	board.solve();
	board.print();


	return 0;
}