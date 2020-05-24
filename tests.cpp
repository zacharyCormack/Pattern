#include "Grid.hpp"
#include "tests.hpp"
#include <iostream>
#include "mod.hpp"

int test() {
	int errors = 0;
	Gridline line1(false, false);
	Gridline line2(true, false);
	Gridline line3(true, true);
	if(line1.get_edge(true) || line3.get_edge(false) || line2.get_edge(true)) {
		errors+=1;
		std::cout << "error 1\n";
		std::cout << line1.get_edge(true) << line3.get_edge(false) << line2.get_edge(false);
	}
	line1.switch_activity(true);
	if(!line1.get_edge(false)) {
		errors+=2;
		std::cout << "error 2\n";
	}
	Grid grid1(5.0, 0.0);
	Grid grid2(5.0, -0.5);
	Grid grid3(5.0, -1);
	grid1.colour();
	grid2.colour();
	grid3.colour();
	for(unsigned short int i = 0; i < 4; i++) {
		std::cout << "\n\n----\n" << grid1.cells[0][i].get_next(true) << grid1.grid_rows[i+1].get_edge(false) << i << 0 << "\n\n";
		for(unsigned short int j = 0; j < 4; j++) {
			std::cout << grid1.cells[j][i].get_next(false) << grid1.grid_cols[j+1].get_edge(false) << j << i << "\n";
		}
	}
	std::vector<std::bitset<32> > bits = grid1.convert_to_bitset();
	for(unsigned short int i = 0; i < 5; i++) {
		std::cout << grid1.grid_cols[i].get_edge(false);
	}
	std::cout << "\n\n";
	for(unsigned short int i = 0; i < 5; i++) {
		std::cout << grid1.grid_rows[i].get_edge(false) << " ";
		for(unsigned short int j = 0; j < 5; j++) {
			std::cout << bits[i][5-j];
		}
		std::cout << "\n";
	}
	grid2.randomize(0.5);
	grid3.randomize(0.5);
	grid2.colour();
	grid3.colour();
	return errors;
}
