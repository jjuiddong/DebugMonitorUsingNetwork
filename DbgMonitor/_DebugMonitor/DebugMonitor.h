
// DebugMonitor.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CDebugMonitorApp:
// �� Ŭ������ ������ ���ؼ��� DebugMonitor.cpp�� �����Ͻʽÿ�.
//

class CDebugMonitorDlg;
class CDebugMonitorApp : public CWinAppEx
{
public:
	CDebugMonitorApp();

	CDebugMonitorDlg *m_pDlg;

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CDebugMonitorApp theApp;