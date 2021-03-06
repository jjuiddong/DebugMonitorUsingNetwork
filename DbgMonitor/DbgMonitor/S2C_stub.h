﻿
#pragma once

#include "S2C_common.h"


namespace S2C{
	class Stub : public Proud::IRmiStub
	{
	public:
virtual bool SendMessage(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &msgType,const int &subType,const Proud::String &msg)
{ 
			return false;
		} 
#define DECRMI_S2C_SendMessage bool SendMessage(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &msgType,const int &subType,const Proud::String &msg)
#define DEFRMI_S2C_SendMessage(DerivedClass) bool DerivedClass::SendMessage(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &msgType,const int &subType,const Proud::String &msg)
#define CALL_S2C_SendMessage SendMessage(remote,rmiContext,msgType,subType,msg)
virtual bool ConsoleString(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &consoleType,const int &movieID,const Proud::String &message)
{ 
			return false;
		} 
#define DECRMI_S2C_ConsoleString bool ConsoleString(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &consoleType,const int &movieID,const Proud::String &message)
#define DEFRMI_S2C_ConsoleString(DerivedClass) bool DerivedClass::ConsoleString(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &consoleType,const int &movieID,const Proud::String &message)
#define CALL_S2C_ConsoleString ConsoleString(remote,rmiContext,consoleType,movieID,message)
virtual bool ProcessReceivedMessage(Proud::CReceivedMessage &pa, void* hostTag) OVERRIDE;
 
// Rmi name 선언
// Rmi profiler 등 Rmi name을 가리키는 unique pointer이다. 이것이 있으면 strcmp 등을 쓰지 말고 바로 Rmi name pointer 값으로 name 매칭을 할 수 있다.
static LPCWSTR RmiName_SendMessage;
static LPCWSTR RmiName_First;
    static LPCWSTR RmiName_ConsoleString;
virtual Proud::RmiID GetFirstRmiID() OVERRIDE { return (Proud::RmiID)Rmi_First; }
		virtual Proud::RmiID GetLastRmiID() OVERRIDE { return (Proud::RmiID)Rmi_Last; }
	};
}

