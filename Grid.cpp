#include "Grid.hpp"
using namespace std;

Grid::Grid(int side, double skew)
{
	length = side;
	bool prev_c = ((float)rand()/RAND_MAX)>0.5;
	bool prev_r = ((float)rand()/RAND_MAX)>0.5;
	for(unsigned short int i = 0; i < side; i++)
	{
		//logic operation allows skew to make 1's or 0's more probable.
		if (((float)rand()/RAND_MAX)>(skew+1)/2)
			prev_c = !prev_c;
		if (((float)rand()/RAND_MAX)>(skew+1)/2)
			prev_r = !prev_r;
		Gridline new_col(i%2==0, prev_c);
		Gridline new_row(i%2==0, prev_r);
		grid_cols.push_back(new_col);
		grid_rows.push_back(new_row);
	}
	for(unsigned short int i = 0; i < side; i++)
	{
		vector<Cell> new_cell_row;
		for(unsigned short int j = 0; j < side; j++)
		{
			Cell new_cell(&grid_rows[j], &grid_rows[j+1], &grid_cols[i], &grid_cols[i+1], i, j);
			new_cell_row.push_back(new_cell);
		}
		cells.push_back(new_cell_row);
	}
}

void Grid::randomize(double skew)
{
	bool prev_c = ((float)rand()/RAND_MAX)>0.5;
	bool prev_r = ((float)rand()/RAND_MAX)>0.5;
	for(unsigned short int i = 0; i < length; i++)
	{
		//logic operation allows skew to make 1's or 0's more probable.
		if (((float)rand()/RAND_MAX)>(skew+1)/2)
			prev_c = !prev_c;
		if (((float)rand()/RAND_MAX)>(skew+1)/2)
			prev_r = !prev_r;
		grid_cols[i].switch_activity(prev_c);
		grid_rows[i].switch_activity(prev_r);
	}
}

void Grid::colour()
{
	for(unsigned short int i = 0; i < length; i++)
	{
		for(unsigned short int j = 0; j < length-1; j++)
			cells[j+1][i].draw(cells[j][i].get_next(false));
		cells[0][i+1].draw(cells[0][i].get_next(true));
	}
	for(unsigned short int j = 1; j < length; j++)
	{
		cells[j][length-1].draw(cells[j][length-1].get_next(true));//This is where ab error was! The colour of the previous cell is never considered!
	}
}

vector<bitset<64> > Grid::convert_to_bitset()
{
	vector<bitset<64> > bit_array;
	for(unsigned short int i = 0; i < length; i++)
	{
		long long row_int_representation = 0;
		for(unsigned short int j = 0; j < length; j++)
		{
			row_int_representation<<=1;
			if(cells[i][j].colour)
				row_int_representation++;
		}
		bitset<64> row_bit_representation(row_int_representation);
		bit_array.push_back(row_bit_representation);
	}
	return bit_array;
}