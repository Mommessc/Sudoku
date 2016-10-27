#include "Cell.h"
#include <iostream>

using namespace std;

//Class Cell
Cell::Cell(){
	value = 0;
	list = vector<int>(9);
	for(int i(0); i<9;i++){
		list[i] = i+1;
	}
}
Cell::Cell(int v){
	value = v;
	list = vector<int>(1,v);
}
Cell::~Cell(){} // Destructor by default, not useful


std::vector<int> Cell::getList() const{
	return list;
}

int Cell::getValue() const{
	return value;
}

void Cell::setValue(int v){
	value=v;
	list = vector<int>(1,v);
}

void Cell::removeValue(int v){
	//TODO remove value v form the list
	//if only 1 value, set value correspondingly
}

void Cell::print() const{
	string s("");
	for(unsigned int i(0); i<list.size();++i){
		s+= to_string(list[i]) + " ";
	}
	cout << s << endl;
}
//End Class Cell
//Class Board
Board::Board(string filename){}
Board::~Board(){}
	
void Board::solve(){
	tab[4][5].setValue(12);
}

void Board::print() const{
	string s("");
	for(int i(0); i<9; ++i){
		for(int j(0); j<9; ++j){
			s+= to_string(tab[i][j].getValue()) + " ";
		}
		s+="\n";
	}
	cout << s << endl;
}
//End Class Board
