/*

Author: Forgive
Website: www.github.com/Forgive
Creation Date: 11 - 02 - 2012 (15:14) (By Forgive)
Creation Date: 11 - 02 - 2012 (16:19) (By Forgive)

Here we'll put all the functions, include the headers, etc to retrieve the data.

*/

/* Stuff will be organizated better later. :-) */

#pragma once

#include <Windows.h>
#include <iostream>

// Including proyect files...

#include "wmiquery.h"

using namespace std;

int main() {

	WMIQuery *myQuery = new WMIQuery();

	system("PAUSE");
	return 0;
}