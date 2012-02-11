/*

Author: Forgive
Website: www.github.com/Forgive
Creation Date: 11 - 02 - 2012 (16:14) (By: Forgive)
Last Update: 11 - 02 - 12 (16:15) (By: Forgive)

This is the code to retrieve some data using WMI (Windows Management Instrumentation). 

*/

#include <comdef.h>
#include <WbemIdl.h>

#pragma comment(lib, "wbemuuid.lib")

class WMIQuery {
public:
	WMIQuery();
	VARIANT requestData(const char* WMIClass, const LPCWSTR dataName);

private:
	HRESULT result;
	IWbemLocator *locator;
	IWbemServices *services;
	IEnumWbemClassObject *enumerator;
	IWbemClassObject *object;
	VARIANT returnVariant;
};
