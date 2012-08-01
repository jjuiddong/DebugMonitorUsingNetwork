
#include "DbgWrap.h"


using namespace dbg;

namespace dbg
{
	eDbgType m_Type = DbgClient;
	CDbgMonitorServer *m_pSvr = NULL;
	CDbgMonitorClient *m_pClt = NULL;

};


// Client로 동작할때만 ip값이 필요하다.
void dbg::Init( HWND hWnd, eDbgType type, CDbgMonitorServer *pSvr, CDbgMonitorClient *pClt, const std::wstring &ip )
{
	m_Type = type;
	m_pSvr = pSvr;
	m_pClt = pClt;
	if (DbgServer == m_Type)
	{
		if (m_pSvr)
		{
			m_pSvr->Init();
			ShellExecute(NULL, _T("open"), _T("RS_Monitor.exe"), ip.c_str(), NULL, SW_SHOW);
		}
	}
	else
	{
 		if (m_pClt)
			m_pClt->Init( ip.c_str());
	}
}

bool dbg::IsEnable() 
{ 
	return (m_pClt) || (m_pSvr);
}

void dbg::Clear()
{
}


// Only Client
void dbg::FrameMove()
{
	if (DbgClient == m_Type)
		if (m_pClt)
			m_pClt->FrameMove();
}


void dbg::Message( int msg )
{
	if (m_pClt)
		m_pClt->Message(msg);
}

void dbg::Trace( const TCHAR* pcszFormat, ... )
{
	if (m_pSvr)
	{
		VA_MAKE_M(buffer, pcszFormat);
		m_pSvr->Trace(buffer);
	}
}

void dbg::Trace_Scaleform( int movieID, const TCHAR* pcszFormat, ... )
{
	if (m_pSvr)
	{
		VA_MAKE_M(buffer, pcszFormat);
		m_pSvr->Trace_Scaleform(movieID, buffer);
	}
}

void dbg::Trace_Network( const TCHAR* pcszFormat, ... )
{
	if (m_pSvr)
	{
		VA_MAKE_M(buffer, pcszFormat);
		m_pSvr->Trace_Network(buffer);
	}
}

void dbg::Message( int msgType, int subType, const TCHAR* pcszFormat, ... )
{
	VA_MAKE_M(buffer, pcszFormat);
	if (m_pSvr)
	{
		m_pSvr->Message(msgType, subType, buffer);
	}
	if (m_pClt)
	{
		m_pClt->Message(msgType, subType, buffer);
	}
}


void dbg::SetTitleName(const TCHAR *titleName)
{
}

float dbg::GetValue(int idx) 
{ 
	return 0;
}
void dbg::SetValue(int idx, float v) 
{
}
//	void SetUITree(ui::CUINode *pNode) {}
void dbg::SetMouseOverUI(int movieID) 
{
}

