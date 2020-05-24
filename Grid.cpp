#include "Grid.hpp"

Grid::Grid(int side, double skew) {
	length = side;
	std::bitset<16> random(rand());
	for(unsigned short int i = 0; i < side; i++) {
		if(i%8==0) {
			std::bitset<16> newRand(rand());
			random = newRand;
		}
		
		//logic operation allows skew to make 1's or 0's more probable.
		if(skew>0) {
			Gridline new_col(i%2==0, modulo(i*skew, 0.5)<skew||random[2*i-1]);
			Gridline new_row(i%2==0, modulo(i*skew, 0.5)<skew||random[2*i]);
			grid_cols.push_back(new_col);
			grid_rows.push_back(new_row);
		}
		else if(skew < 0) {
			Gridline new_col(i%2==0, !(modulo(i*skew, 0.5)>(1+skew)||random[2*i-1]));
			Gridline new_row(i%2==0, !(modulo(i*skew, 0.5)>(1+skew)||random[2*i]));
			grid_cols.push_back(new_col);
			grid_rows.push_back(new_row);
		}
		else {
			Gridline new_col(i%2==0, random[2*i-1]);
			Gridline new_row(i%2==0, random[2*i]);
			grid_cols.push_back(new_col);
			grid_rows.push_back(new_row);
		}
	}
	for(unsigned short int i = 0; i < side; i++) {
		std::vector<Cell> new_cell_row;
		for(unsigned short int j = 0; j < side; j++) {
			Cell new_cell(&grid_rows[j], &grid_rows[j+1], &grid_cols[i], &grid_cols[i+1], i, j);
			new_cell_row.push_back(new_cell);
		}
		cells.push_back(new_cell_row);
	}
}

void Grid::randomize(double skew) {
	std::bitset<16> random(std::rand());
	for(unsigned short int i = 0; i < length; i++) {
		if(i%8==0) {
			std::bitset<16> new_rand(std::rand());
			random = new_rand;
		}
		//logic operation allows skew to make 1's or 0's more probable.
		if(skew>0) {
			grid_cols[i].switch_activity(modulo(i*skew, 0.5)<skew||random[2*i-1]);
			grid_rows[i].switch_activity(modulo(i*skew, 0.5)<skew||random[2*i]);
		}
		else {
			grid_cols[i].switch_activity(!(modulo(i*skew, 0.5)>1+skew||random[2*i-1]));
			grid_rows[i].switch_activity(!(modulo(i*skew, 0.5)>1+skew||random[2*i]));
		}
	}
}

void Grid::colour() {
	for(unsigned short int i = 0; i < length; i++) {
		for(unsigned short int j = 0; j < length-1; j++) {
			cells[j+1][i].draw(cells[j][i].get_next(false));
		}
		cells[0][i+1].draw(cells[0][i].get_next(true));
	}
	for(unsigned short int j = 1; j < length; j++) {
		cells[j][length-1].draw(cells[j][length-1].get_next(true));//This is where the error is! The colour of the previous cell is never considered!
	}
}

std::vector<std::bitset<32> > Grid::convert_to_bitset() {
	std::vector<std::bitset<32> > bit_array;
	for(unsigned short int i = 0; i < length; i++) {
		long row_int_representation = 0;
		for(unsigned short int j = 0; j < length; j++) {
			if(cells[i][j].colour) {
				row_int_representation += power(2, j);
			}
		}
		std::bitset<32> row_bit_representation(row_int_representation);
		bit_array.push_back(row_bit_representation);
	}
	
	return bit_array;
}

Gridline Grid::get_line(int index, bool row_not_col) {
	if(row_not_col) {
		return grid_rows[index];
	}
	return grid_cols[index];
}

void* Grid::convert_to_bits() {
	std::vector<long long> output;
	for(unsigned short int i = 0; i < length; i++) {
		long long row_int = 0;
		for(unsigned short int j = 0; j < length; j++) {
			if(cells[i][j].colour) {
				row_int += power(2, j);
			}
		}
		output.push_back(row_int);
	}
	return (void*)&output;
}
