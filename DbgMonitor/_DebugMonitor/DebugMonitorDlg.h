
// DebugMonitorDlg.h : 헤더 파일
//

#pragma once


// CDebugMonitorDlg 대화 상자
class CDebugMonitorDlg : public CDialog
{
// 생성입니다.
public:
	CDebugMonitorDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DEBUGMONITOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

protected:
	BOOL m_IsRunning;

public:
	BOOL IsRunning() { return m_IsRunning; }


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
