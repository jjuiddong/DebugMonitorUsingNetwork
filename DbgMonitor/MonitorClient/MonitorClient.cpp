
// MonitorClient.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "MonitorClient.h"
#include "MonitorClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



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



// CMonitorClientApp

BEGIN_MESSAGE_MAP(CMonitorClientApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMonitorClientApp ����

CMonitorClientApp::CMonitorClientApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CMonitorClientApp ��ü�Դϴ�.

CMonitorClientApp theApp;


// CMonitorClientApp �ʱ�ȭ

BOOL CMonitorClientApp::InitInstance()
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

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));

	CMonitorClientDlg dlg;
	m_pMainWnd = &dlg;

	dbg::Init(dbg::DbgClient, NULL, new CDbgMonitorClientProc(), "127.0.0.1" );

	m_pDlg = new CMonitorClientDlg(NULL);
	m_pDlg->Create(CMonitorClientDlg::IDD);
	m_pMainWnd = m_pDlg;
	m_pDlg->ShowWindow(SW_SHOW);

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
