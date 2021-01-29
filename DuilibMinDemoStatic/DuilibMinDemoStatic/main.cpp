#define UILIB_STATIC							// 声明静态宏：UILIB_STATIC（必须在UIlib.h之前声明）
#include "UIlib.h"								// 引入头文件：UIlib.h
using namespace DuiLib;							// 使用命名空间：DuiLib
#pragma comment(lib, "DuiLib_Static_ud.lib")	// 加载静态库：DuiLib_Static_ud.lib

class CDuilibWnd : public CWindowWnd, public INotifyUI  //CWindowWnd：处理Window消息 INotifyUI：处理Duilib消息
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DuiWnd"); }

	virtual void Notify(TNotifyUI& msg) // 响应消息 重写INotifyUI::Notify
	{
		if (msg.sType == _T("click"))	//if (msg.sType == DUI_MSGTYPE_CLICK)
		{
			if (msg.pSender->GetName() == _T("btn"))
			{
				::MessageBox(NULL, _T("按钮内容"), _T("按钮标题"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) // 重写CWindowWnd::HandleMessage处理消息
	{
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE) 				    // 初始化窗口消息
        {
			m_PaintManager.Init(m_hWnd);		// 初始化绘制管理器，m_hWnd句柄在一个消息WM_NCCREATE中赋值
			
			CDialogBuilder builder;				// 使用XML布局文件生成界面
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), 0, NULL, &m_PaintManager);
			ASSERT(pRoot && "Failed to parse XML");

			

			m_PaintManager.AttachDialog(pRoot);	// 添加CControlUI对象，用于管理界面
			m_PaintManager.AddNotifier(this);	// 添加INotifyUI对象，用于处理消息

			return lRes;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;	// CPaintManagerUI处理消息
		return __super::HandleMessage(uMsg, wParam, lParam);						// CWindowWnd兜底处理消息
	}

protected:
	CPaintManagerUI m_PaintManager;				// 绘制管理器：负责绘制界面和管理消息
};

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd )
{
	CPaintManagerUI::SetInstance(hInstance);    // 绘制管理器CPaintManagerUI绑定窗口句柄
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()); // 绘制管理器CPaintManagerUI设置资源目录，用于加载XML

	CDuilibWnd duilibWnd;   // 声明Duilib窗口对象
	duilibWnd.Create(NULL, _T("标题"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE); // 创建窗口
	duilibWnd.ShowModal();  // 显示窗口并且监听消息

	return 0;
}