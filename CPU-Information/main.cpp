/*

Author: Forgive
Website: www.github.com/Forgive
Creation Date: 11 - 02 - 2012 (15:14) (By Forgive)
Last Update: 11 - 02 - 2012 (21:00) (By Forgive)

Here we'll put all the functions, include the headers, etc to retrieve the data.

*/

/* Stuff will be organizated better later. :-) */

#pragma once

#include <Windows.h>
#include <iostream>

using namespace std;

// Including proyect files...

#include "wmiquery.h"

int main() {	
	WMIQuery *myQuery = new WMIQuery();

	system("PAUSE");
	return 0;
}