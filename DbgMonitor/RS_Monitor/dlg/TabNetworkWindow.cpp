// D:\RS_Project2\src\Common\RS_Monitor\dlg\TabNetworkWindow.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "../RS_Monitor.h"
#include "TabNetworkWindow.h"
#include "MainDialog.h"
//#include "Common/PNetClient/NetListener.h"



CTabNetworkWindow::CTabNetworkWindow(CWnd* pParent /*=NULL*/)
	: CDialog(CTabNetworkWindow::IDD, pParent)
,	m_NetworkTree(CTreeCtrlBase::TREE_ITEM)
{

}

CTabNetworkWindow::~CTabNetworkWindow()
{
}

void CTabNetworkWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_NETWORK, m_NetworkTree);
}


BEGIN_MESSAGE_MAP(CTabNetworkWindow, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CTabNetworkWindow::OnBnClickedButtonUpdate)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_NETWORK, &CTabNetworkWindow::OnTvnSelchangedTreeNetwork)
	ON_BN_CLICKED(IDC_BUTTON_GOTO_LOGINSCENE, &CTabNetworkWindow::OnBnClickedButtonGotoLoginscene)
END_MESSAGE_MAP()


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
// void CTabNetworkWindow::SetNetwork(CNetManager *pNetMng)
// {
// 	if (!pNetMng)
// 		return;
// 
// 	m_NetworkTree.DeleteAllItems();
// 
//  	HTREEITEM hRoot = m_NetworkTree.InsertTree(NULL, _T("Root"), NULL);
// 
// 	HTREEITEM hSubItem;
// 
// 	CLoginClient *pLoginClient = pNetMng->GetLoginClient();
// 	hSubItem = m_NetworkTree.InsertTree(hRoot, _T("LoginClient"), NULL);
// 	AddNetListenerTree(hSubItem, pLoginClient);
// 
// 	CLobbyClient *pLobbyClient = pNetMng->GetLobbyClient();
// 	hSubItem = m_NetworkTree.InsertTree(hRoot, _T("LobbyClient"), NULL);
// 	AddNetListenerTree(hSubItem, pLobbyClient);
// 
// 	CGameClient *pGameClient = pNetMng->GetGameClient();
// 	hSubItem = m_NetworkTree.InsertTree(hRoot, _T("GameClient"), NULL);
// 	AddNetListenerTree(hSubItem, pGameClient);
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief NetClient의 리스너 리스트를 출력한다.
// */
// //------------------------------------------------------------------------------
// HTREEITEM CTabNetworkWindow::AddNetListenerTree(HTREEITEM hItem, CNetBase *pNetBase)
// {
// 	if (!pNetBase)
// 		return NULL;
// 
// 	std::list<CNetListener*> listeners = pNetBase->GetListeners();
// 	std::list<CNetListener*>::iterator it = listeners.begin();
// 
// 	HTREEITEM hSubItem = hItem;
// 	while (listeners.end() != it)
// 	{
// 		CNetListener *net = *it++;
// 		hSubItem = m_NetworkTree.InsertTree(hItem, net->m_DerivedClassName, NULL);
// 	}
// 
// 	m_NetworkTree.SelectItem(hSubItem);
// 
// 	return hSubItem;
// }


// CTabNetworkWindow 메시지 처리기입니다.
void CTabNetworkWindow::OnBnClickedButtonUpdate()
{
	//CMainDialog::SendDbgMessage(dbg::REFRESH_NETLISTENER, 0, 0);
	
}

void CTabNetworkWindow::OnTvnSelchangedTreeNetwork(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

void CTabNetworkWindow::OnBnClickedButtonGotoLoginscene()
{
	int result = ::AfxMessageBox(_T("LogIn 씬으로 이동하겠습니까?"), MB_OKCANCEL);
// 	if (result == IDOK)
// 		CMainDialog::SendDbgMessage(dbg::GOTO_LOGINSERVER, 0, 0);	
}
