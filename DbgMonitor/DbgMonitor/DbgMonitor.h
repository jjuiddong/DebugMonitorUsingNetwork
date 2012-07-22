
#pragma once

#include "ProudNet.h"
#include "C2S_stub.h"
#include "S2C_proxy.h"
#include "C2S_proxy.h"
#include "S2C_stub.h"


#ifdef _DEBUG
#pragma comment(lib, "ProudNet_2008_Debug.lib" )
#else
#pragma comment(lib, "ProudNet_2008_Release.lib" )
#endif


namespace dbg
{
	enum eDbgType
	{
		DbgServer,
		DbgClient,
	};

	enum
	{
		DBGMONITOR_PORT=33334,
	};

};
