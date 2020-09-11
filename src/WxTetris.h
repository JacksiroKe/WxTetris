#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/frame.h>

#include "Board.h"

class WxTetris : public wxFrame
{
private:

protected:
	wxPanel* PanelLeft;
	Board* PanelGaming;
	wxPanel* PanelRight;

	wxMenuBar* MyMenuBar;
	wxMenu* MenuFile;
	wxMenu* MenuTools;
	wxMenu* MenuHelp;

public:
	WxTetris(const wxString& title);
	void CreateMenu();
	~WxTetris();

};