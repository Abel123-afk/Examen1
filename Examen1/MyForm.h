#pragma once
#include"CControladora.h"
#include"CArchivoTexto.h"
namespace Examen1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			miarchivo = new CArchivoTexto();
			S = miarchivo->retornarNumero("configuracion.txt",0);
			T= miarchivo->retornarNumero("configuracion.txt", 1);
			g = this->CreateGraphics();
			imgJugador = gcnew Bitmap("imagenes\\jugadores.png");
			obj = new CControladora(g,S,T);
		}
	private:
		CControladora* obj;
		Bitmap^ imgJugador;
		Graphics^ g;
		CArchivoTexto* miarchivo;
		int S, T;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Timer^ timerMain;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Interval = 1000;
			this->timerMain->Tick += gcnew System::EventHandler(this, &MyForm::timerMain_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(545, 436);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(BackColor);
		obj->run(buffer->Graphics, imgJugador);
		if (obj->getTermino())
		{
			timerMain->Enabled = false;
		}
		buffer->Render(g);
		delete buffer;
	}
	};
}
