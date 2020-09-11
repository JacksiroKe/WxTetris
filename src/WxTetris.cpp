#include "WxTetris.h"

WxTetris::WxTetris(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(450, 500), wxCAPTION | wxCLOSE_BOX | wxMINIMIZE_BOX | wxSYSTEM_MENU | wxTAB_TRAVERSAL)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetStatusText(wxT("Score: 0"));

	wxBoxSizer* MainLayout;
	MainLayout = new wxBoxSizer(wxHORIZONTAL);

	PanelLeft = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* LeftLayout;
	LeftLayout = new wxBoxSizer(wxVERTICAL);


	PanelLeft->SetSizer(LeftLayout);
	PanelLeft->Layout();
	LeftLayout->Fit(PanelLeft);
	MainLayout->Add(PanelLeft, 1, wxEXPAND | wxALL, 5);

	PanelGaming = new Board(this);
	MainLayout->Add(PanelGaming, 2, wxEXPAND | wxALL, 5);

	PanelRight = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* RightLayout;
	RightLayout = new wxBoxSizer(wxVERTICAL);

	PanelRight->SetSizer(RightLayout);
	PanelRight->Layout();
	RightLayout->Fit(PanelRight);
	MainLayout->Add(PanelRight, 1, wxEXPAND | wxALL, 5);

	PanelGaming->SetFocus();
	PanelGaming->Start();
	srand(time(NULL));

	this->SetSizer(MainLayout);
	this->Layout();

	CreateMenu();
	this->Centre(wxBOTH);
}

void WxTetris::CreateMenu()
{
	MyMenuBar = new wxMenuBar(0);
	MenuFile = new wxMenu();
	wxMenuItem* MenuGameNew;
	MenuGameNew = new wxMenuItem(MenuFile, wxID_ANY, wxString(wxT("New Game")), wxEmptyString, wxITEM_NORMAL);
	MenuFile->Append(MenuGameNew);

	wxMenuItem* MenuGamePause;
	MenuGamePause = new wxMenuItem(MenuFile, wxID_ANY, wxString(wxT("Pause Game")), wxEmptyString, wxITEM_NORMAL);
	MenuFile->Append(MenuGamePause);

	wxMenuItem* MenuGameReset;
	MenuGameReset = new wxMenuItem(MenuFile, wxID_ANY, wxString(wxT("Reset Game")), wxEmptyString, wxITEM_NORMAL);
	MenuFile->Append(MenuGameReset);

	MenuFile->AppendSeparator();

	wxMenuItem* MenuExit;
	MenuExit = new wxMenuItem(MenuFile, wxID_ANY, wxString(wxT("Exit")), wxEmptyString, wxITEM_NORMAL);
	MenuFile->Append(MenuExit);

	MyMenuBar->Append(MenuFile, wxT("File"));

	MenuTools = new wxMenu();
	wxMenuItem* MenuOptions;
	MenuOptions = new wxMenuItem(MenuTools, wxID_ANY, wxString(wxT("Game Options")), wxEmptyString, wxITEM_NORMAL);
	MenuTools->Append(MenuOptions);

	MyMenuBar->Append(MenuTools, wxT("Tools"));

	MenuHelp = new wxMenu();
	wxMenuItem* MenuAbout;
	MenuAbout = new wxMenuItem(MenuHelp, wxID_ANY, wxString(wxT("About")), wxEmptyString, wxITEM_NORMAL);
	MenuHelp->Append(MenuAbout);

	MyMenuBar->Append(MenuHelp, wxT("Help"));

	this->SetMenuBar(MyMenuBar);
}

WxTetris::~WxTetris()
{
}