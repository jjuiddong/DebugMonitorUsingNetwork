// DlgMainMonitor.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "RS_Monitor.h"
#include "DlgMainMonitor.h"


// CDlgMainMonitor 대화 상자입니다.


CDlgMainMonitor::CDlgMainMonitor(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMainMonitor::IDD, pParent)
{

}

CDlgMainMonitor::~CDlgMainMonitor()
{

}

void CDlgMainMonitor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMainMonitor, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgMainMonitor::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgMainMonitor::OnBnClickedCancel)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CDlgMainMonitor::OnTcnSelchangeTabMain)
END_MESSAGE_MAP()


// CDlgMainMonitor 메시지 처리기입니다.

void CDlgMainMonitor::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}

void CDlgMainMonitor::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnCancel();
}

BOOL CDlgMainMonitor::OnInitDialog()
{
	CDialog::OnInitDialog();

	CWnd *pParent = GetParent();
	if (pParent)
	{
		CRect Rect;
		pParent->GetWindowRect(Rect);
		CRect curR;
		GetWindowRect(curR);

		curR.OffsetRect(Rect.right, Rect.top);
		MoveWindow(curR);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgMainMonitor::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
