// RS_Monitor.cpp : �ش� DLL�� �ʱ�ȭ ��ƾ�� �����մϴ�.
//

#include "stdafx.h"
#include "RS_Monitor.h"
#include "dlg/MainDialog.h"
#include "dlg/TabConsolWindow.h"
#include "dlg/TabUIViewer.h"
#include "tinyXml/tinyxml.h"



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

	DECRMI_S2C_SendMessage
	{
		if (theApp.m_pDlg)
		{
// 			CTabConsolWindow *pWnd = theApp.m_pDlg->GetConsolWindow();
// 			pWnd->AddMessage((CTabConsolWindow::eMsgType)consoleType, movieID, message);
			if (msgType == 0)
			{
				HWND hwnd = FindWindow(msg.GetString(), msg.GetString());
				if (!hwnd) return true;

				RECT rect;
				GetWindowRect(hwnd, &rect);

				RECT cr;
				GetWindowRect(theApp.m_pDlg->m_hWnd, &cr);
				const int w = cr.right - cr.left;
				const int h = cr.bottom - cr.top;
				MoveWindow(theApp.m_pDlg->m_hWnd, rect.right, rect.top, w, h, TRUE);		
			}
			else if (msgType == 2)
			{
				std::wstring wstr = msg.GetString();
				std::string str;
				str.assign(wstr.begin(), wstr.end());

				TiXmlDocument doc;
				doc.Parse(str.c_str());

				CTabUIViewer *pWnd = theApp.m_pDlg->GetUIViewr();
				pWnd->SetUITree(&doc);				
			}

		}
		return true;
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


// CRS_MonitorApp ����

CRS_MonitorApp::CRS_MonitorApp():
	m_pDlg(NULL)
{
}
CRS_MonitorApp::~CRS_MonitorApp()
{

}
CRS_MonitorApp theApp;

// CRS_MonitorApp �ʱ�ȭ

BOOL CRS_MonitorApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�.
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));

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
