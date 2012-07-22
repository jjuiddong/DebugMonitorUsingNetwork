
#pragma once

#include "ProudNet.h"
#include "C2S_stub.h"
#include "S2C_proxy.h"

#ifdef _DEBUG
#pragma comment(lib, "ProudNet_2008_Debug.lib" )
#else
#pragma comment(lib, "ProudNet_2008_Release.lib" )
#endif


#define DBGMONITOR_PORT		33334


enum eDbgType
{
	DbgServer,
	DbgClient,
};

