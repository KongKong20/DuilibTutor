#define UILIB_STATIC							// ������̬�꣺UILIB_STATIC��������UIlib.h֮ǰ������
#include "UIlib.h"								// ����ͷ�ļ���UIlib.h
using namespace DuiLib;							// ʹ�������ռ䣺DuiLib
#pragma comment(lib, "DuiLib_Static_ud.lib")	// ���ؾ�̬�⣺DuiLib_Static_ud.lib

class CDuilibWnd : public CWindowWnd, public INotifyUI  //CWindowWnd������Window��Ϣ INotifyUI������Duilib��Ϣ
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DuiWnd"); }

	virtual void Notify(TNotifyUI& msg) // ��Ӧ��Ϣ ��дINotifyUI::Notify
	{
		if (msg.sType == _T("click"))	//if (msg.sType == DUI_MSGTYPE_CLICK)
		{
			if (msg.pSender->GetName() == _T("btn"))
			{
				::MessageBox(NULL, _T("��ť����"), _T("��ť����"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) // ��дCWindowWnd::HandleMessage������Ϣ
	{
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE) 				    // ��ʼ��������Ϣ
        {
			m_PaintManager.Init(m_hWnd);		// ��ʼ�����ƹ�������m_hWnd�����һ����ϢWM_NCCREATE�и�ֵ
			
			CDialogBuilder builder;				// ʹ��XML�����ļ����ɽ���
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), 0, NULL, &m_PaintManager);
			ASSERT(pRoot && "Failed to parse XML");

			

			m_PaintManager.AttachDialog(pRoot);	// ���CControlUI�������ڹ������
			m_PaintManager.AddNotifier(this);	// ���INotifyUI�������ڴ�����Ϣ

			return lRes;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;	// CPaintManagerUI������Ϣ
		return __super::HandleMessage(uMsg, wParam, lParam);						// CWindowWnd���״�����Ϣ
	}

protected:
	CPaintManagerUI m_PaintManager;				// ���ƹ�������������ƽ���͹�����Ϣ
};

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd )
{
	CPaintManagerUI::SetInstance(hInstance);    // ���ƹ�����CPaintManagerUI�󶨴��ھ��
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()); // ���ƹ�����CPaintManagerUI������ԴĿ¼�����ڼ���XML

	CDuilibWnd duilibWnd;   // ����Duilib���ڶ���
	duilibWnd.Create(NULL, _T("����"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE); // ��������
	duilibWnd.ShowModal();  // ��ʾ���ڲ��Ҽ�����Ϣ

	return 0;
}