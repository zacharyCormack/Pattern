#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>
using namespace std;

int main()
{
	stringstream command_stream;
	system("clear");
	for (unsigned short i = 0; i < 64; ++i)
	{
		system("clear");
		usleep(125000);
		unsigned x = rand() % 10;
		unsigned y = rand() % 62 + 1;
		cout << "\e[" << 64-y << 'B' << "Pattern " << x << " " << (y < 10 ? "0" : "") << y << ", the " << i+1;
		if (i == 10 || i == 11 || i == 12)
			cout << "th ";
		else
			switch (i % 10)
			{
			case 0:
				cout << "st ";
				break;
			case 1:
				cout << "nd ";
				break;
			case 2:
				cout << "rd ";
				break;
			default:
				cout << "th ";
				break;
			}
		cout << "pattern shown of 64.";
		command_stream << "cat Patterns/" << x << '/' << (y < 10 ? "0" : "") << y;
		system(command_stream.str().c_str());
		command_stream.str((string)"");
		cout << endl;
		usleep(875000);
	}
	system("clear");
	return 0;
}