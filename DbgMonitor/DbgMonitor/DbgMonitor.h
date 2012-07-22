
#pragma once

#include "ProudNet.h"
#include "C2S_stub.h"
#include "S2C_proxy.h"
#include "C2S_proxy.h"
#include "S2C_stub.h"


#ifdef _DEBUG
#pragma comment(lib, "ProudNet_2008_Debug_static_CRT.lib" )
#else
#pragma comment(lib, "ProudNet_2008_Release_static_CRT.lib" )
#endif


// 가변인자값을 받아서 버퍼에 저장한다.
#define VA_MAKE_M(buffer, format)\
	TCHAR buffer[256];\
{\
	va_list ap;\
	va_start(ap, format);\
	_vstprintf_s(buffer, format, ap);\
	va_end(ap);\
}\


namespace dbg
{
	enum eDbgType
	{
		DbgServer,
		DbgClient,
	};

	enum eConsoleType
	{
		Console_General,
		Console_Network,
		Console_Scaleform,		
	};

	enum
	{
		DBGMONITOR_PORT=33334,
	};

};
