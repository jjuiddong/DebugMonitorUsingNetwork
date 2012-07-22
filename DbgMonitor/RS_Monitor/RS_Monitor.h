// RS_Monitor.h : RS_Monitor DLL의 기본 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.

class CMainDialog;
class CRS_MonitorApp : public CWinApp
{
public:
	CRS_MonitorApp();
	virtual ~CRS_MonitorApp();

	CMainDialog *m_pDlg;

// 재정의입니다.
public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};

extern CRS_MonitorApp theApp;
