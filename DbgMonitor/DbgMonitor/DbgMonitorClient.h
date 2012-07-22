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
			State_WaitConnect,
			State_Connect,
			State_Close
		};

	protected:
		Proud::CNetClient *m_pClient;
		CClientEventSink *m_pEventSink;
		C2S::Proxy *m_pProxy;
		eClientState m_State;

	public:
		bool			Init(const Proud::String &ip);
		bool			FrameMove();
		virtual void	Connect() {}
		virtual void	DisConnect() {}
		C2S::Proxy*		GetProxy() { return m_pProxy; }
		void			SetState(eClientState state) { m_State = state; }

		//---------------------------------------------------------------
		// DebugMonitor Method
		//---------------------------------------------------------------
		void Message( int message );

	};
};
