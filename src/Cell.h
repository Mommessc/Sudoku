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
	int contains(int val);
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
	Board(){};
	Board(std::string filename);
	~Board();
	void removeNear(int x, int y, int val); 		//Removes the value val from neighboring cells of (x,y)
	void removeValue(int x, int y, int val);
	void reduceAppearsOnce(); 						//Tests and removes in each row/col/block if a value appears once
	void setRow(int row, int val);
	void setColumn(int col, int val);
	void setBlock(int x, int y, int val);
	void solve();
	bool isDone() const;
	void print() const;
};

#endif
