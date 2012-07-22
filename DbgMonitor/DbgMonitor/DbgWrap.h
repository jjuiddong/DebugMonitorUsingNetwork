
#pragma once


#include "DbgMonitor.h"
#include "DbgMonitorClient.h"
#include "DbgMonitorServer.h"

namespace dbg
{
	extern eDbgType m_Type;
	extern CDbgMonitorServer *m_pSvr; // reference, �޸����Ŵ� ���⼭ ��
	extern CDbgMonitorClient *m_pClt; // reference, �޸����Ŵ� ���⼭ ��

	void Init( eDbgType type, CDbgMonitorServer *pSvr, CDbgMonitorClient *pClt, const std::wstring &ip );
	void Clear();
	void FrameMove();	// Only Client


	//-------------------------------------------------------------------------
	// Server Method
	//-------------------------------------------------------------------------
	void Trace( const TCHAR* pcszFormat, ... );
	void Trace_Scaleform( int movieID, const TCHAR* pcszFormat, ... );
	void Trace_Network( const TCHAR* pcszFormat, ... );


	//-------------------------------------------------------------------------
	// Client Method
	//-------------------------------------------------------------------------
	void Message( int msg );

};
