#ifndef CELL
#define CELL

#include <vector>
#include <string>

class Cell
{
	int value;
	std::vector<int> list;	

public:
	Cell();
	~Cell();
	std::vector<int> const& getList() const;
	int getValue() const;
	void setValue(int v);
	void removeValue(int v);
	void print() const;
};
#endif


#ifndef BOARD
#define BOARD

#include <string>

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
