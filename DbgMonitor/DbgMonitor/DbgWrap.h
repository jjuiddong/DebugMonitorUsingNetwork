
#pragma once


#include "DbgMonitor.h"
#include "DbgMonitorClient.h"
#include "DbgMonitorServer.h"

namespace dbg
{
	extern eDbgType m_Type;
	extern CDbgMonitorServer *m_pSvr; // reference, �޸����Ŵ� ���⼭ ��
	extern CDbgMonitorClient *m_pClt; // reference, �޸����Ŵ� ���⼭ ��

	void Init( eDbgType type, CDbgMonitorServer *pSvr, CDbgMonitorClient *pClt, const std::string &ip );
	void Clear();
	void FrameMove();	// Only Client


	//-------------------------------------------------------------------------
	// Server Method
	//-------------------------------------------------------------------------
	void Trace( TCHAR *msg );


	//-------------------------------------------------------------------------
	// Client Method
	//-------------------------------------------------------------------------
	void Message( int msg );

};
