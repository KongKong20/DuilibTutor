#pragma once
#include "DuilibBase.h"

#define TIMER_ID_TEST	(1)

class CMainWnd : public WindowImplBase
{
public:
    virtual LPCTSTR    GetWindowClassName() const { return _T("MainWnd"); }
    virtual CDuiString GetSkinFile() { return _T("MainWnd.xml"); }
    virtual CDuiString GetSkinFolder() { return _T(""); }

    virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    virtual LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

    virtual void Notify(TNotifyUI& msg);
};

