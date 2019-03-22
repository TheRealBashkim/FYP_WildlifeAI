#include "StatWindow.h"


StatWindow^ StatWindow::Initialize()
{
	if(mInstance == nullptr)
	{
		mInstance = gcnew StatWindow();
	}
	return mInstance;
}

void StatWindow::SetAgent(BaseAgent * mAgent)
{
	NumberFormatInfo ^ set = gcnew NumberFormatInfo();
	set->NumberDecimalDigits = 2;

	mName->Text = msclr::interop::marshal_as<String^>(mAgent->GetName());
	mX->Text = mAgent->GetPosition().x.ToString("N",set);
	mY->Text = mAgent->GetPosition().y.ToString("N",set);
	mStamina->Text = mAgent->GetStamina().ToString("N",set);
	mHealth->Text = mAgent->GetHealth().ToString("N",set);
	mAge->Text = mAgent->GetAge().ToString("N",set);
	mGender->Text = msclr::interop::marshal_as<String^>(mAgent->GetChromosome()->GetGene()->mGender);
}

void StatWindow::SetButtons(Label^ Name, Label^ X, Label^ Y,Label ^ Stamina, Label ^ Health, Label ^ Age, Label ^ Gender)
{
	mName = Name;
	mX = X;
	mY = Y;
	mStamina = Stamina;
	mHealth = Health;
	mAge = Age;
	mGender = Gender;
	
}


StatWindow::StatWindow()
{
}
