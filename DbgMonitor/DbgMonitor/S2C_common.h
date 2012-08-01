
#pragma once


namespace S2C{
	// 각 Rmi 메서드에 대응하는 메시지 ID
	enum RmiID
	{   
		Rmi_First = (2000),
Rmi_SendMessage = (2000 + 1),

Rmi_ConsoleString = (2000 + 2),

    Rmi_Last
	};

}

