//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------

#if !defined(__DbgMonitor_h__)
#define __DbgMonitor_h__

#include "DbgMonitorExport.h"
#include "DbgMessage.h"
#include "DbgMessageListener.h"
/*

class CMainDialog;
class CDbgMessageListener;
class CDbgMonitor : public CDbgMonitorInterface
{
public:
	CDbgMonitor();
	virtual ~CDbgMonitor();

public:
	CMainDialog			*m_pMainDialog;
	CDbgMessageListener *m_pMessageListener;	// 모니터로 부터오는 메세지를 받는다.

public:
	virtual void	Modalese(HWND hWnd);
	virtual BOOL	MessageProc(LPMSG lpMsg);

	// Debug Method
	virtual void	SetMessageListener(CDbgMessageListener *p) override;

	virtual void	PrintMsg(const TCHAR* str) override;
	virtual void	PrintNetMsg(const TCHAR* str) override;
	virtual void	PrintScaleformMsg(int movieID, const TCHAR* str) override;

	virtual void	SetValue(int idx, float v) override;
	virtual float 	GetValue(int idx ) override;

	virtual void	SetTitleName(const TCHAR *titleName) override;
	virtual void	SetUITree(ui::CUINode *pNode) override;
	virtual void	SetMouseOverUI(int movieID) override;
	virtual void	SetNetwork(CNetManager *pNet) override;

};
/**/

#endif // __DbgMonitor_h__
