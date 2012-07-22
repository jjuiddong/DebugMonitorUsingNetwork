#pragma once

#include "S2C_stub.h"


namespace dbg
{
	class CClientEventSink;
	class CDbgMonitorClient : public S2C::Stub
	{
	public:
		CDbgMonitorClient();
		virtual ~CDbgMonitorClient();

		enum eClientState
		{
			WaitConnect,
			Connect,
			Close
		};

	protected:
		Proud::CNetClient *m_pClient;
		CClientEventSink *m_pEventSink;
		C2S::Proxy *m_pProxy;
		eClientState m_State;

	public:
		bool Init(const Proud::String &ip);
		bool FrameMove();
		void SetState(eClientState state) { m_State = state; }

	};
};
