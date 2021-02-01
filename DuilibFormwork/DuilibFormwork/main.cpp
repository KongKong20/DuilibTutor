#include "CMainWnd.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	CPaintManagerUI::SetInstance(hInstance);

	CMainWnd mainWnd;
	mainWnd.Create(NULL, _T("БъЬт"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mainWnd.CenterWindow();
	mainWnd.ShowModal();

	return 0;
}