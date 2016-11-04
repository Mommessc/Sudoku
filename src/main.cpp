#include <iostream>
#include "Cell.h"

using namespace std;

int main(){
	
	Board board("../data/s01a.txt");
	//board.solve();
	board.print();
	cout << board.isDone() << endl;

	return 0;
}