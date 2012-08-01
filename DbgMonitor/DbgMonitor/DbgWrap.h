
#pragma once


#include "DbgMonitor.h"
#include "DbgMonitorClient.h"
#include "DbgMonitorServer.h"

namespace dbg
{
	extern eDbgType m_Type;
	extern CDbgMonitorServer *m_pSvr;
	extern CDbgMonitorClient *m_pClt;

	void Init( HWND hWnd, eDbgType type, CDbgMonitorServer *pSvr, CDbgMonitorClient *pClt, const std::wstring &ip);
	void Clear();
	void FrameMove();	// Only Client
	bool IsEnable();

	//-------------------------------------------------------------------------
	// 아직 구현 안됨
	//-------------------------------------------------------------------------
	void SetTitleName(const TCHAR *titleName);
	float GetValue(int idx); // idx=0~7 {}
	void SetValue(int idx, float v); // idx=0~7 {}
	//	void SetUITree(ui::CUINode *pNode) {}
	void SetMouseOverUI(int movieID);
	//	void SetNetwork(CNetManager *pNetMng) {}

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

	//-------------------------------------------------------------------------
	// Common Method
	//-------------------------------------------------------------------------
	void Message( int msgType, int subType, const TCHAR* pcszFormat, ... );


};
