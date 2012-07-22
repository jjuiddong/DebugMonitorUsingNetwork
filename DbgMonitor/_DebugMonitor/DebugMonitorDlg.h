
// DebugMonitorDlg.h : ��� ����
//

#pragma once


// CDebugMonitorDlg ��ȭ ����
class CDebugMonitorDlg : public CDialog
{
// �����Դϴ�.
public:
	CDebugMonitorDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DEBUGMONITOR_DIALOG };

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
public:
	afx_msg void OnBnClickedOk();
	int m_Message;
	afx_msg void OnBnClickedButtonSend();
	virtual BOOL DestroyWindow();
protected:
	virtual void OnOK();
	virtual void OnCancel();
};
