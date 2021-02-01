#pragma once
#define UILIB_STATIC							// 使用静态库：必须在UIlib.h之前声明
#include "UIlib.h"								// 引入头文件：UIlib.h
using namespace DuiLib;							// 使用命名空间：DuiLib

// 加载导入库或者静态库
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