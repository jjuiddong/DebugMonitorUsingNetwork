#pragma once

// CTabMain ��ȭ �����Դϴ�.
#include "Base/TabMainCtrl.h"

class CTabConsolWindow;
class CTabMain : public CTabMainCtrl
{
public:
	CTabMain(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTabMain();
	enum { IDD = IDD_DLG_MAIN_MONITOR };

protected:

public:
	void Init();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
