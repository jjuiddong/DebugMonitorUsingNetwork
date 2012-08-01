
#pragma once

#include "C2S_common.h"


namespace C2S{
	class Stub : public Proud::IRmiStub
	{
	public:
virtual bool Message(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &msg)
{ 
			return false;
		} 
#define DECRMI_C2S_Message bool Message(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &msg)
#define DEFRMI_C2S_Message(DerivedClass) bool DerivedClass::Message(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &msg)
#define CALL_C2S_Message Message(remote,rmiContext,msg)
virtual bool SendMessage(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &msgType,const int &subType,const Proud::String &msg)
{ 
			return false;
		} 
#define DECRMI_C2S_SendMessage bool SendMessage(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &msgType,const int &subType,const Proud::String &msg)
#define DEFRMI_C2S_SendMessage(DerivedClass) bool DerivedClass::SendMessage(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &msgType,const int &subType,const Proud::String &msg)
#define CALL_C2S_SendMessage SendMessage(remote,rmiContext,msgType,subType,msg)
virtual bool ProcessReceivedMessage(Proud::CReceivedMessage &pa, void* hostTag) OVERRIDE;
 
// Rmi name 선언
// Rmi profiler 등 Rmi name을 가리키는 unique pointer이다. 이것이 있으면 strcmp 등을 쓰지 말고 바로 Rmi name pointer 값으로 name 매칭을 할 수 있다.
static LPCWSTR RmiName_Message;
static LPCWSTR RmiName_First;
    static LPCWSTR RmiName_SendMessage;
virtual Proud::RmiID GetFirstRmiID() OVERRIDE { return (Proud::RmiID)Rmi_First; }
		virtual Proud::RmiID GetLastRmiID() OVERRIDE { return (Proud::RmiID)Rmi_Last; }
	};
}

