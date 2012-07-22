// TabControlWindow.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "../RS_Monitor.h"
#include "TabControlWindow.h"


// CTabControlWindow 대화 상자입니다.

CTabControlWindow::CTabControlWindow(CWnd* pParent /*=NULL*/)
	: CDlgBase(CTabControlWindow::IDD, pParent)
{
	for (int i=0; i < MAX_SLIDE; ++i)
	{
		m_Slide[ i].min = -10000;
		m_Slide[ i].max = 10000;
		m_ValueText[ i] = 0;
		m_ValueMin[ i] = -100;
		m_ValueMax[ i] = 100;
	}

}

CTabControlWindow::~CTabControlWindow()
{

}

void CTabControlWindow::DoDataExchange(CDataExchange* pDX)
{
	CDlgBase::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_CHAR_X, m_SlideValue[0]);
	DDX_Control(pDX, IDC_SLIDER_CHAR_Z, m_SlideValue[1]);
	DDX_Control(pDX, IDC_SLIDER_CAM_X, m_SlideValue[2]);
	DDX_Control(pDX, IDC_SLIDER_CAM_Y, m_SlideValue[3]);
	DDX_Control(pDX, IDC_SLIDER_5, m_SlideValue[4]);
	DDX_Control(pDX, IDC_SLIDER_6, m_SlideValue[5]);
	DDX_Control(pDX, IDC_SLIDER_7, m_SlideValue[6]);
	DDX_Control(pDX, IDC_SLIDER_8, m_SlideValue[7]);

	DDX_Text(pDX, IDC_EDIT_VALUE1_MIN, m_ValueMin[0]);
	DDX_Text(pDX, IDC_EDIT_VALUE2_MIN, m_ValueMin[1]);
	DDX_Text(pDX, IDC_EDIT_VALUE3_MIN, m_ValueMin[2]);
	DDX_Text(pDX, IDC_EDIT_VALUE4_MIN, m_ValueMin[3]);
	DDX_Text(pDX, IDC_EDIT_VALUE5_MIN, m_ValueMin[4]);
	DDX_Text(pDX, IDC_EDIT_VALUE6_MIN, m_ValueMin[5]);
	DDX_Text(pDX, IDC_EDIT_VALUE7_MIN, m_ValueMin[6]);
	DDX_Text(pDX, IDC_EDIT_VALUE8_MIN, m_ValueMin[7]);

	DDX_Text(pDX, IDC_EDIT_VALUE1_MAX, m_ValueMax[ 0]);
	DDX_Text(pDX, IDC_EDIT_VALUE2_MAX, m_ValueMax[ 1]);
	DDX_Text(pDX, IDC_EDIT_VALUE3_MAX, m_ValueMax[ 2]);
	DDX_Text(pDX, IDC_EDIT_VALUE4_MAX, m_ValueMax[ 3]);
	DDX_Text(pDX, IDC_EDIT_VALUE5_MAX, m_ValueMax[ 4]);
	DDX_Text(pDX, IDC_EDIT_VALUE6_MAX, m_ValueMax[ 5]);
	DDX_Text(pDX, IDC_EDIT_VALUE7_MAX, m_ValueMax[ 6]);
	DDX_Text(pDX, IDC_EDIT_VALUE8_MAX, m_ValueMax[ 7]);

	DDX_Text(pDX, IDC_EDIT_VALUE1, m_ValueText[ 0]);
	DDX_Text(pDX, IDC_EDIT_VALUE2, m_ValueText[ 1]);
	DDX_Text(pDX, IDC_EDIT_VALUE3, m_ValueText[ 2]);
	DDX_Text(pDX, IDC_EDIT_VALUE4, m_ValueText[ 3]);
	DDX_Text(pDX, IDC_EDIT_VALUE5, m_ValueText[ 4]);
	DDX_Text(pDX, IDC_EDIT_VALUE6, m_ValueText[ 5]);
	DDX_Text(pDX, IDC_EDIT_VALUE7, m_ValueText[ 6]);
	DDX_Text(pDX, IDC_EDIT_VALUE8, m_ValueText[ 7]);

}


BEGIN_MESSAGE_MAP(CTabControlWindow, CDlgBase)
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
	ON_EN_UPDATE(IDC_EDIT_VALUE1_MIN, &CTabControlWindow::OnEnChangeEditValue1Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE1_MAX, &CTabControlWindow::OnEnChangeEditValue1Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE2_MIN, &CTabControlWindow::OnEnChangeEditValue2Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE2_MAX, &CTabControlWindow::OnEnChangeEditValue2Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE3_MIN, &CTabControlWindow::OnEnChangeEditValue3Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE3_MAX, &CTabControlWindow::OnEnChangeEditValue3Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE4_MIN, &CTabControlWindow::OnEnChangeEditValue4Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE4_MAX, &CTabControlWindow::OnEnChangeEditValue4Min)

	ON_EN_UPDATE(IDC_EDIT_VALUE5_MIN, &CTabControlWindow::OnEnChangeEditValue5Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE5_MAX, &CTabControlWindow::OnEnChangeEditValue5Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE6_MIN, &CTabControlWindow::OnEnChangeEditValue6Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE6_MAX, &CTabControlWindow::OnEnChangeEditValue6Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE7_MIN, &CTabControlWindow::OnEnChangeEditValue7Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE7_MAX, &CTabControlWindow::OnEnChangeEditValue7Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE8_MIN, &CTabControlWindow::OnEnChangeEditValue8Min)
	ON_EN_UPDATE(IDC_EDIT_VALUE8_MAX, &CTabControlWindow::OnEnChangeEditValue8Min)

	ON_EN_CHANGE(IDC_EDIT_VALUE1, &CTabControlWindow::OnEnChangeEditValue1)
	ON_EN_CHANGE(IDC_EDIT_VALUE2, &CTabControlWindow::OnEnChangeEditValue2)
	ON_EN_CHANGE(IDC_EDIT_VALUE3, &CTabControlWindow::OnEnChangeEditValue3)
	ON_EN_CHANGE(IDC_EDIT_VALUE4, &CTabControlWindow::OnEnChangeEditValue4)
	ON_EN_CHANGE(IDC_EDIT_VALUE5, &CTabControlWindow::OnEnChangeEditValue5)
	ON_EN_CHANGE(IDC_EDIT_VALUE6, &CTabControlWindow::OnEnChangeEditValue6)
	ON_EN_CHANGE(IDC_EDIT_VALUE7, &CTabControlWindow::OnEnChangeEditValue7)
	ON_EN_CHANGE(IDC_EDIT_VALUE8, &CTabControlWindow::OnEnChangeEditValue8)

END_MESSAGE_MAP()

// CTabControlWindow 메시지 처리기입니다.

BOOL CTabControlWindow::OnInitDialog()
{
	CDlgBase::OnInitDialog();

	for (int i=0; i < MAX_SLIDE; ++i)
	{
		m_SlideValue[ i].SetRange(m_Slide[ i].min, m_Slide[ i].max);
		m_SlideValue[ i].SetPos( 50 );
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTabControlWindow::OnLButtonDown(UINT nFlags, CPoint point)
{


	CDlgBase::OnLButtonDown(nFlags, point);
}

void CTabControlWindow::OnEnChangeEditValue1Min()
{
	UpdateData(TRUE);
	m_SlideValue[ 0].SetRange(m_ValueMin[0]*100, m_ValueMax[0]*100);
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue2Min()
{
	UpdateData(TRUE);
	m_SlideValue[ 1].SetRange(m_ValueMin[1]*100, m_ValueMax[1]*100);
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue3Min()
{
	UpdateData(TRUE);
	m_SlideValue[ 2].SetRange(m_ValueMin[2]*100, m_ValueMax[2]*100);
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue4Min()
{
	UpdateData(TRUE);
	m_SlideValue[ 3].SetRange(m_ValueMin[3]*100, m_ValueMax[3]*100);
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue5Min()
{
	UpdateData(TRUE);
	m_SlideValue[ 4].SetRange(m_ValueMin[4]*100, m_ValueMax[4]*100);
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue6Min()
{
	UpdateData(TRUE);
	m_SlideValue[ 5].SetRange(m_ValueMin[5]*100, m_ValueMax[5]*100);
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue7Min()
{
	UpdateData(TRUE);
	m_SlideValue[ 6].SetRange(m_ValueMin[6]*100, m_ValueMax[6]*100);
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue8Min()
{
	UpdateData(TRUE);
	m_SlideValue[ 7].SetRange(m_ValueMin[7]*100, m_ValueMax[7]*100);
	UpdateData(FALSE);
}


void CTabControlWindow::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
{
	for (int i=0; i < MAX_SLIDE; ++i)
	{
		if (pScrollBar == (CScrollBar*)&m_SlideValue[ i])
		{
			const int curpos = m_SlideValue[ i].GetPos();
			m_ValueText[ i] = (float)curpos / 100.f;
			UpdateData(FALSE);
		}
	}
	
}


//------------------------------------------------------------------------------
/**
@brief 슬라이드 바 값 설정
*/
//------------------------------------------------------------------------------
void CTabControlWindow::SetValue(int idx, float v)
{
	if (idx<0 || idx>=MAX_SLIDE)
		return;
	m_ValueText[ idx] = v;
	m_SlideValue[ idx].SetPos( (int)(v*100.f) );
	UpdateData(FALSE);
}

float CTabControlWindow::GetValue(int idx ) 
{ 
	if (idx<0 || idx>=MAX_SLIDE) 
		return 0; 
	return m_ValueText[ idx]; 
}


//------------------------------------------------------------------------------
/**
@brief Value 에디트창 수정
*/
//------------------------------------------------------------------------------
void CTabControlWindow::OnEnChangeEditValue1()
{
	UpdateData(TRUE);
	m_SlideValue[ 0].SetPos( (int)(m_ValueText[0]*100.f) );
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue2()
{
	UpdateData(TRUE);
	m_SlideValue[ 1].SetPos( (int)(m_ValueText[1]*100.f) );
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue3()
{
	UpdateData(TRUE);
	m_SlideValue[ 2].SetPos( (int)(m_ValueText[2]*100.f) );
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue4()
{
	UpdateData(TRUE);
	m_SlideValue[ 3].SetPos( (int)(m_ValueText[3]*100.f) );
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue5()
{
	UpdateData(TRUE);
	m_SlideValue[ 4].SetPos( (int)(m_ValueText[4]*100.f) );
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue6()
{
	UpdateData(TRUE);
	m_SlideValue[ 5].SetPos( (int)(m_ValueText[5]*100.f) );
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue7()
{
	UpdateData(TRUE);
	m_SlideValue[ 6].SetPos( (int)(m_ValueText[6]*100.f) );
	UpdateData(FALSE);
}
void CTabControlWindow::OnEnChangeEditValue8()
{
	UpdateData(TRUE);
	m_SlideValue[ 7].SetPos( (int)(m_ValueText[7]*100.f) );
	UpdateData(FALSE);
}
