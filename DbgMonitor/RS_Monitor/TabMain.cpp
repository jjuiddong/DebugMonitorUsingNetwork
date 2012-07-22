// TabMain.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "RS_Monitor.h"
#include "TabMain.h"
#include "Dlg/TabConsolWindow.h"



// CTabMain 대화 상자입니다.
CTabMain::CTabMain(CWnd* pParent /*=NULL*/):
	CTabMainCtrl()
{

}

CTabMain::~CTabMain()
{

}

void CTabMain::DoDataExchange(CDataExchange* pDX)
{
	CTabMainCtrl::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabMain, CTabMainCtrl)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CTabMain::OnTcnSelchangeTabMain)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CTabMain 메시지 처리기입니다.


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CTabMain::Init()
{
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CTabMain::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{	

	
	*pResult = 0;
}


//------------------------------------------------------------------------------
/**
@brief 윈도우 사이즈 변경
*/
//------------------------------------------------------------------------------
void CTabMain::OnSize(UINT nType, int cx, int cy)
{
	if (!m_hWnd)
		return;

	CTabMainCtrl::OnSize(nType, cx, cy);

	CRect cr;
	GetClientRect(cr);
	cr.right = cr.left + cx;
	cr.bottom = cr.top + cy;
	MoveWindow(cr);

 	if (m_pCurWindow)
 		m_pCurWindow->SendMessage(WM_SIZE, nType, MAKELONG(cx, cy));
}
