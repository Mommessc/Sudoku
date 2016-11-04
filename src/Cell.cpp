#include "Cell.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

//Class Cell
Cell::Cell() :
	value(0), list(9)
	{
	for(int i(0); i<9;i++){
		list[i] = i+1;
	}
}
Cell::~Cell(){} // Destructor by default, not useful


std::vector<int> const& Cell::getList() const{
	return list;
}

int Cell::getValue() const{
	return value;
}

void Cell::setValue(int val){
	value = val;
	list.clear();
	list.push_back(val);
}

// If value has been set returns the value. Otherwise returns 0.
int Cell::removeValue(int val){
	if(list.size() > 1){
		auto it = find(list.begin(), list.end(), val);
		if (it != list.end()){
			std::swap(*it, list.back());
			list.pop_back();
		}
		//list.erase(std::remove(list.begin(), list.end(), val), list.end());
		if(list.size() == 1){
			value = list[0];
			return list[0];
		}
	}
	return 0;
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
Board::Board(string filename){
	ifstream in(filename);
	if(!in){
        cout << "ERROR while reading the input file: " << filename << endl;
		return;
	}
	int val(0);
	for(int i(0); i<9; ++i){
		for(int j(0); j<9; ++j){
			in >> val;
			if(val){
				tab[i][j].setValue(val);
				removeNear(i, j, val);
			}
		}
	}
}
Board::~Board(){}


void Board::removeNear(int x, int y, int val){
	for(int k(0); k<9;++k){
		removeValue(x, k, val);
		removeValue(k, y, val);
	}
	int i(x/3), j(y/3); //gives the coordinates of the block
	for(int a(0); a<3; ++a){
		for(int b(0); b<3; ++b){
			removeValue(i*3+a, j*3+b, val);
		}
	}

}

// Removes val in cell (x,y), if only one value remaining in the cell, updates neighbours
void Board::removeValue(int x, int y, int val){
	int ret = tab[x][y].removeValue(val);
	if(ret){
		removeNear(x, y, ret);
	}
}


void Board::solve(){
	//tab[7][2].setValue(1);
	//removeNear(7, 2, 1);
}

bool Board::isDone() const{
	int nb(0);
	for(int i(0); i<9; ++i){
		for(int j(0); j<9; ++j){
			nb += (tab[i][j].getValue() != 0);
		}
	}
	return nb == 81;
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
