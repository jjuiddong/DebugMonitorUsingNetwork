
#include "S2C_proxy.h"


namespace S2C{
bool Proxy::SendMessage(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &msgType,const int &subType,const Proud::String &msg)
{
// 여기서 더이상 main lock을 하지 않음.
    // Proud::CriticalSectionLock __lock(m_core->GetCritSec(),true);
	Proud::CMessage __msg;		// CStackAllocMessage 대신 CMessage를 써도 성능상 차이가 적다고 검증됨.
	__msg.UseInternalBuffer();
	
	Proud::RmiID __msgid=(Proud::RmiID)Rmi_SendMessage;
	__msg.Write(__msgid); 
	
__msg << msgType;
__msg << subType;
__msg << msg;

		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_SendMessage, (Proud::RmiID)Rmi_SendMessage);
	}

	bool Proxy::SendMessage(const Proud::HostID *remotes,int remoteCount,Proud::RmiContext &rmiContext,const int &msgType,const int &subType,const Proud::String &msg)
{
// 여기서 더이상 main lock을 하지 않음.
    // Proud::CriticalSectionLock __lock(m_core->GetCritSec(),true);
	Proud::CMessage __msg;		// CStackAllocMessage 대신 CMessage를 써도 성능상 차이가 적다고 검증됨.
	__msg.UseInternalBuffer();
	
	Proud::RmiID __msgid=(Proud::RmiID)Rmi_SendMessage;
	__msg.Write(__msgid); 
	
__msg << msgType;
__msg << subType;
__msg << msg;

		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_SendMessage, (Proud::RmiID)Rmi_SendMessage);
	}

bool Proxy::ConsoleString(Proud::HostID remote,Proud::RmiContext &rmiContext,const int &consoleType,const int &movieID,const Proud::String &message)
{
// 여기서 더이상 main lock을 하지 않음.
    // Proud::CriticalSectionLock __lock(m_core->GetCritSec(),true);
	Proud::CMessage __msg;		// CStackAllocMessage 대신 CMessage를 써도 성능상 차이가 적다고 검증됨.
	__msg.UseInternalBuffer();
	
	Proud::RmiID __msgid=(Proud::RmiID)Rmi_ConsoleString;
	__msg.Write(__msgid); 
	
__msg << consoleType;
__msg << movieID;
__msg << message;

		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_ConsoleString, (Proud::RmiID)Rmi_ConsoleString);
	}

	bool Proxy::ConsoleString(const Proud::HostID *remotes,int remoteCount,Proud::RmiContext &rmiContext,const int &consoleType,const int &movieID,const Proud::String &message)
{
// 여기서 더이상 main lock을 하지 않음.
    // Proud::CriticalSectionLock __lock(m_core->GetCritSec(),true);
	Proud::CMessage __msg;		// CStackAllocMessage 대신 CMessage를 써도 성능상 차이가 적다고 검증됨.
	__msg.UseInternalBuffer();
	
	Proud::RmiID __msgid=(Proud::RmiID)Rmi_ConsoleString;
	__msg.Write(__msgid); 
	
__msg << consoleType;
__msg << movieID;
__msg << message;

		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_ConsoleString, (Proud::RmiID)Rmi_ConsoleString);
	}


// Rmi name 선언
// Rmi profiler 등 Rmi name을 가리키는 unique pointer이다. 이것이 있으면 strcmp 등을 쓰지 말고 바로 Rmi name pointer 값으로 name 매칭을 할 수 있다.
#ifndef HIDE_RMI_NAME_STRING
LPCWSTR Proxy::RmiName_SendMessage=L"SendMessage";
#else
LPCWSTR Proxy::RmiName_SendMessage=L"";
#endif
LPCWSTR Proxy::RmiName_First=RmiName_SendMessage;
    #ifndef HIDE_RMI_NAME_STRING
LPCWSTR Proxy::RmiName_ConsoleString=L"ConsoleString";
#else
LPCWSTR Proxy::RmiName_ConsoleString=L"";
#endif
}

