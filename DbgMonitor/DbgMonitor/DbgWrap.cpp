
#include "DbgWrap.h"


using namespace dbg;

namespace dbg
{
	eDbgType m_Type = DbgClient;
	CDbgMonitorServer *m_pSvr = NULL; // reference, 메모리제거는 여기서 함
	CDbgMonitorClient *m_pClt = NULL; // reference, 메모리제거는 여기서 함

};


// Client로 동작할때만 ip값이 필요하다.
void dbg::Init( eDbgType type, CDbgMonitorServer *pSvr, CDbgMonitorClient *pClt, const std::string &ip )
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
			m_pClt->Init( _T("127.0.0.1") );
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


void dbg::Trace( TCHAR *msg )
{
 	if (m_pSvr)
		m_pSvr->Trace(msg);
}


void dbg::Message( int msg )
{
	if (m_pClt)
		m_pClt->Message(msg);
}
