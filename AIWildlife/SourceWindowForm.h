#pragma once
#include "Source.h"
#include "Messaging.h"
#include "StatWindow.h"

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
	private: StatWindow ^ mStatWindow;
	private: System::Windows::Forms::GroupBox^  StatBox;
	private: System::Windows::Forms::Label^  NameL;
	private: System::Windows::Forms::Label^  groupLabel;
	private: System::Windows::Forms::Label^  ySize;
	private: System::Windows::Forms::Label^  xSize;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  x;


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
			this->StatBox = (gcnew System::Windows::Forms::GroupBox());
			this->groupLabel = (gcnew System::Windows::Forms::Label());
			this->NameL = (gcnew System::Windows::Forms::Label());
			this->x = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->xSize = (gcnew System::Windows::Forms::Label());
			this->ySize = (gcnew System::Windows::Forms::Label());
			this->StatBox->SuspendLayout();
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
			this->ConsoleWindow->Location = System::Drawing::Point(893, 477);
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
			this->Console->Location = System::Drawing::Point(890, 461);
			this->Console->Name = L"Console";
			this->Console->Size = System::Drawing::Size(45, 13);
			this->Console->TabIndex = 2;
			this->Console->Text = L"Console";
			// 
			// StatBox
			// 
			this->StatBox->Controls->Add(this->ySize);
			this->StatBox->Controls->Add(this->xSize);
			this->StatBox->Controls->Add(this->label1);
			this->StatBox->Controls->Add(this->x);
			this->StatBox->Controls->Add(this->NameL);
			this->StatBox->Controls->Add(this->groupLabel);
			this->StatBox->Location = System::Drawing::Point(893, 12);
			this->StatBox->Name = L"StatBox";
			this->StatBox->Size = System::Drawing::Size(400, 446);
			this->StatBox->TabIndex = 3;
			this->StatBox->TabStop = false;
			this->StatBox->Enter += gcnew System::EventHandler(this, &SourceWindowForm::StatBox_Enter);
			// 
			// groupLabel
			// 
			this->groupLabel->AutoSize = true;
			this->groupLabel->Location = System::Drawing::Point(7, 20);
			this->groupLabel->Name = L"groupLabel";
			this->groupLabel->Size = System::Drawing::Size(35, 13);
			this->groupLabel->TabIndex = 0;
			this->groupLabel->Text = L"Name";
			// 
			// NameL
			// 
			this->NameL->AutoSize = true;
			this->NameL->Location = System::Drawing::Point(68, 20);
			this->NameL->Name = L"NameL";
			this->NameL->Size = System::Drawing::Size(0, 13);
			this->NameL->TabIndex = 1;
			// 
			// x
			// 
			this->x->AutoSize = true;
			this->x->Location = System::Drawing::Point(10, 51);
			this->x->Name = L"x";
			this->x->Size = System::Drawing::Size(14, 13);
			this->x->TabIndex = 2;
			this->x->Text = L"X";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Y";
			// 
			// xSize
			// 
			this->xSize->AutoSize = true;
			this->xSize->Location = System::Drawing::Point(68, 51);
			this->xSize->Name = L"xSize";
			this->xSize->Size = System::Drawing::Size(0, 13);
			this->xSize->TabIndex = 4;
			// 
			// ySize
			// 
			this->ySize->AutoSize = true;
			this->ySize->Location = System::Drawing::Point(68, 82);
			this->ySize->Name = L"ySize";
			this->ySize->Size = System::Drawing::Size(0, 13);
			this->ySize->TabIndex = 5;
			// 
			// SourceWindowForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->StatBox);
			this->Controls->Add(this->Console);
			this->Controls->Add(this->ConsoleWindow);
			this->Controls->Add(this->SDLWindow);
			this->Name = L"SourceWindowForm";
			this->Text = L"X";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &SourceWindowForm::SourceWindowForm_Load);
			this->StatBox->ResumeLayout(false);
			this->StatBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SDLWindow_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	}
	private: System::Void SourceWindowForm_Load(System::Object^  sender, System::EventArgs^  e) {
		mMessaging = Messaging::Initialize();
		mStatWindow = StatWindow::Initialize();
		mMessaging->SetMessageBox(ConsoleWindow);
		mStatWindow->SetButtons(NameL, xSize, ySize);

		int handler = (int)SDLWindow->Handle.ToPointer();
		Source ^ _Source = gcnew Source(handler);
	}
	private: System::Void ConsoleWindow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		ConsoleWindow->SelectionStart = ConsoleWindow->Text->Length;
		ConsoleWindow->ScrollToCaret();
	}
private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void StatBox_Enter(System::Object^  sender, System::EventArgs^  e) {
}
};
}
