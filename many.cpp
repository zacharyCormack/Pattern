#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	stringstream command_stream;
	unsigned errors = 0;
	for (unsigned short i = 0; i < 10; ++i)
		for (unsigned short j = 0; j < 63; ++j)
		{
			command_stream << "./main " << j << " Patterns/" << i << '/' << (j < 10 ? "0" : "") << j <<  ' ' << ((float)i)/5-1 << ' ';
			if (system(command_stream.str().c_str()) > 0)
				errors++;
			command_stream.str((string)"");
			usleep(999);
		}
	cout << errors << " errors occured.\n";
	return 0;
}