// testuiproj.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "testuiproj.h"
#include "testuiprojDlg.h"

#include <cppunit/ui/mfc/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestuiprojApp

BEGIN_MESSAGE_MAP(CtestuiprojApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CtestuiprojApp ����

CtestuiprojApp::CtestuiprojApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CtestuiprojApp ����

CtestuiprojApp theApp;


// CtestuiprojApp ��ʼ��

BOOL CtestuiprojApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	//CtestuiprojDlg dlg;
	//m_pMainWnd = &dlg;
	//INT_PTR nResponse = dlg.DoModal();
	//if (nResponse == IDOK)
	//{
	//	// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
	//	//  �Ի���Ĵ���
	//}
	//else if (nResponse == IDCANCEL)
	//{
	//	// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
	//	//  �Ի���Ĵ���
	//}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�

    RunTest() ;
	return FALSE;
}

void CtestuiprojApp::RunTest()
{
    CPPUNIT_NS::MfcUi::TestRunner runner;

    runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );

    runner.run();
}
