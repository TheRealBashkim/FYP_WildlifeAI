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
	mName->Text = msclr::interop::marshal_as<String^>(mAgent->GetName());
	mX->Text = mAgent->GetPosition().x.ToString();
	mY->Text = mAgent->GetPosition().y.ToString();
	mStamina->Text = mAgent->GetStamina().ToString();
	mHealth->Text = mAgent->GetHealth().ToString();
}

void StatWindow::SetButtons(Label^ Name, Label^ X, Label^ Y,Label ^ Stamina, Label ^ Health)
{
	mName = Name;
	mX = X;
	mY = Y;
	mStamina = Stamina;
	mHealth = Health;
	
}


StatWindow::StatWindow()
{
}
