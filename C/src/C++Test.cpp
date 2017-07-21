//============================================================================
// Name        : C++Test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "Interface.h"
#include "Impl1.h"
#include "Impl2.h"

using namespace std;

int main()
{
	vector<Interface*> aList;

	aList.push_back(new Impl1());
	aList.push_back(new Impl2());

	for (vector<Interface*>::iterator it = aList.begin(); it != aList.end();
	        ++it)
	{
		Interface* face = *it;
		face->saySomething();
	}

	return 0;
}


