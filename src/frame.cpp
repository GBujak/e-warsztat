#include <wx/wx.h>
#include <iostream>
#include <fstream>
#include "../include/frame.hpp"
#include "../include/data_store.hpp"
#include "../include/globals.hpp"
#include "../include/new_data_window.hpp"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(wxID_OPEN,  MyFrame::OnOpen)
    EVT_MENU(wxID_SAVE,  MyFrame::OnSave)
    EVT_MENU(wxID_NEW,   MyFrame::OnNew)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString& title,
    const wxPoint& pos, const wxSize& size) 
    : wxFrame (NULL, wxID_ANY, title, pos, size) {
    
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_OPEN, "&Open...\tCtrl-O");
    menuFile->Append(wxID_SAVE, "&Save...\tCtrl-S");
    menuFile->Append(wxID_NEW, "&New...\tCtrl-N");
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );

    auto test = new wxBoxSizer{wxVERTICAL};
    test->Add( new wxStaticText{this, -1, "Hello\nWorld!"} );
    SetSizerAndFit(test);

    SetMenuBar(menuBar);
}

void MyFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This is a wxWidgets Hello world sample",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::OnOpen(wxCommandEvent& event) {
    wxFileDialog openFileDialog(this, _("Open XYZ file"), "", "",
                                "XYZ files (*.xyz)|*.xyz", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;
    
    std::ifstream stream;
    stream.open(openFileDialog.GetPath());
    if (stream.fail()) {
        wxLogError("Cannot open file " + openFileDialog.GetPath());
        return;
    }

    g_datastore.load(stream);
}

void MyFrame::OnSave(wxCommandEvent& event) {
    wxFileDialog 
        saveFileDialog(this, _("Save XYZ file"), "", "",
                       "XYZ files (*.xyz)|*.xyz", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;
    
    std::ofstream stream;
    stream.open(saveFileDialog.GetPath());
    if (stream.fail()) {
        wxLogError("Cannot open file " + saveFileDialog.GetPath());
        return;
    }

    g_datastore.save(stream);
}

void MyFrame::OnNew(wxCommandEvent& event) {
    new_data_window_t new_data_window {this};
    new_data_window.ShowModal();
}