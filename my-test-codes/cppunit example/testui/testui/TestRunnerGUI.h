#include <afxwin.h>

class TestRunnerGUI : public CWinApp
{
public:
    TestRunnerGUI();
    virtual BOOL InitInstance();

private:
    void RunTests();
};