#pragma once
#define UILIB_STATIC							// ʹ�þ�̬�⣺������UIlib.h֮ǰ����
#include "UIlib.h"								// ����ͷ�ļ���UIlib.h
using namespace DuiLib;							// ʹ�������ռ䣺DuiLib

// ���ص������߾�̬��
#ifdef _DEBUG
#   ifdef _UNICODE
#       ifndef UILIB_STATIC
#           pragma comment(lib, "DuiLib_ud.lib")
#       else
#           pragma comment(lib, "DuiLib_Static_ud.lib")
#       endif
#   else
#       ifndef UILIB_STATIC
#           pragma comment(lib, "DuiLib_d.lib")
#       else
#           pragma comment(lib, "DuiLib_Static_d.lib")
#       endif
#   endif
#else
#   ifdef _UNICODE
#       ifndef UILIB_STATIC
#           pragma comment(lib, "DuiLib_u.lib")
#       else
#           pragma comment(lib, "DuiLib_Static_u.lib")
#       endif
#   else
#       ifndef UILIB_STATIC
#           pragma comment(lib, "DuiLib.lib")
#       else
#           pragma comment(lib, "DuiLib_Static.lib")
#       endif
#   endif
#endif