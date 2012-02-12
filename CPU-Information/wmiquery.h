/*

Author: Forgive
Website: www.github.com/Forgive
Creation Date: 11 - 02 - 2012 (16:14) (By: Forgive)
Last Update: 11 - 02 - 12 (20:29) (By: Forgive)

This is the code to retrieve some data using WMI (Windows Management Instrumentation). 

*/

#include <comdef.h>
#include <WbemIdl.h>

#pragma comment(lib, "wbemuuid.lib")

class WMIQuery {
public:
	WMIQuery();
	void initialize();
	VARIANT requestData(const char* WMIClass, const LPCWSTR dataName);
	void clearData();

private:
	HRESULT result;
	IWbemLocator *locator;
	IWbemServices *services;
	IEnumWbemClassObject *enumerator;
	IWbemClassObject *object;
	VARIANT returnVariant;
};
