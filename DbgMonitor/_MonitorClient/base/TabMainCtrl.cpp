// Lib/TabMainCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TabMainCtrl.h"


CTabMainCtrl::CTabMainCtrl():
m_pCurWindow(NULL)
{

}

CTabMainCtrl::~CTabMainCtrl()
{
}


BEGIN_MESSAGE_MAP(CTabMainCtrl, CTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CTabMainCtrl::OnTcnSelchange)
END_MESSAGE_MAP()



// CTabMainCtrl �޽��� ó�����Դϴ�.



//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CTabMainCtrl::InsertTab( int index, TCHAR *str, CWnd *pWnd )
{
	InsertItem(index, str, 0);

	sTabInfo info;
	info.id = index;
	info.name = str;
	info.pWindow = pWnd;
	m_tabList.push_back(info);

	if (pWnd)
	{
		m_pCurWindow = pWnd;

		CRect cr;
		GetClientRect(cr);

		CRect mr = cr;
		mr.top += 30;
		mr.left += 10;
		mr.right -= 10;
		mr.bottom -= 10;
		pWnd->MoveWindow(mr);
	}
}


//------------------------------------------------------------------------------
/**
@brief �� ���� ã��
*/
//------------------------------------------------------------------------------
bool CTabMainCtrl::FindTab( int index, sTabInfo &out)
{
	TabItor it = std::find(m_tabList.begin(), m_tabList.end(), sTabInfo(index));
	if (m_tabList.end() == it)
		return false;
	out = *it;
	return true;
}


//------------------------------------------------------------------------------
/**
@brief �� ���
*/
//------------------------------------------------------------------------------
void CTabMainCtrl::ShowTab( int index )
{
	sTabInfo info;
	if (FindTab(index, info))
	{
		HideAllTab();

		if (info.pWindow)
			info.pWindow->ShowWindow(SW_SHOW);
		m_pCurWindow = info.pWindow;
	}
}


//------------------------------------------------------------------------------
/**
@brief ��� �����츦 �Ⱥ��̰� �Ѵ�.
*/
//------------------------------------------------------------------------------
void CTabMainCtrl::HideAllTab()
{
	TabItor it = m_tabList.begin();
	while (m_tabList.end() != it)
	{
		it++->pWindow->ShowWindow(SW_HIDE);
	}
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CTabMainCtrl::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	const int id = GetCurFocus();
	ShowTab(id);
	*pResult = 0;
}
