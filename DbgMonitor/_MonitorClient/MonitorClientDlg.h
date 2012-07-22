
// MonitorClientDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "base/TabMainCtrl.h"


// CMonitorClientDlg ��ȭ ����
class CMonitorClientDlg : public CDialog
{
// �����Դϴ�.
public:
	CMonitorClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MONITORCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

protected:
	BOOL m_IsRunning;

public:
	BOOL IsRunning() { return m_IsRunning; }


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	virtual BOOL DestroyWindow();
	CTabMainCtrl m_TabMain;
};
