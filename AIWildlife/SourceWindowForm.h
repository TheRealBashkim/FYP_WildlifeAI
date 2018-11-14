#pragma once
#include "Source.h"

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
			this->SuspendLayout();
			// 
			// SDLWindow
			// 
			this->SDLWindow->Location = System::Drawing::Point(12, 12);
			this->SDLWindow->Name = L"SDLWindow";
			this->SDLWindow->Size = System::Drawing::Size(957, 777);
			this->SDLWindow->TabIndex = 0;
			this->SDLWindow->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SourceWindowForm::SDLWindow_Paint);
			// 
			// SourceWindowForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->SDLWindow);
			this->Name = L"SourceWindowForm";
			this->Text = L"SourceWindowForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &SourceWindowForm::SourceWindowForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void SDLWindow_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	}
	private: System::Void SourceWindowForm_Load(System::Object^  sender, System::EventArgs^  e) {
		int handler = (int)SDLWindow->Handle.ToPointer();
		Source * _Source = new Source(handler);
	}
	};
}
