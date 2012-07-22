#pragma once

#include "base/UITreeCtrl.h"
#include "afxcmn.h"


// CDlgUISelector 대화 상자입니다.

class CTabConsolWindow;
class CDlgUISelector : public CDialog
{
	DECLARE_DYNAMIC(CDlgUISelector)

public:
	CDlgUISelector(CTabConsolWindow *TabConsolWindow, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgUISelector();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_SELECTUI };
	CTabConsolWindow *m_pTabConsolWindow;

public:
//	void SetUITree(ui::CUINode *pRoot);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CUITreeCtrl m_UITree;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedUpdate();
};
