
#include "DbgWrap.h"


using namespace dbg;

namespace dbg
{
	eDbgType m_Type = DbgClient;
	CDbgMonitorServer *m_pSvr = NULL; // reference, �޸����Ŵ� ���⼭ ��
	CDbgMonitorClient *m_pClt = NULL; // reference, �޸����Ŵ� ���⼭ ��

};


// Client�� �����Ҷ��� ip���� �ʿ��ϴ�.
void dbg::Init( eDbgType type, CDbgMonitorServer *pSvr, CDbgMonitorClient *pClt, const std::wstring &ip )
{
	m_Type = type;
	m_pSvr = pSvr;
	m_pClt = pClt;
	if (DbgServer == m_Type)
	{
		if (m_pSvr)
			m_pSvr->Init();
	}
	else
	{
 		if (m_pClt)
			m_pClt->Init( ip.c_str());
	}
}

void dbg::Clear()
{
	if (m_pSvr) delete m_pSvr;
	m_pSvr = NULL;
	if (m_pClt) delete m_pClt;
	m_pClt = NULL;
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
