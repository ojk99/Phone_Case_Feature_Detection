#include "login.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OpenCVTeamProjectWinform::login form;
	Application::Run(% form);
}