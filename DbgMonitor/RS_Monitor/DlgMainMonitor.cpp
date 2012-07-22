// DlgMainMonitor.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "RS_Monitor.h"
#include "DlgMainMonitor.h"


// CDlgMainMonitor ��ȭ �����Դϴ�.


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


// CDlgMainMonitor �޽��� ó�����Դϴ�.

void CDlgMainMonitor::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}

void CDlgMainMonitor::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgMainMonitor::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}
