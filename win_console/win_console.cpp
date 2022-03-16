// win_console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fint.h"

using namespace m31;
using namespace std;

void Example() {
	auto v1 = FInt(1);
	auto v2 = FInt(0.5f);

	if (v1 > v2)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}


	auto v3 = v1 << 1;
	cout << v3.ToString() << endl;

}

void Example2() {
	auto v1 = FInt(10);
	auto v2 = FInt(-0.3f);
	
	cout << (v1>>1).RawInt() << endl;

	auto v3 = FInt(2);
	auto v4 = FInt(0.5f);
	cout << (v3 / v4).ToString() << endl;
	cout << (v3 / 0.5f).ToString() << endl;

}

int main()
{
    //Example();
    
	Example2();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
