
// MonitorClientDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "base/TabMainCtrl.h"


// CMonitorClientDlg 대화 상자
class CMonitorClientDlg : public CDialog
{
// 생성입니다.
public:
	CMonitorClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MONITORCLIENT_DIALOG };

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
	virtual void OnOK();
	virtual void OnCancel();
public:
	virtual BOOL DestroyWindow();
	CTabMainCtrl m_TabMain;
};
