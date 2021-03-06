// GameClient.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "GameClient.h"
#include  <string>
#include <iostream>
#include <sstream>
#include <shellapi.h>
#include <atlconv.h>

using namespace std;
#include <string>
#include "tinyXml/tinyxml.h"



#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;								// 현재 인스턴스입니다.
TCHAR szTitle[MAX_LOADSTRING];					// 제목 표시줄 텍스트입니다.
TCHAR szWindowClass[MAX_LOADSTRING];			// 기본 창 클래스 이름입니다.
int g_ClientMessage = 1;
HWND g_hWnd;


#ifdef _DEBUG
	#	pragma comment(lib, "../Debug/DbgMonitor_Debug_Win32.lib" )
#else
	#	pragma comment(lib, "../Release/DbgMonitor_Release_Win32.lib" )
#endif


class CDbgMonitorProc : public dbg::CDbgMonitorServer
{
public:
	CDbgMonitorProc() {}
	virtual ~CDbgMonitorProc() {}

protected:

public:
	virtual void ClientJoin(Proud::HostID hostId) override
	{
		m_pProxy->SendMessage(hostId,  Proud::RmiContext::ReliableSend, 0, 0, _T("GameClient"));

	}

	DECRMI_C2S_Message
	{
		g_ClientMessage = msg;
		InvalidateRect(g_hWnd, NULL, TRUE);
		return true;
	}
};

CDbgMonitorProc *g_pDbgMonitorProc = NULL;

std::wstring format(const wchar_t *fmt, ...) 
{ 
	using std::wstring;
	using std::vector;

	wstring retStr(_T(""));

	if (NULL != fmt)
	{
		va_list marker = NULL; 

		// initialize variable arguments
		va_start(marker, fmt); 

		// Get formatted string length adding one for NULL
		size_t len = _vscwprintf(fmt, marker) + 1;

		// Create a char vector to hold the formatted string.
		vector<wchar_t> buffer(len, '\0');
		int nWritten = _vsnwprintf_s(&buffer[0], buffer.size(), len, fmt, marker);    

		if (nWritten > 0)
		{
			retStr = &buffer[0];
		}

		// Reset variable arguments
		va_end(marker); 
	}

	return retStr; 
}


template <class T>
std::wstring to_string(T t, std::ios_base & (*f)(std::ios_base&))
{
	std::wostringstream oss;
	oss << f << t;
	return oss.str();
}





// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 여기에 코드를 입력합니다.
	MSG msg;
	HACCEL hAccelTable;

	// 전역 문자열을 초기화합니다.
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_GAMECLIENT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다.
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMECLIENT));

	// 기본 메시지 루프입니다.
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	delete g_pDbgMonitorProc;
	return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
//  설명:
//
//    Windows 95에서 추가된 'RegisterClassEx' 함수보다 먼저
//    해당 코드가 Win32 시스템과 호환되도록
//    하려는 경우에만 이 함수를 사용합니다. 이 함수를 호출해야
//    해당 응용 프로그램에 연결된
//    '올바른 형식의' 작은 아이콘을 가져올 수 있습니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAMECLIENT));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_GAMECLIENT);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
   g_hWnd = hWnd;

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   // DebugMonitor Server 생성
   g_pDbgMonitorProc = new CDbgMonitorProc();
   dbg::Init(hWnd, dbg::DbgServer, g_pDbgMonitorProc, NULL, _T(""));

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND	- 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT	- 주 창을 그립니다.
//  WM_DESTROY	- 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 메뉴의 선택 영역을 구문 분석합니다.
		switch (wmId)
		{
		case IDM_ABOUT:
//			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);
			// TODO: 여기에 그리기 코드를 추가합니다.
			std::wstring str;
			str = to_string<int>(g_ClientMessage, std::dec);
			TextOut(hdc, 100, 100, str.c_str(), str.length());
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_KEYDOWN:
		{
			switch (wParam)
			{
			case VK_END:
				dbg::Trace( _T("aaaa") );
				break;
			case VK_HOME:
				dbg::Trace_Scaleform( 1, _T("bbbb") );
				break;
			case VK_DELETE:
				dbg::Trace_Network( _T("ccc") );
				break;

			case VK_RETURN:
				{
					TiXmlDocument doc;
					TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
					TiXmlElement * element = new TiXmlElement( "Hello" );
					element->LinkEndChild(new TiXmlText( "World" ));
					TiXmlElement * element2 = new TiXmlElement( "Youarea" );
					element2->LinkEndChild(new TiXmlText( "Girl" ));
					TiXmlElement * element3 = new TiXmlElement( "Iama" );
					element3->LinkEndChild(new TiXmlText( "Boy" ));
					element2->LinkEndChild(element3);

					doc.LinkEndChild( decl );
					doc.LinkEndChild( element );
					doc.LinkEndChild( element2 );

					std::string str;
					str << doc;
					std::wstring wstr;
					wstr.assign(str.begin(), str.end());
					dbg::Message( 1, 0, wstr.c_str() );
				}
				break;
			}
		}
		break;
	case WM_DESTROY:
		dbg::Clear();
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
