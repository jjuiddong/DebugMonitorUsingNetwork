
// MonitorClient.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMonitorClientApp:
// �� Ŭ������ ������ ���ؼ��� MonitorClient.cpp�� �����Ͻʽÿ�.
//

class CMonitorClientDlg;
class CMonitorClientApp : public CWinAppEx
{
public:
	CMonitorClientApp();

	CMonitorClientDlg *m_pDlg;

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMonitorClientApp theApp;