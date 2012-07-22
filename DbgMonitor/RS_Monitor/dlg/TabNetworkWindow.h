#pragma once
#include "afxcmn.h"
#include "../base/TreeCtrlBase.h"


class CNetManager;
class CTabNetworkWindow : public CDialog
{
public:
	CTabNetworkWindow(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTabNetworkWindow();

	enum { IDD = IDD_DLG_NETWORK };

public:
//	void	SetNetwork(CNetManager *pNetMng);

protected:
//	HTREEITEM AddNetListenerTree(HTREEITEM hItem, CNetBase *pNetBase);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrlBase m_NetworkTree;
	afx_msg void OnBnClickedButtonUpdate();
	afx_msg void OnTvnSelchangedTreeNetwork(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonGotoLoginscene();
};
