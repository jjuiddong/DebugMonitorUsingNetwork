#pragma once

#include "DlgBase.h"
#include "afxcmn.h"
#include "../base/UITreeCtrl.h"


class TiXmlDocument;
class CTabUIViewer : public CDlgBase
{
public:
	CTabUIViewer(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabUIViewer();
	enum { IDD = IDD_DLG_UIVIEW };

protected:
	int	m_CurrentMouseOverUI;	// movieID

public:
//	void SetUITree(ui::CUINode *pRoot);
	void SetMouseOverUI(int movieID);
	void SetUITree(TiXmlDocument *pDoc);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CUITreeCtrl m_UITree;
	afx_msg void OnBnClickedButtonUpdate();
	afx_msg void OnBnClickedButtonReload();
	CString m_MouseOverUI;
};
