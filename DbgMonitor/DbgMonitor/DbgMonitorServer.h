#pragma once

#include "C2S_stub.h"

namespace dbg
{
	class CServerEventSink;
	class CDbgMonitorServer : public C2S::Stub
	{
	public:
		CDbgMonitorServer();
		virtual ~CDbgMonitorServer();

	protected:
		Proud::CNetServer *m_pNetServer;
		CServerEventSink *m_pEventSink;
		S2C::Proxy *m_pProxy;

		Proud::CFastArray<Proud::HostID> m_Clients;

	public:
		bool			Init();
		bool			AddClient(Proud::HostID hostId);
		bool			RemoveClient(Proud::HostID hostId);
		virtual void	ClientJoin(Proud::HostID hostId) {}
		virtual void	ClientLeave(Proud::HostID hostId) {}
		S2C::Proxy*		GetProxy() { return m_pProxy; }

		//---------------------------------------------------------------
		// DebugMonitor Method
		//---------------------------------------------------------------
		void			Trace( const TCHAR* msg);
		void			Trace_Scaleform( int movieID, const TCHAR* msg);
		void			Trace_Network( const TCHAR* msg);
		void			Message( int msgType, int subType, const TCHAR *msg );

		// Stub
		DECRMI_C2S_Message override { return true; }
	};
};
