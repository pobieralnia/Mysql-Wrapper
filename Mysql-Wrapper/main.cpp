/**
 * Filename main.cpp
 * 
 * @author		Tomasz
 * @date		2012-03-11
 */

// System
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

// Addtional
#include "dbWrapperClass.h"

using namespace std;

int main(void)
{
	DB_wrapper object;
	object.init();
	object.get_result("SELECT * FROM users_panel");

	while (object.fetch_row())
	{
		cout << "W srodku" << endl;
		string name = object.get_value(2);
		printf("User %s\n", name.c_str() );
	}

	object.free();

	system("PAUSE");
	return 0;
}