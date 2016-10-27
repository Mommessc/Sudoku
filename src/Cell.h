#include <vector>
#include <string>

#ifndef CELL
#define CELL

class Cell
{
	int value;
	std::vector<int> list;	

public:
	Cell();
	Cell(int v);
	~Cell();
	std::vector<int> getList() const;
	int getValue() const;
	void setValue(int v);
	void removeValue(int v);
	void print() const;
};
#endif

#ifndef BOARD
#define BOARD

class Board
{
	Cell tab[9][9];

public:
	Board(std::string filename);
	~Board();
	void solve();
	void print() const;
};

#endif
