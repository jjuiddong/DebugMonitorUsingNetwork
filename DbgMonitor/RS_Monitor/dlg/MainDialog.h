#pragma once
#include "afxcmn.h"


// CDlgMonitor 대화 상자입니다.
#include "../TabMain.h"


class CDbgMessageListener;
class CTabConsolWindow;
class CTabControlWindow;
class CTabUIViewer;
class CTabNetworkWindow;
class CMainDialog : public CDialog
{
public:
	CMainDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMainDialog();
	enum { IDD = IDD_DLG_MONITOR };

protected:
	CTabMain			m_TabMain;
	CTabConsolWindow	*m_pTabConsolWindow;
	CTabControlWindow	*m_pTabControlWindow;
	CTabUIViewer		*m_pTabUIViewer;
	CTabNetworkWindow	*m_pTabNetworkWindow;

	static CDbgMessageListener	*s_pListener;		// 전역으로 접근 가능하게하기 위해 선언됨
	BOOL				m_IsRunning;

public:
	BOOL				IsRunning() { return m_IsRunning; }
	CTabMain*			GetTabMain();
	CTabConsolWindow*	GetConsolWindow() { return m_pTabConsolWindow; }
	CTabControlWindow*	GetControllWindow() { return m_pTabControlWindow; }
	CTabUIViewer*		GetUIViewr() { return m_pTabUIViewer; }
	CTabNetworkWindow*	GetNetworkWindow() { return m_pTabNetworkWindow; }

	static void			SetListener(CDbgMessageListener *p) {s_pListener=p;}
	static void			SendDbgMessage(int id, LPARAM lParam, WPARAM wParam);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);

protected:
	virtual void OnOK();
	virtual void OnCancel();
public:
	virtual BOOL DestroyWindow();
};
