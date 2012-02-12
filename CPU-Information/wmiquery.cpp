/*

Author: Forgive
Website: www.github.com/Forgive
Creation Date: 11 - 02 - 2012 (16:14) (By: Forgive)
Last Update: 11 - 02 - 12 (21:00) (By: Forgive)

This is the code to retrieve some data using WMI (Windows Management Instrumentation). 

*/
#include "wmiquery.h"

WMIQuery::WMIQuery() {
	initialize();
}

void WMIQuery::initialize() {
	result = CoInitializeEx(0, COINIT_MULTITHREADED);
	result = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
	locator = NULL;
	result = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID*) &locator);
	services = NULL;
	result = locator->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &services);
	result = CoSetProxyBlanket(services, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE);
	enumerator = NULL;
}

VARIANT WMIQuery::requestData(const char* WMIClass, LPCWSTR dataName) {
	result = services->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM ") + bstr_t(WMIClass), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &enumerator);
	ULONG uReturn;
	while(enumerator) {
		HRESULT result = enumerator->Next(WBEM_INFINITE, 1, &object, &uReturn);
		if(0 == uReturn) {
			break;
		}
		result = object->Get(dataName, 0, &returnVariant, 0, 0);
		return returnVariant;
	}
	return returnVariant;
}

void WMIQuery::clearData() {
	services->Release();
	locator->Release();
	enumerator->Release();
	object->Release();
	CoUninitialize();
}