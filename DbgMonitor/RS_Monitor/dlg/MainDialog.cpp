// DlgMonitor.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "../RS_Monitor.h"
#include "MainDialog.h"
#include "../tool/DbgMessageListener.h"

#include "TabConsolWindow.h"
#include "TabControlWindow.h"
#include "TabUIViewer.h"
#include "TabNetworkWindow.h"


// CDlgMonitor 대화 상자입니다.

CDbgMessageListener *CMainDialog::s_pListener = NULL;


CMainDialog::CMainDialog(CWnd* pParent /*=NULL*/)
: CDialog(CMainDialog::IDD, pParent)
,	m_pTabConsolWindow(NULL)
,	m_pTabControlWindow(NULL)
,	m_IsRunning(TRUE)
{

}

CMainDialog::~CMainDialog()
{
	delete m_pTabConsolWindow;
	delete m_pTabControlWindow;
	delete m_pTabUIViewer;
	delete m_pTabNetworkWindow;

}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_TabMain);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgMonitor 메시지 처리기입니다.

BOOL CMainDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	CWnd *pParent = GetParent();
	if (pParent)
	{
		CRect Rect;
		pParent->GetWindowRect(Rect);
		CRect curR;
		GetWindowRect(curR);

		curR.OffsetRect(Rect.right, Rect.top+20);
		MoveWindow(curR);
	}

	m_pTabConsolWindow = new CTabConsolWindow(&m_TabMain);
	m_pTabConsolWindow->Create(CTabConsolWindow::IDD, &m_TabMain);

	m_pTabControlWindow = new CTabControlWindow(&m_TabMain);
	m_pTabControlWindow->Create(CTabControlWindow::IDD, &m_TabMain);

	m_pTabUIViewer = new CTabUIViewer(&m_TabMain);
	m_pTabUIViewer->Create(CTabUIViewer::IDD, &m_TabMain);
	//m_pTabUIViewer->SetUITree(NULL);

	m_pTabNetworkWindow = new CTabNetworkWindow(&m_TabMain);
	m_pTabNetworkWindow->Create(CTabNetworkWindow::IDD, &m_TabMain);

	m_TabMain.InsertTab( 0, _T("Console"), m_pTabConsolWindow );
	m_TabMain.InsertTab( 1, _T("UI"), m_pTabUIViewer);
	m_TabMain.InsertTab( 2, _T("Value"), m_pTabControlWindow);
	m_TabMain.InsertTab( 3, _T("Network"), m_pTabNetworkWindow);
	m_TabMain.ShowTab( 0 );

	return TRUE;  // return TRUE unless you set the focus to a control
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CMainDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	m_TabMain.OnSize(nType, cx, cy);
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CMainDialog::SendDbgMessage(int id, LPARAM lParam, WPARAM wParam)
{
	if (s_pListener)
		s_pListener->Message(id, lParam, wParam);
}

void CMainDialog::OnOK()
{
	m_IsRunning = FALSE;
	CDialog::OnOK();
}

void CMainDialog::OnCancel()
{
	m_IsRunning = FALSE;
	CDialog::OnCancel();
}

BOOL CMainDialog::DestroyWindow()
{
	m_IsRunning = FALSE;
	return CDialog::DestroyWindow();
}
