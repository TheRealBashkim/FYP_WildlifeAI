#ifndef MESSAGING_H
#define MESSAGING_H
#include <string>
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::Windows::Forms;
public ref class Messaging
{
public:
	static Messaging ^ Initialize();
	void SendMessage(std::string message);
	void SetMessageBox(RichTextBox ^ TextBox) { mTextbox = TextBox; }
private:
	static Messaging ^ mInstance;
	RichTextBox ^ mTextbox;
	Messaging();
	~Messaging();
};
#endif