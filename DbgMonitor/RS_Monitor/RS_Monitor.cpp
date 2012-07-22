// RS_Monitor.cpp : 해당 DLL의 초기화 루틴을 정의합니다.
//

#include "stdafx.h"
#include "RS_Monitor.h"
#include "dlg/MainDialog.h"
#include "dlg/TabConsolWindow.h"


class CDbgMonitorClientProc : public dbg::CDbgMonitorClient
{
public:
	CDbgMonitorClientProc() {}
	virtual ~CDbgMonitorClientProc() {}

protected:

public:
	virtual void Connect() override
	{
		if (theApp.m_pDlg)
			theApp.m_pDlg->SetWindowText(_T("RSMonitor Connected.."));
	}
	virtual void DisConnect() override
	{
		if (theApp.m_pDlg)
			theApp.m_pDlg->SetWindowText(_T("DisConnect.."));
	}

	DECRMI_S2C_ConsoleString
	{
		if (theApp.m_pDlg)
		{
			CTabConsolWindow *pWnd = theApp.m_pDlg->GetConsolWindow();
			pWnd->AddMessage((CTabConsolWindow::eMsgType)consoleType, movieID, message);
		}
		return true;
	}
};


// CRS_MonitorApp

BEGIN_MESSAGE_MAP(CRS_MonitorApp, CWinApp)
END_MESSAGE_MAP()


// CRS_MonitorApp 생성

CRS_MonitorApp::CRS_MonitorApp():
	m_pDlg(NULL)
{
}
CRS_MonitorApp::~CRS_MonitorApp()
{

}
CRS_MonitorApp theApp;

// CRS_MonitorApp 초기화

BOOL CRS_MonitorApp::InitInstance()
{
	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다.
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 응용 프로그램 마법사에서 생성된 응용 프로그램"));

	m_pDlg = new CMainDialog(NULL);
	m_pDlg->Create(CMainDialog::IDD);
	m_pMainWnd = m_pDlg;
	m_pDlg->ShowWindow(SW_SHOW);
	m_pDlg->SetWindowText(_T("Wait Connect"));

	std::wstring ip = _T("127.0.0.1");

	int argCount;
	LPWSTR *argList = CommandLineToArgvW(GetCommandLine(), &argCount);
	if (argCount > 1)
	{
		ip = argList[ 1];
	}

	dbg::Init(m_pDlg->m_hWnd, dbg::DbgClient, NULL, new CDbgMonitorClientProc(), ip );

	while (m_pDlg->IsRunning())
	{
		MSG msg;
		while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				::PostQuitMessage(111); //just return code, it is up to you what value
				break;
			}
			if (!PreTranslateMessage(&msg))
			{
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}
		}

		dbg::FrameMove();
	}

	dbg::Clear();
	return FALSE;
}
