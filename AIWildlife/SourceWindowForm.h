#pragma once
#include "Source.h"
#include "Messaging.h"

namespace AIWildlife {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SourceWindowForm
	/// </summary>
	public ref class SourceWindowForm : public System::Windows::Forms::Form
	{
	public:
		SourceWindowForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SourceWindowForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  SDLWindow;
	private: System::Windows::Forms::RichTextBox^  ConsoleWindow;
	private: System::Windows::Forms::Label^  Console;
	private: Messaging ^ mMessaging;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SDLWindow = (gcnew System::Windows::Forms::Panel());
			this->ConsoleWindow = (gcnew System::Windows::Forms::RichTextBox());
			this->Console = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// SDLWindow
			// 
			this->SDLWindow->Location = System::Drawing::Point(12, 12);
			this->SDLWindow->Name = L"SDLWindow";
			this->SDLWindow->Size = System::Drawing::Size(875, 875);
			this->SDLWindow->TabIndex = 0;
			this->SDLWindow->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SourceWindowForm::SDLWindow_Paint);
			// 
			// ConsoleWindow
			// 
			this->ConsoleWindow->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ConsoleWindow->Location = System::Drawing::Point(893, 28);
			this->ConsoleWindow->Name = L"ConsoleWindow";
			this->ConsoleWindow->ReadOnly = true;
			this->ConsoleWindow->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedVertical;
			this->ConsoleWindow->Size = System::Drawing::Size(400, 410);
			this->ConsoleWindow->TabIndex = 1;
			this->ConsoleWindow->Text = L"";
			this->ConsoleWindow->TextChanged += gcnew System::EventHandler(this, &SourceWindowForm::ConsoleWindow_TextChanged);
			// 
			// Console
			// 
			this->Console->AutoSize = true;
			this->Console->Location = System::Drawing::Point(890, 12);
			this->Console->Name = L"Console";
			this->Console->Size = System::Drawing::Size(45, 13);
			this->Console->TabIndex = 2;
			this->Console->Text = L"Console";
			// 
			// SourceWindowForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->Console);
			this->Controls->Add(this->ConsoleWindow);
			this->Controls->Add(this->SDLWindow);
			this->Name = L"SourceWindowForm";
			this->Text = L"SourceWindowForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &SourceWindowForm::SourceWindowForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SDLWindow_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	}
	private: System::Void SourceWindowForm_Load(System::Object^  sender, System::EventArgs^  e) {
		mMessaging = Messaging::Initialize();
		mMessaging->SetMessageBox(ConsoleWindow);
		int handler = (int)SDLWindow->Handle.ToPointer();
		Source ^ _Source = gcnew Source(handler);
	}
	private: System::Void ConsoleWindow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		ConsoleWindow->SelectionStart = ConsoleWindow->Text->Length;
		ConsoleWindow->ScrollToCaret();
	}
};
}
