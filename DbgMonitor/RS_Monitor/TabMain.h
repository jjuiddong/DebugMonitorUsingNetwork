#pragma once

// CTabMain 대화 상자입니다.
#include "Base/TabMainCtrl.h"

class CTabConsolWindow;
class CTabMain : public CTabMainCtrl
{
public:
	CTabMain(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabMain();
	enum { IDD = IDD_DLG_MAIN_MONITOR };

protected:

public:
	void Init();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
