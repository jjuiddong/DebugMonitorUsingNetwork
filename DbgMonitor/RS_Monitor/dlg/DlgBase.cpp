// dlg/DlgBase.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "../RS_Monitor.h"
#include "DlgBase.h"


// CDlgBase 대화 상자입니다.
CDlgBase::CDlgBase(UINT id, CWnd* pParent /*=NULL*/)
	: CDialog(id, pParent)
{

}

CDlgBase::~CDlgBase()
{
}

void CDlgBase::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgBase, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgBase 메시지 처리기입니다.

//------------------------------------------------------------------------------
/**
@brief 윈도우 크기 조절
*/
//------------------------------------------------------------------------------
void CDlgBase::OnSize(UINT nType, int cx, int cy)
{
	if (!m_hWnd)
		return;

	CDialog::OnSize(nType, cx, cy);

	CRect pr;
	GetParent()->GetClientRect(pr);

	CRect mr = pr;
	mr.top += 30;
	mr.left += 10;
	mr.right -= 10;
	mr.bottom -= 10;
	MoveWindow(mr);
}
