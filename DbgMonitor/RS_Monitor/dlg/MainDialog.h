#pragma once
#include "afxcmn.h"


// CDlgMonitor ��ȭ �����Դϴ�.
#include "../TabMain.h"


class CDbgMessageListener;
class CTabConsolWindow;
class CTabControlWindow;
class CTabUIViewer;
class CTabNetworkWindow;
class CMainDialog : public CDialog
{
public:
	CMainDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMainDialog();
	enum { IDD = IDD_DLG_MONITOR };

protected:
	CTabMain			m_TabMain;
	CTabConsolWindow	*m_pTabConsolWindow;
	CTabControlWindow	*m_pTabControlWindow;
	CTabUIViewer		*m_pTabUIViewer;
	CTabNetworkWindow	*m_pTabNetworkWindow;

	static CDbgMessageListener	*s_pListener;		// �������� ���� �����ϰ��ϱ� ���� �����
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
