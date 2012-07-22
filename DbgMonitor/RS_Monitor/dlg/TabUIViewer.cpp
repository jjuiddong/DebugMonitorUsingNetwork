// dlg/DlgUIViwer.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "../RS_Monitor.h"
#include "TabUIViewer.h"
#include "MainDialog.h"


// CDlgUIViwer 대화 상자입니다.

CTabUIViewer::CTabUIViewer(CWnd* pParent /*=NULL*/)
	: CDlgBase(CTabUIViewer::IDD, pParent)
,	m_UITree(CTreeCtrlBase::TREE_ITEM, TRUE)
, m_MouseOverUI(_T("None"))
,	m_CurrentMouseOverUI(-1)
{

}

CTabUIViewer::~CTabUIViewer()
{
}

void CTabUIViewer::DoDataExchange(CDataExchange* pDX)
{
	CDlgBase::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_UI, m_UITree);
	DDX_Text(pDX, IDC_STATIC_MOUSEOVERUI, m_MouseOverUI);
}


BEGIN_MESSAGE_MAP(CTabUIViewer, CDlgBase)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CTabUIViewer::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_RELOAD, &CTabUIViewer::OnBnClickedButtonReload)
END_MESSAGE_MAP()


// CDlgUIViwer 메시지 처리기입니다.

//------------------------------------------------------------------------------
/**
@brief UI 출력
*/
//------------------------------------------------------------------------------
// void CTabUIViewer::SetUITree(ui::CUINode *pRoot)
// {
// 	m_UITree.SetUITree(pRoot);
// }


void CTabUIViewer::OnBnClickedButtonUpdate()
{
	//CMainDialog::SendDbgMessage(dbg::REFRESH_UITREE, 0, 0);

}


//------------------------------------------------------------------------------
/**
@brief 선택된 UIWindow를 재로딩한다.
*/
//------------------------------------------------------------------------------
void CTabUIViewer::OnBnClickedButtonReload()
{
	HTREEITEM hItem = m_UITree.GetSelectedItem();
	if (!hItem)
		return;

	DWORD_PTR ptr = m_UITree.GetItemData(hItem);
	//CMainDialog::SendDbgMessage(dbg::RELOAD_UIWINDOW, ptr, 0);	
}


//------------------------------------------------------------------------------
/**
@brief 현재 마우스 아래에 있는 UI를 설정한다.
*/
//------------------------------------------------------------------------------
void CTabUIViewer::SetMouseOverUI(int movieID)
{
	if (m_CurrentMouseOverUI == movieID)
		return;

// 	m_CurrentMouseOverUI = movieID;
// 	const HTREEITEM hSelectItem = m_UITree.SelectUI( movieID );
// 	if (hSelectItem)
// 	{
// 		LPARAM data = m_UITree.GetItemData(hSelectItem);
// 		ui::CUINode *pNode = reinterpret_cast<ui::CUINode*>(data);
// 		if (pNode)
// 		{
// 			m_MouseOverUI = pNode->GetName().c_str();
// 		}
// 	}
// 	else
// 	{
// 		m_MouseOverUI = _T("None");
// 	}
// 
	UpdateData(FALSE);
}
