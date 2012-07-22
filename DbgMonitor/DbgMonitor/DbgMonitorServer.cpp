
#include "DbgMonitor.h"
#include "DbgMonitorServer.h"
#include "C2S_stub.cpp"
#include "S2C_proxy.cpp"


using namespace dbg;
using namespace Proud;





namespace dbg
{
	class CServerEventSink : public Proud::INetServerEvent
	{
	public:
		CDbgMonitorServer *m_pServer;// reference
		CServerEventSink(CDbgMonitorServer*pServer) :m_pServer(pServer)
		{
		}

	protected:
		//----------------------------------------------------------------------------------
		// INetServerEvent
		//----------------------------------------------------------------------------------
		virtual void OnClientJoin(Proud::CNetClientInfo *clientInfo) OVERRIDE
		{
			if (m_pServer)
			{
				m_pServer->AddClient(clientInfo->m_HostID);
				m_pServer->ClientJoin(clientInfo->m_HostID);
			}
		}
		virtual void OnClientLeave( Proud::CNetClientInfo *clientInfo, Proud::ErrorInfo *errorInfo, const Proud::ByteArray& comment ) OVERRIDE
		{
			if (m_pServer)
			{
				m_pServer->RemoveClient(clientInfo->m_HostID);
				m_pServer->ClientLeave(clientInfo->m_HostID);
			}
		}
		virtual bool OnConnectionRequest(Proud::AddrPort clientAddr, Proud::ByteArray &userDataFromClient, Proud::ByteArray &reply) OVERRIDE
		{
			return true;
		}
		virtual void OnP2PGroupJoinMemberAckComplete(Proud::HostID groupHostID,Proud::HostID memberHostID,Proud::ErrorType result) OVERRIDE {}
		virtual void OnUserWorkerThreadBegin() OVERRIDE {}
		virtual void OnUserWorkerThreadEnd() OVERRIDE {}
		virtual void OnError(Proud::ErrorInfo *errorInfo) OVERRIDE
		{ 
			//printf("OnError : %s",(LPCSTR)CW2A(errorInfo->ToString())); 
		}
		virtual void OnWarning(Proud::ErrorInfo *errorInfo) OVERRIDE
		{ 
			//printf("OnWarning : %s",(LPCSTR)CW2A(errorInfo->ToString())); 
		}
		virtual void OnInformation(Proud::ErrorInfo *errorInfo) OVERRIDE
		{ 
			//printf("OnInformation : %s",(LPCSTR)CW2A(errorInfo->ToString())); 
		}
		virtual void OnException(Proud::Exception &e) OVERRIDE
		{ 
			//printf("OnInformation : %s",e.what()); 
		}
		virtual void OnNoRmiProcessed(Proud::RmiID rmiID) OVERRIDE {}
	};
}


CDbgMonitorServer::CDbgMonitorServer():
	m_pNetServer(NULL)
,	m_pEventSink(NULL)
,	m_pProxy(NULL)
{

}

CDbgMonitorServer::~CDbgMonitorServer()
{
	if (m_pNetServer) delete m_pNetServer;
	m_pNetServer = NULL;
	if (m_pEventSink) delete m_pEventSink;
	m_pEventSink = NULL;
	if (m_pProxy) delete m_pProxy;
	m_pProxy = NULL;
}

bool CDbgMonitorServer::Init()
{
	if (m_pNetServer)
		return false;

	m_pNetServer = ProudNet::CreateServer();
	m_pEventSink = new CServerEventSink(this);
	m_pProxy = new S2C::Proxy();

	m_pNetServer->SetEventSink(m_pEventSink);
	m_pNetServer->AttachStub(this);
	m_pNetServer->AttachProxy(m_pProxy);

	CStartServerParameter p1;
	p1.m_protocolVersion = Guid();
	p1.m_tcpPort = DBGMONITOR_PORT;
	return m_pNetServer->Start(p1);
}


bool CDbgMonitorServer::AddClient(Proud::HostID hostId)
{
	m_Clients.Add(hostId);
	return true;
}


bool CDbgMonitorServer::RemoveClient(Proud::HostID hostId)
{
	for (int i=0; i < m_Clients.GetCount(); ++i)
	{
		if (hostId == m_Clients[ i])
			m_Clients.RemoveAndPullLast(i);
	}
	return true;
}



void CDbgMonitorServer::Trace( const TCHAR* msg )
{
	for (int i=0; i < m_Clients.GetCount(); ++i)
		m_pProxy->ConsoleString(m_Clients[ i], RmiContext::ReliableSend, dbg::Console_General, 0, Proud::String(msg) );
}
void CDbgMonitorServer::Trace_Scaleform( int movieID, const TCHAR* msg )
{
	for (int i=0; i < m_Clients.GetCount(); ++i)
		m_pProxy->ConsoleString(m_Clients[ i], RmiContext::ReliableSend, dbg::Console_Scaleform, movieID, Proud::String(msg) );
}
void CDbgMonitorServer::Trace_Network( const TCHAR* msg )
{
	for (int i=0; i < m_Clients.GetCount(); ++i)
		m_pProxy->ConsoleString(m_Clients[ i], RmiContext::ReliableSend, dbg::Console_Network, 0, Proud::String(msg) );
}

