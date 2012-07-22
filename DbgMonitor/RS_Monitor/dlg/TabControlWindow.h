#pragma once
#include "afxcmn.h"
#include "DlgBase.h"


// CTabControlWindow ��ȭ �����Դϴ�.

class CTabControlWindow : public CDlgBase
{
public:
	CTabControlWindow(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTabControlWindow();

// ��ȭ ���� �������Դϴ�.
	enum 
	{ 
		IDD = IDD_DLG_CONTROL,
		MAX_SLIDE = 8,	
	};

protected:
	typedef struct _sSlidInfo
	{
		int min;	// *100		���������� *100�� �ѻ����̴�. (int�� float�� ǥ���ϱ�����)
		int max;	// *100
	} sSlideInfo;

	sSlideInfo m_Slide[ MAX_SLIDE];


public:
	void		SetValue(int idx, float v);
	float 		GetValue(int idx );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	CSliderCtrl	m_SlideValue[ MAX_SLIDE];
	float		m_ValueText[ MAX_SLIDE];
	int			m_ValueMin[ MAX_SLIDE];
	int			m_ValueMax[ MAX_SLIDE];

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEnChangeEditValue1Min();
	afx_msg void OnEnChangeEditValue2Min();
	afx_msg void OnEnChangeEditValue3Min();
	afx_msg void OnEnChangeEditValue4Min();
	afx_msg void OnEnChangeEditValue5Min();
	afx_msg void OnEnChangeEditValue6Min();
	afx_msg void OnEnChangeEditValue7Min();
	afx_msg void OnEnChangeEditValue8Min();

	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar );

	afx_msg void OnEnChangeEditValue1();
	afx_msg void OnEnChangeEditValue2();
	afx_msg void OnEnChangeEditValue3();
	afx_msg void OnEnChangeEditValue4();
	afx_msg void OnEnChangeEditValue5();
	afx_msg void OnEnChangeEditValue6();
	afx_msg void OnEnChangeEditValue7();
	afx_msg void OnEnChangeEditValue8();

};
