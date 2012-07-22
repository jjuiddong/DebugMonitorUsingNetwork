// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // �Ϻ� CString �����ڴ� ��������� ����˴ϴ�.

#include <afxwin.h>         // MFC �ٽ� �� ǥ�� ���� ����Դϴ�.
#include <afxext.h>         // MFC Ȯ���Դϴ�.

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE Ŭ�����Դϴ�.
#include <afxodlgs.h>       // MFC OLE ��ȭ ���� Ŭ�����Դϴ�.
#include <afxdisp.h>        // MFC �ڵ�ȭ Ŭ�����Դϴ�.
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC �����ͺ��̽� Ŭ�����Դϴ�.
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO �����ͺ��̽� Ŭ�����Դϴ�.
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // Windows ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <afxdhtml.h>


/*
//-----------------------------------------------------
//	ProudNet Network Base
//-----------------------------------------------------

#ifdef	_DEBUG
#	pragma comment(lib, "ProudNet_2008_Debug_static_CRT.lib" )
#else	//	_DEBUG
#	pragma comment(lib, "ProudNet_2008_Release_static_CRT.lib" )
#endif	//	_DEBUG

#include "ProudNet.h"
// #include "ProudDB.h"
// #include "AdoWrap.h"


//-----------------------------------------------------
//	ProudNet Common
//-----------------------------------------------------

#ifdef	_DEBUG
#	pragma comment(lib, "PNetCommon_Debug_Win32.lib" )
#else	//	_DEBUG
#	pragma comment(lib, "PNetCommon_Release_Win32.lib" )
#endif	//	_DEBUG

#include "PNetCommon.h"


//-----------------------------------------------------
//	ProudNet Client
//-----------------------------------------------------
#ifdef	_DEBUG
#	pragma comment(lib, "PNetClient_Debug_Win32.lib" )
#else	//	_DEBUG
#	pragma comment(lib, "PNetClient_Release_Win32.lib" )
#endif	//	_DEBUG

#include "PNetClient.h"
//#include <afxdhtml.h>
/**/



// RealSoccer UI Library
// #include "Util/tstring.h"
// #include "RealSoccer/Scene/UINode.h"
//#include "RealSoccer/Scene/UIInclude.h"


#include "../DbgMonitor/DbgWrap.h"
