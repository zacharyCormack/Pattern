#include <fstream>
#include "Grid.hpp"
#include <iostream>
#include <bitset>
#include <sstream>
#include <ctime>
using namespace std;

int main (int num, char** inputs)
{
	srand((unsigned)time(NULL));
	if(num > 4)
	{
		cout << "Error #1!\n";
		return 1;
	}
	else if(num == 1)
	{
		cout << "Error #2!\n";
		return 2;
	}
	else if(inputs[1][0] == 'h')
	{
		if(num == 2)
			cout <<
			"\nGENERAL HELP: How to get specific help\n\n"
			"  h	  general help\n"
			"  h p	list of inputs\n"
			"  h e	list of exit codes\n"
			"  h a	what this program does\n"
			"  h f	all of the above\n";
		else if(inputs[2][0] == 'p')
			cout <<
			"\nPARAMETER LIST\n\n"
			"  For help:\n"
			"	One: h indicates need of help\n"
			"	Two: indicates type of help, plain for how to get help\n"
			"  For normal use:\n"
			"	One: type unsigned int, indicates size of grid, must be below 64\n"
			"	Two: file destination\n"
			"	Three: optional: type double, bias for grid generaton, must be from -1 to 1 inclusive, default 0\n";
		else if(inputs[2][0] == 'e')
			cout <<
			"\nEXIT CODES LIST\n\n"
			"  0. all went well\n"
			"  1. too many parameters, give 2 or 3\n"
			"  2. too few parameters, give 2 or 3\n"
			"  3. param one is out of bounds, should be between 0 and 64, exlusive\n"
			"  4. param three is invalid, must be of type double and from -1 to 1\n\n\n";
		else if(inputs[2][0] == 'a')
			cout <<
			"\nABOUT THIS PROGRAM\n\n"
			"  Created by Zachary Cormack in 2020\n"
			"  This program creates a binary file which represents a special pattern\n"
			"  How it does so is complicated and involves lots of math\n"
			"  Enjoy using this program\n"
			"	P.S. The optional bias parameter affects how the design looks\n";
		else if(inputs[2][0] == 'f')
			cout <<
			"\nGENERAL HELP: How to get specific help\n\n"
			"  h	  general help\n"
			"  h p	list of inputs\n"
			"  h e	list of exit codes\n"
			"  h a	what this program does\n"
			"  h f	all of the above\n\n\n"
			"PARAMETER LIST\n\n"
			"  For help:\n"
			"	One: h indicates need of help\n"
			"	Two: indicates type of help, plain for how to get help\n"
			"  For normal use:\n"
			"	One: type int, indicates size of grid, must be from 1 to 63\n"
			"	Two: file destination\n"
			"	Three: optional: type double, bias for grid generaton, must be from -1 to 1 inclusive, default 0\n\n\n"
			"EXIT CODES LIST\n\n"
			"  0. all went well\n"
			"  1. too many parameters, give 2 or 3\n"
			"  2. too few parameters, give 2 or 3\n"
			"  3. param one is out of bounds, should be between 0 and 64, exlusive\n"
			"  4. param three is invalid, must be of type double and from -1 to 1\n\n\n"
			"ABOUT THIS PROGRAM\n\n"
			"  Created by Zachary Cormack in 2020\n"
			"  This program creates a binary file which represents a special pattern\n"
			"  How it does so is complicated and involves lots of math\n"
			"  Enjoy using this program\n"
			"	P.S. The optional bias parameter affects how the design looks\n";
		else
			cout <<
			"*** Invalid help type, using default help instead ***\n"
			" >  GENERAL HELP: How to get specific help\n\n"
			" >	h		   general help\n"
			" >	h params	list of inputs\n"
			" >	h exit	  list of exit codes\n"
			" >	h about	 what this program does\n"
			" >	h full	  all of the above";
		return 0;
	}
	else if(num < 3)
	{
		cout << "Error #2!\n";
		return 2;
	}
	stringstream ins;
	ins << inputs[1];
	unsigned side = 0;
	ins >> side;
	if (side > 63 || side == 0)
	{
		cout << "Error #3!\n";
		return 3;
	}
	double bias = 0.0;
	if(num > 3)
	{
		ins << inputs[3];
		ins >> bias;
	}
	if (bias > 1 || bias < -1)
	{
		cout << "Error #4!\n";
		return 4;
	}
	Grid grid(side, bias);
	grid.colour();
	vector<bitset<64> > rows = grid.convert_to_bitset();
	ofstream file(inputs[2]);
	for (unsigned short i = 0; i < side; i++)
	{
		for (unsigned short j = 0; j < side; j++)
			file << (rows[i][j] ? "  " : "\e[47;30m  \e[0m");
		file << "\n";
	}
	return 0;
}
