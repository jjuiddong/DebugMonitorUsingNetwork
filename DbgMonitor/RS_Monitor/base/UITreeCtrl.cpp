// D:\RS_Project2\src\Common\RS_Monitor\base\UITreeCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "../RS_Monitor.h"
#include "UITreeCtrl.h"
#include "../tinyXml/tinyxml.h"

using namespace std;

// CUITreeCtrl
CUITreeCtrl::CUITreeCtrl(TYPE type, BOOL isDisplayDetail)
:	CTreeCtrlBase(type)
,	m_isDisplayDetail(isDisplayDetail)
{

}

CUITreeCtrl::~CUITreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CUITreeCtrl, CTreeCtrlBase)
	ON_NOTIFY_REFLECT(TVN_KEYDOWN, &CUITreeCtrl::OnTvnKeydown)
	ON_NOTIFY_REFLECT(NM_CLICK, &CUITreeCtrl::OnNMClick)
END_MESSAGE_MAP()



// CUITreeCtrl �޽��� ó�����Դϴ�.


void CUITreeCtrl::SetUITree(TiXmlDocument *pDoc)
{
	if (!pDoc)
		return;

	DeleteAllItems();
	HTREEITEM hRoot = InsertTree(NULL, _T("UITree"), NULL);
	TiXmlElement *pRoot = pDoc->RootElement();
	AddUITree(hRoot, pRoot);
}

HTREEITEM CUITreeCtrl::AddUITree(HTREEITEM hParentItem, TiXmlElement *pElement)
{
	if (!pElement)
		return NULL;

	string value = pElement->Value();
	const char *ctext = pElement->GetText();
	string text = (ctext)? ctext: " ";
	if (ctext)
	{
		value += " : ";
		value += text;
	}

	wstring wtext;
	wtext.assign(value.begin(), value.end());
	HTREEITEM hItem = InsertTree(hParentItem, wtext.c_str(), NULL);

	TiXmlAttribute *attr = pElement->FirstAttribute();
	while (attr)
	{
		string name = attr->Name();
		name += " : ";
		name += attr->Value();
		wstring wname;
		wname.assign(name.begin(), name.end());
		HTREEITEM hSubItem = InsertTree(hItem, wname.c_str(), NULL);

		attr = attr->Next();
		SelectItem(hSubItem);
	}

	SelectItem(hItem);

	TiXmlElement *pChild = pElement->FirstChildElement();
	AddUITree(hItem, pChild);
	AddUITree(hParentItem, pElement->NextSiblingElement());

/*
	if (m_isDisplayDetail)
	{
		//---------------------------------------------------------------------------------
		// UINode �������
		CString strFilename;
		strFilename.Format(_T("- fileName = %s"), pNode->GetResourceName().c_str());
		InsertTree(hItem, strFilename, (CDialog*)pNode);

		CString strVisible;
		strVisible.Format(_T("- IsVisible = %d"), pNode->IsVisible() );
		HTREEITEM hSubItem = InsertTree(hItem, strVisible, (CDialog*)pNode);

		CString strLook;
		strLook.Format(_T("- IsLook = %d"), pNode->IsLook() );
		InsertTree(hItem, strLook, (CDialog*)pNode);
		//---------------------------------------------------------------------------------

		SelectItem(hSubItem);
	}
	else
	{
		SelectItem(hItem);
	}

	ui::NodeList *pList = pNode->GetChildList();
	if (pList)
	{
		ui::NodeItor it = pList->begin();
		while (pList->end() != it)
			AddUITree(hItem, *it++);
	}
	return hItem;	
/**/
	return hItem;
}


//------------------------------------------------------------------------------
/**
@brief UI ���
*/
//------------------------------------------------------------------------------
// void CUITreeCtrl::SetUITree(ui::CUINode *pRoot)
// {
// 	if (!pRoot)
// 		return;
// 
// 	DeleteAllItems();
// 	HTREEITEM hRoot = InsertTree(NULL, _T("Root"), NULL);
// 	AddUITree(hRoot, pRoot);
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief �ڽ� UIƮ�� �߰�
// */
// //------------------------------------------------------------------------------
// HTREEITEM CUITreeCtrl::AddUITree(HTREEITEM hParentItem, ui::CUINode *pNode)
// {
// 	if (!pNode)
// 		return NULL;
// 
// 	HTREEITEM hItem = InsertTree(hParentItem, pNode->GetName().c_str(), (CDialog*)pNode);
// 
// 	if (m_isDisplayDetail)
// 	{
// 		//---------------------------------------------------------------------------------
// 		// UINode �������
// 		CString strFilename;
// 		strFilename.Format(_T("- fileName = %s"), pNode->GetResourceName().c_str());
// 		InsertTree(hItem, strFilename, (CDialog*)pNode);
// 
// 		CString strVisible;
// 		strVisible.Format(_T("- IsVisible = %d"), pNode->IsVisible() );
// 		HTREEITEM hSubItem = InsertTree(hItem, strVisible, (CDialog*)pNode);
// 
// 		CString strLook;
// 		strLook.Format(_T("- IsLook = %d"), pNode->IsLook() );
// 		InsertTree(hItem, strLook, (CDialog*)pNode);
// 		//---------------------------------------------------------------------------------
// 
// 		SelectItem(hSubItem);
// 	}
// 	else
// 	{
// 		SelectItem(hItem);
// 	}
// 
// 	ui::NodeList *pList = pNode->GetChildList();
// 	if (pList)
// 	{
// 		ui::NodeItor it = pList->begin();
// 		while (pList->end() != it)
// 			AddUITree(hItem, *it++);
// 	}
// 	return hItem;
// }

void CUITreeCtrl::OnTvnKeydown(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVKEYDOWN pTVKeyDown = reinterpret_cast<LPNMTVKEYDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


//------------------------------------------------------------------------------
/**
@brief üũ�ڽ� Ŭ��
*/
//------------------------------------------------------------------------------
void CUITreeCtrl::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	UINT uFlags = 0;
	CPoint pt(0, 0);
	GetCursorPos(&pt);
	ScreenToClient(&pt);
	HTREEITEM hItem = HitTest(pt, &uFlags);
	if(NULL != hItem && (TVHT_ONITEMSTATEICON  & uFlags))
	{
		const BOOL isCheck = GetCheck(hItem);
		HTREEITEM hChildItem = GetChildItem(hItem);
		SelectItem(hItem);
		CheckUITree( hChildItem, !isCheck );
	}

	*pResult = 0;
}


//------------------------------------------------------------------------------
/**
@brief Ʈ�������� üũ, �ڽ�Ʈ���� ���� ������� ó���Ѵ�.
*/
//------------------------------------------------------------------------------
void CUITreeCtrl::CheckUITree( HTREEITEM hItem, BOOL isCheck )
{
	if (!hItem)
		return;

	SetCheck(hItem, isCheck);
 	HTREEITEM hChildItem = GetChildItem(hItem);
 	CheckUITree( hChildItem, isCheck );
	
	HTREEITEM hSibItem = hItem;
	while (hSibItem = GetNextSiblingItem(hSibItem))
	{
		CheckUITree(hSibItem, isCheck);
	}	
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
std::list<int>	CUITreeCtrl::GetCheckIDList()
{
	std::list<int> checkList;

	HTREEITEM hRoot = GetRootItem();
	HTREEITEM hChildItem = GetChildItem(hRoot);
	GetCheckIDList(hChildItem, checkList);
	return checkList;
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CUITreeCtrl::GetCheckIDList(HTREEITEM hItem, std::list<int> &lst)
{
	if (!hItem)
		return;

// 	LPARAM data = GetItemData(hItem);
// 	ui::CUINode *pNode = reinterpret_cast<ui::CUINode*>(data);
// 	if (pNode)
// 	{
// 		if (GetCheck(hItem))
// 			lst.push_back(pNode->GetTag());
// 	}
// 
// 	HTREEITEM hChildItem = GetChildItem(hItem);
// 	GetCheckIDList( hChildItem, lst );
// 
// 	HTREEITEM hSibItem = hItem;
// 	while (hSibItem = GetNextSiblingItem(hSibItem))
// 	{
// 		GetCheckIDList(hSibItem, lst);
// 	}
}


//------------------------------------------------------------------------------
/**
@brief isCheck ������ ��� Ʈ�� üũ�ڽ��� �����Ѵ�.
*/
//------------------------------------------------------------------------------
void CUITreeCtrl::CheckAllTree( BOOL isCheck )
{
	HTREEITEM hRoot = GetRootItem();
	HTREEITEM hChildItem = GetChildItem(hRoot);
	SetCheck(hRoot, isCheck);
	CheckUITree(hChildItem, isCheck);
}


//------------------------------------------------------------------------------
/**
@brief movieID �� ���� UINode Ʈ���� CTreeCtrl�� ����Ѵ�.
*/
//------------------------------------------------------------------------------
HTREEITEM CUITreeCtrl::SelectUI( int movieID )
{
// 	TreeItemList itemList;
// 	HTREEITEM hChildItem = GetChildItem(GetRootItem());
// 	GetUITree(hChildItem, itemList);
// 
// 	HTREEITEM selectItem = NULL;
// 	TreeItemItor it = itemList.begin();
// 	while (itemList.end() != it)
// 	{
// 		HTREEITEM hItem = *it++;
// 		LPARAM data = GetItemData(hItem);
// 		ui::CUINode *pNode = reinterpret_cast<ui::CUINode*>(data);
// 		if (pNode)
// 		{
// 			if (pNode->GetTag() == movieID)
// 			{
// 				selectItem = hItem;
// 				SelectItem(hItem);
// 				break;
// 			}
// 		}
// 	}
//	return selectItem;
	return NULL;
}


//------------------------------------------------------------------------------
/**
@brief ��� UITree �� list�� �����ؼ� �����Ѵ�.
*/
//------------------------------------------------------------------------------
void CUITreeCtrl::GetUITree(HTREEITEM hItem, TreeItemList &lst)
{
	if (!hItem)
		return;

	lst.push_back(hItem);

	HTREEITEM hChildItem = GetChildItem(hItem);
	GetUITree( hChildItem, lst );

	HTREEITEM hSibItem = hItem;
	while (hSibItem = GetNextSiblingItem(hSibItem))
	{
		GetUITree(hSibItem, lst);
	}
}
