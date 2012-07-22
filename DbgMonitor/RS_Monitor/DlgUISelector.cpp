// DlgUISelector.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "RS_Monitor.h"
#include "DlgUISelector.h"
#include "dlg/MainDialog.h"
#include "dlg/TabConsolWindow.h"


// CDlgUISelector 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgUISelector, CDialog)

CDlgUISelector::CDlgUISelector(CTabConsolWindow *TabConsolWindow, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgUISelector::IDD, pParent)
,	m_UITree(CTreeCtrlBase::TREE_ITEM, FALSE)
,	m_pTabConsolWindow(TabConsolWindow)
{

}

CDlgUISelector::~CDlgUISelector()
{
}

void CDlgUISelector::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_UI, m_UITree);
}


BEGIN_MESSAGE_MAP(CDlgUISelector, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgUISelector::OnBnClickedOk)
	ON_BN_CLICKED(ID_UPDATE, &CDlgUISelector::OnBnClickedUpdate)
END_MESSAGE_MAP()


// CDlgUISelector 메시지 처리기입니다.

//------------------------------------------------------------------------------
/**
@brief UI 출력
*/
//------------------------------------------------------------------------------
// void CDlgUISelector::SetUITree(ui::CUINode *pRoot)
// {
// 	m_UITree.SetUITree(pRoot);
// 	m_UITree.CheckAllTree(TRUE);
// }

void CDlgUISelector::OnBnClickedOk()
{
	if (m_pTabConsolWindow)
	{
		std::list<int> filterList = m_UITree.GetCheckIDList();
		m_pTabConsolWindow->UpdateFilter(filterList);
	}
	
	OnOK();
}

void CDlgUISelector::OnBnClickedUpdate()
{
//	CMainDialog::SendDbgMessage(dbg::REFRESH_UITREE, 0, 0);
}
