// Dlg/TabConsolWindow.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "../MonitorClient.h"
#include "TabConsolWindow.h"


// CTabConsolWindow ��ȭ �����Դϴ�.

CTabConsolWindow::CTabConsolWindow(CWnd* pParent /*=NULL*/)
	: CDialog(CTabConsolWindow::IDD, pParent)
	, m_NoUpdate(FALSE)
	, m_NoScroll(FALSE)
// 	, m_pUISelector(NULL)
// 	, m_isUpdateFilter(FALSE)
{
// 	m_pUISelector = new CDlgUISelector(this);
// 	m_pUISelector->Create(CDlgUISelector::IDD, this);

}

CTabConsolWindow::~CTabConsolWindow()
{
}

void CTabConsolWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MSG, m_MsgList);
	DDX_Control(pDX, IDC_LIST_MSG2, m_MsgList2);
	DDX_Control(pDX, IDC_LIST_MSG3, m_MsgList3);
	DDX_Control(pDX, IDC_COMBO_MSGTYPE, m_MsgTypeComboBox);
	DDX_Check(pDX, IDC_CHECK_NOUPDATE, m_NoUpdate);
	DDX_Check(pDX, IDC_CHECK_NOSCROLL, m_NoScroll);
}

BOOL CTabConsolWindow::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_MsgTypeComboBox.InsertString( General, _T("General") );
	m_MsgTypeComboBox.InsertString( Network, _T("Network") );
	m_MsgTypeComboBox.InsertString( UI, _T("Scaleform") );
	m_MsgTypeComboBox.SetCurSel(General);
	ChangeComboxBox(General);

	UpdateConsolSize();

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

BEGIN_MESSAGE_MAP(CTabConsolWindow, CDialog)
	ON_WM_SIZE()
	ON_CBN_SELCHANGE(IDC_COMBO_MSGTYPE, &CTabConsolWindow::OnCbnSelchangeComboMsgtype)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CTabConsolWindow::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_CHECK_NOUPDATE, &CTabConsolWindow::OnBnClickedCheckNoupdate)
	ON_BN_CLICKED(IDC_CHECK_NOSCROLL, &CTabConsolWindow::OnBnClickedCheckNoscroll)
	ON_BN_CLICKED(IDC_BUTTON_FILTER, &CTabConsolWindow::OnBnClickedButtonFilter)
END_MESSAGE_MAP()


//------------------------------------------------------------------------------
/**
@brief UI ���
*/
//------------------------------------------------------------------------------
// void CTabConsolWindow::SetUITree(ui::CUINode *pRoot)
// {
// 	if (m_pUISelector)
// 		m_pUISelector->SetUITree(pRoot);
// }


//------------------------------------------------------------------------------
/**
@brief �޼��� ���
*/
//------------------------------------------------------------------------------
void CTabConsolWindow::AddMessage(eMsgType type, int movieID, const TCHAR *str)
{
	if ((UI==type) && !IsFiltering(movieID))
		return;		

	//	UpdateData();
	if (m_NoUpdate)
		return;

	switch(type)
	{
	case General:
		m_MsgList.AddString( str );
		if (!m_NoScroll)
			m_MsgList.SetCurSel(m_MsgList.GetCount()-1);
		break;

	case Network:
		m_MsgList2.AddString( str );
		if (!m_NoScroll)
			m_MsgList2.SetCurSel(m_MsgList2.GetCount()-1);
		break;

	case UI:
		m_MsgList3.AddString( str );
		if (!m_NoScroll)
			m_MsgList3.SetCurSel(m_MsgList3.GetCount()-1);
		break;
	}
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CTabConsolWindow::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	UpdateConsolSize();
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CTabConsolWindow::OnCbnSelchangeComboMsgtype()
{
	const int sel = m_MsgTypeComboBox.GetCurSel();
	ChangeComboxBox((eMsgType)sel);
}


//------------------------------------------------------------------------------
/**
@brief �޺��ڽ� ���ú���
*/
//------------------------------------------------------------------------------
void CTabConsolWindow::ChangeComboxBox(eMsgType type)
{
	m_MsgList.ShowWindow(SW_HIDE);
	m_MsgList2.ShowWindow(SW_HIDE);
	m_MsgList3.ShowWindow(SW_HIDE);

	switch (type)
	{
	case General: m_MsgList.ShowWindow(SW_SHOW); break;
	case Network: m_MsgList2.ShowWindow(SW_SHOW); break;
	case UI: m_MsgList3.ShowWindow(SW_SHOW); break;
	}
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CTabConsolWindow::OnBnClickedButtonClear()
{
	eMsgType type = (eMsgType)m_MsgTypeComboBox.GetCurSel();
	switch (type)
	{
	case General: 
		while (m_MsgList.GetCount() > 0)
			m_MsgList.DeleteString(m_MsgList.GetCount()-1); 
		break;
	case Network: 
		while (m_MsgList2.GetCount() > 0)
			m_MsgList2.DeleteString(m_MsgList2.GetCount()-1); 
		break;
	case UI:
		while (m_MsgList3.GetCount() > 0)
			m_MsgList3.DeleteString(m_MsgList3.GetCount()-1); 
		break;
	}	
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CTabConsolWindow::UpdateConsolSize()
{
	if (!m_MsgList.m_hWnd)
		return;

	CRect mr;
	GetClientRect(mr);

	mr.OffsetRect(-mr.left, -mr.top);
	mr.top += 35;
	m_MsgList.MoveWindow(mr);
	m_MsgList2.MoveWindow(mr);
	m_MsgList3.MoveWindow(mr);
}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CTabConsolWindow::OnBnClickedCheckNoupdate()
{

}


//------------------------------------------------------------------------------
/**
@brief 
*/
//------------------------------------------------------------------------------
void CTabConsolWindow::OnBnClickedCheckNoscroll()
{

}


//------------------------------------------------------------------------------
/**
@brief Filter ���
*/
//------------------------------------------------------------------------------
void CTabConsolWindow::OnBnClickedButtonFilter()
{
// 	if (m_pUISelector)
// 		m_pUISelector->ShowWindow(SW_SHOW);
}


//------------------------------------------------------------------------------
/**
@brief movieID ������ ���͸� ������ �Ǵ��Ѵ�.
*/
//------------------------------------------------------------------------------
BOOL CTabConsolWindow::IsFiltering(const int movieID)
{
// 	if (!m_isUpdateFilter && m_filterList.empty()) // ����ִٸ� ���͸��� ����.
// 		return TRUE; // �ѹ��� ���͸��� �������� �ʾ������� �ش�ȴ�.
// 
// 	std::list<int>::iterator it = std::find(m_filterList.begin(), m_filterList.end(), movieID);
// 	if (m_filterList.end() != it)
// 		return TRUE;

	return FALSE;
}
