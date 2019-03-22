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
	private: System::Windows::Forms::Label^  staminaSize;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  healthSize;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  ageBox;
	private: System::Windows::Forms::Label^  Age;
	private: System::Windows::Forms::Label^  GenderBox;
	private: System::Windows::Forms::Label^  Gender;


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
			this->GenderBox = (gcnew System::Windows::Forms::Label());
			this->Gender = (gcnew System::Windows::Forms::Label());
			this->ageBox = (gcnew System::Windows::Forms::Label());
			this->Age = (gcnew System::Windows::Forms::Label());
			this->healthSize = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->staminaSize = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ySize = (gcnew System::Windows::Forms::Label());
			this->xSize = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->x = (gcnew System::Windows::Forms::Label());
			this->NameL = (gcnew System::Windows::Forms::Label());
			this->groupLabel = (gcnew System::Windows::Forms::Label());
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
			this->StatBox->Controls->Add(this->GenderBox);
			this->StatBox->Controls->Add(this->Gender);
			this->StatBox->Controls->Add(this->ageBox);
			this->StatBox->Controls->Add(this->Age);
			this->StatBox->Controls->Add(this->healthSize);
			this->StatBox->Controls->Add(this->label3);
			this->StatBox->Controls->Add(this->staminaSize);
			this->StatBox->Controls->Add(this->label2);
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
			// GenderBox
			// 
			this->GenderBox->AutoSize = true;
			this->GenderBox->Location = System::Drawing::Point(68, 208);
			this->GenderBox->Name = L"GenderBox";
			this->GenderBox->Size = System::Drawing::Size(0, 13);
			this->GenderBox->TabIndex = 13;
			// 
			// Gender
			// 
			this->Gender->AutoSize = true;
			this->Gender->Location = System::Drawing::Point(10, 208);
			this->Gender->Name = L"Gender";
			this->Gender->Size = System::Drawing::Size(42, 13);
			this->Gender->TabIndex = 12;
			this->Gender->Text = L"Gender";
			// 
			// ageBox
			// 
			this->ageBox->AutoSize = true;
			this->ageBox->Location = System::Drawing::Point(68, 179);
			this->ageBox->Name = L"ageBox";
			this->ageBox->Size = System::Drawing::Size(0, 13);
			this->ageBox->TabIndex = 11;
			// 
			// Age
			// 
			this->Age->AutoSize = true;
			this->Age->Location = System::Drawing::Point(10, 179);
			this->Age->Name = L"Age";
			this->Age->Size = System::Drawing::Size(26, 13);
			this->Age->TabIndex = 10;
			this->Age->Text = L"Age";
			// 
			// healthSize
			// 
			this->healthSize->AutoSize = true;
			this->healthSize->Location = System::Drawing::Point(68, 146);
			this->healthSize->Name = L"healthSize";
			this->healthSize->Size = System::Drawing::Size(0, 13);
			this->healthSize->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Health";
			// 
			// staminaSize
			// 
			this->staminaSize->AutoSize = true;
			this->staminaSize->Location = System::Drawing::Point(68, 114);
			this->staminaSize->Name = L"staminaSize";
			this->staminaSize->Size = System::Drawing::Size(0, 13);
			this->staminaSize->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Stamina";
			// 
			// ySize
			// 
			this->ySize->AutoSize = true;
			this->ySize->Location = System::Drawing::Point(68, 82);
			this->ySize->Name = L"ySize";
			this->ySize->Size = System::Drawing::Size(0, 13);
			this->ySize->TabIndex = 5;
			// 
			// xSize
			// 
			this->xSize->AutoSize = true;
			this->xSize->Location = System::Drawing::Point(68, 51);
			this->xSize->Name = L"xSize";
			this->xSize->Size = System::Drawing::Size(0, 13);
			this->xSize->TabIndex = 4;
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
			// x
			// 
			this->x->AutoSize = true;
			this->x->Location = System::Drawing::Point(10, 51);
			this->x->Name = L"x";
			this->x->Size = System::Drawing::Size(14, 13);
			this->x->TabIndex = 2;
			this->x->Text = L"X";
			// 
			// NameL
			// 
			this->NameL->AutoSize = true;
			this->NameL->Location = System::Drawing::Point(68, 20);
			this->NameL->Name = L"NameL";
			this->NameL->Size = System::Drawing::Size(0, 13);
			this->NameL->TabIndex = 1;
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
		mStatWindow->SetButtons(NameL, xSize, ySize,staminaSize,healthSize,ageBox,GenderBox);

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
