#include "Cell.hpp"
using namespace std;
//#include <iostream>

Cell::Cell(Gridline* up, Gridline* down, Gridline* left, Gridline* right, int x_coord, int y_coord)
{
	up_p = up;
	down_p = down;
	left_p = left;
	right_p = right;
	row_index = y_coord;
	col_index = x_coord;
}

bool Cell::get_next(bool vertical)
{
	//Forgot all about colour!
	// This caused a big error and it took a few hours to figure out the mistake.
	//cout << col_index << row_index << " ";
	if(!vertical)
{
		Gridline right = *right_p;
		//cout << right.get_edge(false);
		//cout << row_index%2 << "  ";
		return right.get_edge(false) ^ (row_index%2==1) ^ colour;
	}
	Gridline down = *down_p;
	//cout << " " << down.get_edge(false);
	//cout << col_index%2 << " ";
	return down.get_edge(false) ^ (col_index%2==1) ^ colour;
}

void Cell::draw(bool newColour)
{
	colour = newColour;
}
