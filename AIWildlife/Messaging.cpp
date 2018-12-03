#include "Messaging.h"



Messaging ^ Messaging::Initialize()
{
	if(mInstance == nullptr)
	{
		mInstance = gcnew Messaging();
	}
	return mInstance;
}

void Messaging::SendMessage(std::string message)
{
	String^ test = msclr::interop::marshal_as<String^>(message);
	mTextbox->Text += test + "\n";
}

Messaging::Messaging()
{
}


Messaging::~Messaging()
{
}
