#pragma once


// CDlgBase ��ȭ �����Դϴ�.

class CDlgBase : public CDialog
{
public:
	CDlgBase(UINT id, CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgBase();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
