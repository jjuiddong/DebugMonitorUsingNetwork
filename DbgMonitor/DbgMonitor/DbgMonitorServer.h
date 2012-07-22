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
		bool Init();
		bool AddClient(Proud::HostID hostId);
		bool RemoveClient(Proud::HostID hostId);

		// Stub
		DECRMI_C2S_Message;
	};
};
