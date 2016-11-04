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
	void setValue(int val);
	int removeValue(int val);
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
	void removeNear(int x, int y, int val); 		//Removes the value val from neighboring cells of (x,y)
	void removeValue(int x, int y, int val);
	void solve();
	bool isDone() const;
	void print() const;
};

#endif
