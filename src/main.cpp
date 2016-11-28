#include "Cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv){
	if(argc < 4){
		printf("Usage: %s 0 [grid] [path/to/data/] \nOr %s 1 [list_grids] [path/to/data/]\n", argv[0], argv[0]);
		exit(1);
	}
	
	if(atoi(argv[1]) == 0){ //case single grid
		std::string filename(argv[3]);
		filename.append(argv[2]);
		Board board(filename);
		board.solve();
		board.print();
		cout << "Is" << filename << " solved? " << (board.isDone()?"yes":"no") << endl;
	}

	if(atoi(argv[1]) == 1){ //case file containing paths to grids
		std::string filename(argv[3]);
		filename.append(argv[2]);
		ifstream in(filename.c_str());
		if(!in){
			cout << "ERROR while reading the input file: " << filename << endl;
			exit(1);
		}

		string line(""), path(argv[3]), grid_file;
		Board board;
		while(getline(in, line)){
			grid_file = string(path).append(line);
			board = Board(grid_file);
			board.solve();
			cout << "Is " << line << " solved? " << (board.isDone()?"yes":"no") << endl;		
		}


	}

	/*Board board("../data/s13b.txt");
	//board.solve();
	board.print();
	cout << board.isDone() << endl;
*/
	return 0;
}