#pragma once
#include "Gridline.hpp"
#include <vector>

class Cell {
	int row_index;
	int col_index;
public:
	Gridline* up_p;
	Gridline* down_p;
	Gridline* left_p;
	Gridline* right_p;
	bool colour;
	bool get_next(bool vertical);
	void draw(bool newColour);
	Cell(Gridline* up, Gridline* down, Gridline* left, Gridline* right, int x_coord, int y_coord);
};
