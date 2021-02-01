#include "CMainWnd.h"

LRESULT CMainWnd::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	LRESULT lRes = 0;
	switch (uMsg)
	{
	case WM_TIMER:		lRes = OnTimer(uMsg, wParam, lParam, bHandled); break;
	}

	return lRes;
}

LRESULT CMainWnd::OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	bHandled = TRUE;

	switch (wParam)
	{
	case TIMER_ID_TEST:
	{
		;
	}
	break;

	default:
	{
		bHandled = FALSE;
	}
	break;
	}

	return 0;
}

void CMainWnd::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		if (msg.pSender->GetName() == _T("btn"))
		{
			::MessageBox(NULL, _T("按钮内容"), _T("按钮标题"), NULL);
		}
	}
}
