// testuiproj.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CtestuiprojApp:
// �йش����ʵ�֣������ testuiproj.cpp
//

class CtestuiprojApp : public CWinApp
{
public:
	CtestuiprojApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
    
private:
    void RunTest();
};

extern CtestuiprojApp theApp;