#include <fstream>
#include "Grid.hpp"
#include <iostream>
#include <bitset>
using namespace std;

int main (int num, char** inputs) {
	if(num > 4) {
		cout << "Error #1!\n";
		return 1;
	}
	else if(num == 1) {
		cout << "Error #2!\n";
		return 2;
	}
	else if(inputs[1][0] == 'h') {
		if(num == 2) {
			cout <<
			"\nGENERAL HELP: How to get specific help\n\n"
			"  h	  general help\n"
			"  h p	list of inputs\n"
			"  h e	list of exit codes\n"
			"  h a	what this program does\n"
			"  h f	all of the above\n";
		}
		else if(inputs[2][0] == 'p') {
			cout <<
			"\nPARAMETER LIST\n\n"
			"  For help:\n"
			"	One: h indicates need of help\n"
			"	Two: indicates type of help, plain for how to get help\n"
			"  For normal use:\n"
			"	One: type unsigned int, indicates size of grid, must be below 64\n"
			"	Two: file destination\n"
			"	Three: optional: type double, bias for grid generaton, must be from -1 to 1 inclusive, default 0\n";
		}
		else if(inputs[2][0] == 'e') {
			cout <<
			"\nEXIT CODES LIST\n\n"
			"  0. all went well\n"
			"  1. too many parameters, give 2 or 3\n"
			"  2. too few parameters, give 2 or 3\n"
			"  3. param one is of wrong type, should be unsigned int\n"
			"  4. param one is out of bounds, should be less than 64\n"
			"  5. param three is invalid, must be of type double and from -1 to 1\n";
		}
		else if(inputs[2][0] == 'a') {
			cout <<
			"\nABOUT THIS PROGRAM\n\n"
			"  Created by Zachary Cormack in 2020\n"
			"  This program creates a binary file which represents a special pattern\n"
			"  How it does so is complicated and involves lots of math\n"
			"  Enjoy using this program\n"
			"	P.S. The optional bias parameter affects how the design looks\n";
		}
		else if(inputs[2][0] == 'f') {
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
			"  3. param one is of wrong type, should be int\n"
			"  4. param one is out of bounds, should be between 0 and 64, exlusive\n"
			"  5. param three is invalid, must be of type double and from -1 to 1\n\n\n"
			"ABOUT THIS PROGRAM\n\n"
			"  Created by Zachary Cormack in 2020\n"
			"  This program creates a binary file which represents a special pattern\n"
			"  How it does so is complicated and involves lots of math\n"
			"  Enjoy using this program\n"
			"	P.S. The optional bias parameter affects how the design looks\n";
		}
		else {
			cout <<
			"*** Invalid help type, using default help instead ***\n"
			" >  GENERAL HELP: How to get specific help\n\n"
			" >	h		   general help\n"
			" >	h params	list of inputs\n"
			" >	h exit	  list of exit codes\n"
			" >	h about	 what this program does\n"
			" >	h full	  all of the above";
		}
		return 0;
	}
	else if(num < 3) {
		cout << "Error #2!\n";
		return 2;
	}
	char* side_in = inputs[1];
	unsigned int side = 0;
	for(unsigned short int i = 0; i < 2; i++) {
		if((int)(side_in[i]) - (int)('0') > 9 || (int)(side_in[i]) - (int)('0') < 0) {
			cout << "Error #3!\n";
			return 3;
		}
		side += ((int)(side_in[i])-(int)('0')) * power(10, 1-i);
	}
	if(side > 63) {
		cout << "Error #4!\n";
		return 4;
	}
	char* out_loc = inputs[2];
	double bias = 0.0;
	if(num > 3) {
		char* bias_in = inputs[4];
		if(bias_in[0] == '-') {
			if(bias_in[1] == '1') {
				bias = 1.0;
			}
			else if(bias_in[1] == '0' && bias_in[2] == '.' && sizeof(*bias_in) > sizeof(char)*2) {
				for(unsigned short int i = 3; i < sizeof(*bias_in)/sizeof(char); i++) {
					if((int)bias_in[i] > 57 || (int)bias_in[i] < 48) {
						cout << "Error #6!\n";
						return 6;
					}
					bias += (bias_in[i]-48)/power(10, i-2);
				}
			}
			else {
				cout << "Error #6!\n";
				return 6;
			}
			bias *= -1;
		}
		else if(bias_in[0] == '0') {
			if (!(sizeof(*bias_in) == sizeof(char))) {
				for(unsigned short int i = 0; i < sizeof(*bias_in)/sizeof(char); ++i) {
					if((int)bias_in[i] > 57 || (int)bias_in[i] < 48) {
						cout << "Error #6!\n";
						return 6;
					}
					bias += ((int)(bias_in[i])-(int)('0'))/power(10, i);
				}
			}
		}
		else if((bias_in[0] == '1' && sizeof(*bias_in) == sizeof(char))||strcmp(bias_in, (char*)"1.0")) {
			bias = 1;
		}
		else {
			cout << "Error #6!\n";
			return 6;
		}
	}
	Grid grid(side, bias);
	grid.colour();
	vector<bitset<64> > rows = grid.convert_to_bitset();
	ofstream file(out_loc);
	for (unsigned short i = 0; i < side; i++)
	{
		for (unsigned short j = 0; j < side; j++)
		{
			cout << (rows[i][j] ? "  " : "\e[47;30m  \e[0m");
			file << (rows[i][j] ? "  " : "\e[47;30m  \e[0m");
		}
		cout << "\n";
		file << "\n";
	}
	return 0;
}
