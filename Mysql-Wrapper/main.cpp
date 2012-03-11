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
#include <Windows.h>	// For mysql.h to run on Windows
#ifdef __LCC__ 
#include <winsock.h>	// For windows if __LCC__ is defined (default - winsock.h is included in mysql.h)
#endif 
#include <mysql.h>

// Addtional
#include "dbWrapperClass.h"

using namespace std;

int main(void)
{
	DB_wrapper object;
	object.init();
	
	system("PAUSE");
	return 0;
}