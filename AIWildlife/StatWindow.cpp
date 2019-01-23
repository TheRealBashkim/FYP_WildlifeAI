#include "StatWindow.h"


StatWindow^ StatWindow::Initialize()
{
	if(mInstance == nullptr)
	{
		mInstance = gcnew StatWindow();
	}
	return mInstance;
}

void StatWindow::SetAgent(Agents* mAgent)
{
	mName->Text = msclr::interop::marshal_as<String^>(mAgent->GetName());
	mX->Text = mAgent->GetPosition().x.ToString();
	mY->Text = mAgent->GetPosition().y.ToString();
	mStamina->Text = mAgent->GetStamina().ToString();
}

void StatWindow::SetButtons(Label^ Name, Label^ X, Label^ Y,Label ^ Stamina)
{
	mName = Name;
	mX = X;
	mY = Y;
	mStamina = Stamina;
}


StatWindow::StatWindow()
{
}
