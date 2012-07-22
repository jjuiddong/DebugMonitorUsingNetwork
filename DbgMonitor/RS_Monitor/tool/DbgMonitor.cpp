
#include "stdafx.h"
#include "DbgMonitor.h"
#include "../RS_Monitor.h"
#include "DbgMessageListener.h"

#include "../Dlg/MainDialog.h"
#include "../Dlg/TabConsolWindow.h"
#include "../Dlg/TabControlWindow.h"
#include "../Dlg/TabUIViewer.h"
#include "../Dlg/TabNetworkWindow.h"



// UINT ThreadFunc(LPVOID pParam);
// 
// 
// CDbgMonitor::CDbgMonitor() :
// 	m_pMainDialog(NULL)
// ,	m_pMessageListener(NULL)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 
// }
// 
// CDbgMonitor::~CDbgMonitor()
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 
// 	delete m_pMainDialog;
// 	if (m_pMessageListener)
// 		delete m_pMessageListener;
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief �޼��� ������ ���
// */
// //------------------------------------------------------------------------------
// void CDbgMonitor::SetMessageListener(CDbgMessageListener *p)
// {
// 	m_pMessageListener = p;
// 	if (m_pMainDialog)
// 		m_pMainDialog->SetListener(p);
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief ���� â ����
// */
// //------------------------------------------------------------------------------
// void CDbgMonitor::Modalese(HWND hWnd)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 
// 	if (!m_pMainDialog)
// 	{
// 		CWnd *pParent = CWnd::FromHandle(hWnd);
// 		m_pMainDialog = new CMainDialog(pParent);
// 		m_pMainDialog->Create(CMainDialog::IDD, pParent);
// 	}
// 
// 	m_pMainDialog->ShowWindow(SW_SHOW);
// //	m_pDlgMainMonitor->DoModal();
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief ������ �޼��� ó��
// */
// //------------------------------------------------------------------------------
// BOOL CDbgMonitor::MessageProc(LPMSG lpMsg)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 	TRY
// 	{
// 		return AfxGetThread()->PreTranslateMessage(lpMsg);
// 	}
// 	END_TRY
// 
// 	return FALSE;
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief �޼��� ���
// */
// //------------------------------------------------------------------------------
// void CDbgMonitor::PrintMsg(const TCHAR* str)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 	if (!m_pMainDialog)
// 		return;
// 	CTabConsolWindow *pWnd = m_pMainDialog->GetConsolWindow();
//  	if (pWnd)
// 		pWnd->AddMessage(CTabConsolWindow::General, NULL, str);
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief ��Ʈ��ũ �޼��� ���
// */
// //------------------------------------------------------------------------------
// void CDbgMonitor::PrintNetMsg(const TCHAR* str)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 	if (!m_pMainDialog)
// 		return;
// 	CTabConsolWindow *pWnd = m_pMainDialog->GetConsolWindow();
// 	if (pWnd)
// 		pWnd->AddMessage(CTabConsolWindow::Network, NULL, str);
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief Scaleform External �޼��� ���
// @param pNode: �޼����� ���� UINode ������
// */
// //------------------------------------------------------------------------------
// void CDbgMonitor::PrintScaleformMsg(int movieID, const TCHAR* str)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 	if (!m_pMainDialog)
// 		return;
// 	CTabConsolWindow *pWnd = m_pMainDialog->GetConsolWindow();
// 	if (pWnd)
// 		pWnd->AddMessage(CTabConsolWindow::UI, movieID, str);
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief 
// */
// //------------------------------------------------------------------------------
// float CDbgMonitor::GetValue(int idx)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 	if (!m_pMainDialog)
// 		return 0;
// 	CTabControlWindow *pWnd = m_pMainDialog->GetControllWindow();
// 	if (pWnd)
// 		return pWnd->GetValue(idx);
// 	return 0;
// }
// void CDbgMonitor::SetValue(int idx, float v)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 	if (!m_pMainDialog)
// 		return;
// 	CTabControlWindow *pWnd = m_pMainDialog->GetControllWindow();
// 	if (pWnd)
// 		return pWnd->SetValue(idx, v);
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief UI Ʈ�� ���
// */
// //------------------------------------------------------------------------------
// void CDbgMonitor::SetUITree(ui::CUINode *pNode)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 	if (!m_pMainDialog)
// 		return;
// 	CTabUIViewer *pWnd = m_pMainDialog->GetUIViewr();
// 	if (pWnd)
// 		pWnd->SetUITree(pNode);
// 	CTabConsolWindow *pWnd2 = m_pMainDialog->GetConsolWindow();
// 	if (pWnd2)
// 		pWnd2->SetUITree(pNode);
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief 
// */
// //------------------------------------------------------------------------------
// void CDbgMonitor::SetMouseOverUI(int movieID)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 	if (!m_pMainDialog)
// 		return;
// 	CTabUIViewer *pWnd = m_pMainDialog->GetUIViewr();
// 	if (pWnd)
// 		pWnd->SetMouseOverUI(movieID);
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief ��Ʈ��ũ ���� ���
// */
// //------------------------------------------------------------------------------
// void CDbgMonitor::SetNetwork(CNetManager *pNet)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 	if (!m_pMainDialog)
// 		return;
//  	CTabNetworkWindow *pWnd = m_pMainDialog->GetNetworkWindow();
//  	if (pWnd)
//  		return pWnd->SetNetwork(pNet);
// }
// 
// 
// //------------------------------------------------------------------------------
// /**
// @brief ����� â ĸ�� �̸� ����
// */
// //------------------------------------------------------------------------------
// void CDbgMonitor::SetTitleName(const TCHAR *titleName)
// {
// 	AFX_MANAGE_STATE(AfxGetStaticModuleState());
// 	if (!m_pMainDialog)
// 		return;
// 	m_pMainDialog->SetWindowText(titleName);
// }
