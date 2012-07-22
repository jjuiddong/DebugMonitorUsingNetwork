#pragma once


// CTabConsolWindow 대화 상자입니다.

class CTabConsolWindow : public CDialog
{
public:
	CTabConsolWindow(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabConsolWindow();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_CONSOL};
	enum eMsgType { General, Network, UI };

// 	CDlgUISelector *m_pUISelector;
// 	std::list<int>	m_filterList;
// 	BOOL			m_isUpdateFilter;

//	void SetUITree(ui::CUINode *pRoot);
	void AddMessage(eMsgType type, int movieID, const TCHAR *str);

//	void UpdateFilter(const std::list<int> &lst) { m_isUpdateFilter=TRUE; m_filterList = lst; }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	void		 ChangeComboxBox(eMsgType type);
	void		 UpdateConsolSize();
	BOOL		 IsFiltering(const int movieID);

	DECLARE_MESSAGE_MAP()

public:
	CListBox m_MsgList;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CListBox m_MsgList2;
	CListBox m_MsgList3;
	afx_msg void OnCbnSelchangeComboMsgtype();
	CComboBox m_MsgTypeComboBox;
	afx_msg void OnBnClickedButtonClear();
	BOOL m_NoUpdate;
	BOOL m_NoScroll;
	afx_msg void OnBnClickedCheckNoupdate();
	afx_msg void OnBnClickedCheckNoscroll();
	afx_msg void OnBnClickedButtonFilter();
};
