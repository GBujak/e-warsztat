#include <wx/wx.h>
#include "../include/app.hpp"
#include "../include/frame.hpp"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame(
        "Hello world", {50, 50}, {450, 340});
    frame->Show(true);
    return true;
}