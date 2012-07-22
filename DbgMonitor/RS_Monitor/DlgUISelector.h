#pragma once

#include "base/UITreeCtrl.h"
#include "afxcmn.h"


// CDlgUISelector ��ȭ �����Դϴ�.

class CTabConsolWindow;
class CDlgUISelector : public CDialog
{
	DECLARE_DYNAMIC(CDlgUISelector)

public:
	CDlgUISelector(CTabConsolWindow *TabConsolWindow, CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgUISelector();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_SELECTUI };
	CTabConsolWindow *m_pTabConsolWindow;

public:
//	void SetUITree(ui::CUINode *pRoot);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CUITreeCtrl m_UITree;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedUpdate();
};
