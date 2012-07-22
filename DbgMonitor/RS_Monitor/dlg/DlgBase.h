#pragma once


// CDlgBase 대화 상자입니다.

class CDlgBase : public CDialog
{
public:
	CDlgBase(UINT id, CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgBase();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
