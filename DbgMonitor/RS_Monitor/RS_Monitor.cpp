// RS_Monitor.cpp : �ش� DLL�� �ʱ�ȭ ��ƾ�� �����մϴ�.
//

#include "stdafx.h"
#include "RS_Monitor.h"
#include "dlg/MainDialog.h"


class CDbgMonitorClientProc : public dbg::CDbgMonitorClient
{
public:
	CDbgMonitorClientProc() {}
	virtual ~CDbgMonitorClientProc() {}

protected:

public:
	DECRMI_S2C_ConsoleString
	{
		//::MessageBox(NULL, _T("msg"), _T("Recv Message"), MB_OK );
		// 		g_ClientMessage = msg;
		// 		InvalidateRect(g_hWnd, NULL, TRUE);

		::AfxMessageBox(_T("recv") );

		return true;
	}
};


// CRS_MonitorApp

BEGIN_MESSAGE_MAP(CRS_MonitorApp, CWinApp)
END_MESSAGE_MAP()


// CRS_MonitorApp ����

CRS_MonitorApp::CRS_MonitorApp()
{
}


CRS_MonitorApp::~CRS_MonitorApp()
{

}


// ������ CRS_MonitorApp ��ü�Դϴ�.

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

	dbg::Init(dbg::DbgClient, NULL, new CDbgMonitorClientProc(), "127.0.0.1" );

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