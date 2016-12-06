// speechsynthesis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sapi.h"
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
	ISpVoice * pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;
	wstringstream wss;
	string a;
	getline(cin, a);
	if (a == "exit") {
		return true;
	}
	wss << a.c_str();
	wss.str().c_str();
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (SUCCEEDED(hr))
	{
		hr = pVoice->Speak((LPWSTR)wss.str().c_str(), 0, NULL);
		pVoice->Release();
		pVoice = NULL;
	}

	::CoUninitialize();
	main();
}

