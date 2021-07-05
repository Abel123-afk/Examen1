#include "MyForm.h"
using namespace System;
using namespace Windows::Forms;
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Examen1::MyForm());
}
