#include <afxdisp.h>

#include "TestRunnerGUI.h"

#include <cppunit/ui/mfc/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

TestRunnerGUI::TestRunnerGUI()
{
}

TestRunnerGUI theApp;

BOOL 
TestRunnerGUI::InitInstance()
{
    RunTests();

    return FALSE;
}


void 
TestRunnerGUI::RunTests()
{
    CPPUNIT_NS::MfcUi::TestRunner runner;

    runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );

    runner.run();
}