#pragma once

namespace dbg
{
	enum msg
	{
		REFRESH_UITREE=0,			// UITree 업데이트

		REFRESH_NETLISTENER,	// 네트워크 리스너 출력

		RELOAD_UIWINDOW,		// UIWindow 재로딩
			// arg1: UIWindow 클래스 포인터

		GOTO_LOGINSERVER,		// 접속을 끊고 로그인서버 접속씬으로 이동한다.

	};

};