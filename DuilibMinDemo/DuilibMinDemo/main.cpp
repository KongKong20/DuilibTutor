#include "UIlib.h"                      // ����ͷ�ļ���UIlib.h
using namespace DuiLib;                 // ʹ�������ռ䣺DuiLib
#pragma comment(lib, "DuiLib_ud.lib")   // ���ص���⣺DuiLib_ud.lib

//CWindowWnd������Window��Ϣ INotifyUI������Duilib��Ϣ
class CDuilibWnd : public CWindowWnd, public INotifyUI  
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DuiWnd"); }

	// ��Ӧ��Ϣ ��дINotifyUI::Notify
	virtual void Notify(TNotifyUI& msg) 
	{
		//if (msg.sType == DUI_MSGTYPE_CLICK)
		if (msg.sType == _T("click"))	
		{
			if (msg.pSender->GetName() == _T("btn"))
			{
				::MessageBox(NULL, _T("��ť����"), _T("��ť����"), NULL);
			}
		}
	}

	// ��дCWindowWnd::HandleMessage������Ϣ
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) 
	{
		LRESULT lRes = 0;
		// ��ʼ��������Ϣ
		if (uMsg == WM_CREATE) 				   
        {
			// ��ʼ�����ƹ�������m_hWnd�����һ����ϢWM_NCCREATE�и�ֵ
			m_PaintManager.Init(m_hWnd);		
			
			// ʹ��XML�����ļ����ɽ���
			CDialogBuilder builder;				
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), 0, NULL, &m_PaintManager);
			ASSERT(pRoot && "Failed to parse XML");

			// ���CControlUI�������ڹ������
			m_PaintManager.AttachDialog(pRoot);	

			// ���INotifyUI�������ڴ�����Ϣ
			m_PaintManager.AddNotifier(this);	

			return lRes;
		}

		// CPaintManagerUI������Ϣ
		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;	

		// CWindowWnd���״�����Ϣ
		return __super::HandleMessage(uMsg, wParam, lParam);						
	}

protected:
	// ���ƹ�������������ƽ���͹�����Ϣ
	CPaintManagerUI m_PaintManager;				
};

int APIENTRY _tWinMain(
	_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPWSTR lpCmdLine, 
	_In_ int nShowCmd )
{
	// ���ƹ�����CPaintManagerUI�󶨴��ھ��
	CPaintManagerUI::SetInstance(hInstance);    

	// ���ƹ�����CPaintManagerUI������ԴĿ¼�����ڼ���XML
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()); 

	// ��������
	CDuilibWnd duilibWnd;  
	duilibWnd.Create(NULL, _T("����"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE); 

	// ��ʾ���ڲ��Ҽ�����Ϣ
	duilibWnd.ShowModal();  

	return 0;
}