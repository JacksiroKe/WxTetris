#include "main.h"
#include "WxTetris.h"

#ifdef __WXMAC__
#include <ApplicationServices/ApplicationServices.h>
#endif /* __WXMAC__ */

IMPLEMENT_APP(MainApp);

bool MainApp::OnInit()
{
#ifdef __WXMAC__
    ProcessSerialNumber psn;
    GetCurrentProcess(&psn);
    TransformProcessType(&psn, kProcessTransformToForegroundApplication);
#endif /* __WXMAC__ */

    WxTetris* game = new WxTetris(wxT("WxTetris Game"));
    game->Centre();
    game->Show(true);
    
    return true;
}
