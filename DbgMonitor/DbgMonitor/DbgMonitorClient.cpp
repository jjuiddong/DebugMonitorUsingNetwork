
#include "DbgMonitor.h"
#include "DbgMonitorClient.h"
#include "C2S_proxy.h"
#include "C2S_proxy.cpp"
#include "S2C_stub.h"
#include "S2C_stub.cpp"


using namespace dbg;
using namespace Proud;


namespace dbg
{
	class CClientEventSink : public Proud::INetClientEvent
	{
	public:
		CDbgMonitorClient *m_pClient;
		CClientEventSink(CDbgMonitorClient *pClient) : m_pClient(pClient)
		{
		}

		virtual void OnJoinServerComplete(Proud::ErrorInfo *info,
			const Proud::ByteArray &replyFromServer) OVERRIDE
		{
			if (info->m_errorType == Proud::ErrorType_Ok)
			{
				if (m_pClient)
				{
					m_pClient->SetState(CDbgMonitorClient::State_Connect);
					m_pClient->Connect();
				}				
			}		
 			else
			{
				if (m_pClient)
				{
					m_pClient->SetState(CDbgMonitorClient::State_Close);
					m_pClient->DisConnect();
				}
			}
		}

		virtual void OnLeaveServer(Proud::ErrorInfo *errorInfo) OVERRIDE
		{
			if (m_pClient)
			{
				m_pClient->SetState(CDbgMonitorClient::State_Close);
				m_pClient->DisConnect();
			}
		}
		virtual void OnP2PMemberJoin(Proud::HostID memberHostID, Proud::HostID groupHostID,
			int memberCount, const Proud::ByteArray &customField) OVERRIDE
		{
		}
		virtual void OnP2PMemberLeave(Proud::HostID memberHostID, Proud::HostID groupHostID,
			int memberCount) OVERRIDE
		{
		}
		virtual void OnChangeServerUdpState(Proud::ErrorType reason)
		{
			//printf("OnChangeServerUdpState : %d\n", (int)reason);
		}
		virtual void OnChangeP2PRelayState(Proud::HostID remoteHostID, Proud::ErrorType reason) OVERRIDE 
		{
			//printf("OnChangeP2PRelayState : %d\n", (int)reason);
		}
		virtual void OnSynchronizeServerTime() OVERRIDE {}

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
};


CDbgMonitorClient::CDbgMonitorClient() :
	m_pClient(NULL)
,	m_pEventSink(NULL)
,	m_pProxy(NULL)
,	m_State(State_WaitConnect)
{

}

CDbgMonitorClient::~CDbgMonitorClient()
{
	if (m_pClient) delete m_pClient;
	m_pClient = NULL;
	if (m_pEventSink) delete m_pEventSink;
	m_pEventSink = NULL;
	if (m_pProxy) delete m_pProxy;
	m_pProxy = NULL;
}


bool CDbgMonitorClient::Init(const Proud::String &ip)
{
	m_pClient = Proud::CNetClient::Create();
	m_pEventSink = new CClientEventSink(this);
	m_pProxy = new C2S::Proxy();

	m_pClient->SetEventSink(m_pEventSink);
	m_pClient->AttachProxy(m_pProxy);
	m_pClient->AttachStub(this);

	Proud::CNetConnectionParam cp;
	cp.m_protocolVersion = Proud::Guid(); 
	//cp.m_serverIP = L"192.168.77.144";	// Address of server
	cp.m_serverIP = ip;
	cp.m_serverPort = 33334;	// Port of server

	m_pClient->Connect(cp);

	return true;
}


// Network가 끊기면 false를 리턴한다.
bool CDbgMonitorClient::FrameMove()
{
	if (State_Close == m_State)
		return false;
	if (!m_pClient)
		return false;

	m_pClient->FrameMove();
	return true;
}


void CDbgMonitorClient::Message( int message )
{
	if (m_pProxy)
		m_pProxy->Message( Proud::HostID_Server, Proud::RmiContext::ReliableSend, message );
}
void CDbgMonitorClient::Message( int msgType, int subType, const TCHAR *msg )
{
	if (m_pProxy)
		m_pProxy->SendMessage( Proud::HostID_Server, Proud::RmiContext::ReliableSend, msgType, subType, Proud::String(msg) );
}
