//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------

#if !defined(__DbgMonitorExport_h__)
#define __DbgMonitorExport_h__

/*
#include "Util/tstring.h"
#include "RealSoccer/Scene/UINode.h"

class CNetBase;
class CDbgMessageListener;
class CDbgMonitorInterface
{
public:
	CDbgMonitorInterface() {}
	virtual ~CDbgMonitorInterface() {}

public:
	virtual void	Modalese(HWND hWnd)=0;
	virtual BOOL	MessageProc(LPMSG lpMsg)=0;

	// Debug Method
	virtual void	SetMessageListener(CDbgMessageListener *p)=0;
	virtual void	PrintMsg(const TCHAR* str)=0;
	virtual void	PrintNetMsg(const TCHAR* str)=0;
	virtual void	PrintScaleformMsg(int movieID, const TCHAR* str)=0;

	virtual void	SetValue(int idx, float v)=0;
	virtual float 	GetValue(int idx )=0;

	virtual void	SetTitleName(const TCHAR *titleName)=0;
	virtual void	SetUITree(ui::CUINode *pNode)=0;
	virtual void	SetMouseOverUI(int movieID)=0;
	virtual void	SetNetwork(CNetManager *pNet)=0;

};
/**/

#endif // __DbgMonitorExport_h__
