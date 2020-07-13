#include "mod.hpp"

double modulo(double dividend, double divisor) {
	while(dividend>divisor) {
		dividend-=divisor;
	}
	return dividend;
}

int power(int base, int exponent) {
	if(exponent == 1) {
		return base;
	}
	else if(exponent == 0) {
		return 1;
	}
	return base*power(base, exponent-1);
}

void swap(char** set, int pos1, int pos2) {
	char swap_slot = (*set)[pos1];
	(*set)[pos1] = (*set)[pos2];
	(*set)[pos2] = swap_slot;
}
char* ints_to_chars(unsigned int* ints_in, unsigned int len) {
	char chars_out[static_cast<unsigned int>(2*len+1)];
	while (len > 0) {
		chars_out[2*len] = (char)ints_in[len];
		chars_out[2*len-1] = (char)(ints_in[len] >> 8);
		len--;
	}
	return chars_out;
}
