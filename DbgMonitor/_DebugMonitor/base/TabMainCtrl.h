#pragma once

#include <list>
#include <string>
#include <algorithm>


// CTabMainCtrl
class CTabMainCtrl : public CTabCtrl
{
public:
	CTabMainCtrl();
	virtual ~CTabMainCtrl();

	enum { IDD = 0 };

protected:
	// ÅÇÁ¤º¸
	typedef struct _sTabInfo
	{
		int id;
		std::wstring name;
		CWnd *pWindow;
		_sTabInfo() {}
		_sTabInfo(int id_) : id(id_) {}
		bool operator==(const _sTabInfo &rhs)
		{ return rhs.id == id; }
	} sTabInfo;

	typedef std::list<sTabInfo> TabList;
	typedef TabList::iterator TabItor;

	TabList m_tabList;
	CWnd	*m_pCurWindow;

public:
	void InsertTab( int index, TCHAR *str, CWnd *pWnd );
	bool FindTab( int index, sTabInfo &out );
	void ShowTab( int index );

protected:
	void HideAllTab();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
};


