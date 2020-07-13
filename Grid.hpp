#pragma once
#include "Gridline.hpp"
#include "Cell.hpp"
#include <vector>
#include <bitset>
#include "mod.hpp"
#include <cstdlib>
#include <fstream>
using namespace std;

class Grid {
	int length;
	//index with cells[row][column]
	vector<vector<Cell> > cells;
public:
	vector<Gridline> grid_rows;
	vector<Gridline> grid_cols;
	void colour();
	void randomize(double skew);
	vector<bitset<64> > convert_to_bitset();
	Grid(int side, double skew);
};
