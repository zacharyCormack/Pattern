#pragma once
#include "Gridline.hpp"
#include "Cell.hpp"
#include <vector>
#include <bitset>
#include "mod.hpp"
#include <cstdlib>

class Grid {
	int length;
public:
	//index with cells[row][column], privatize
	std::vector<std::vector<Cell> > cells;
	std::vector<Gridline> grid_rows;
	std::vector<Gridline> grid_cols;
	void colour();
	void randomize(double skew);
	std::vector<std::bitset<32> > convert_to_bitset();
	void* convert_to_bits();
	
	Gridline get_line(int index, bool row_not_col);
	Grid(int side, double skew);
};
