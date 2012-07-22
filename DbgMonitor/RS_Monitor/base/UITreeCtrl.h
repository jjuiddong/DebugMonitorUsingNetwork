#pragma once


// CUITreeCtrl
#include "TreeCtrlBase.h"
#include <list>

class CUITreeCtrl : public CTreeCtrlBase
{
public:
	CUITreeCtrl(TYPE type, BOOL isDisplayDetail);
	virtual ~CUITreeCtrl();

protected:
	typedef std::list<HTREEITEM> TreeItemList;
	typedef TreeItemList::iterator TreeItemItor;

	BOOL		m_isDisplayDetail;

public:
//	void	SetUITree(ui::CUINode *pRoot);
	std::list<int>	GetCheckIDList();
	void			CheckAllTree( BOOL isCheck );
	HTREEITEM		SelectUI( int movieID );

protected:
//	HTREEITEM		AddUITree(HTREEITEM hItem, ui::CUINode *pTree);
	void			CheckUITree( HTREEITEM hItem, BOOL isCheck );	
	void			GetCheckIDList(HTREEITEM hItem, std::list<int> &lst);
	void			GetUITree(HTREEITEM hItem, TreeItemList &lst);

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnKeydown(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
};
