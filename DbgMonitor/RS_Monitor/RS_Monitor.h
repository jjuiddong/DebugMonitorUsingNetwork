// RS_Monitor.h : RS_Monitor DLL�� �⺻ ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.

class CMainDialog;
class CRS_MonitorApp : public CWinApp
{
public:
	CRS_MonitorApp();
	virtual ~CRS_MonitorApp();

	CMainDialog *m_pDlg;

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};

extern CRS_MonitorApp theApp;
