//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------

#pragma once

class CDbgMessageListener
{
public:
	CDbgMessageListener() {}
	virtual ~CDbgMessageListener() {}
public:
	virtual void Message( int id, LPARAM lParam, WPARAM wParam)=0;
};
