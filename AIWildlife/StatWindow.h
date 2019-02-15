#ifndef STATWINDOW_H
#define STATWINDOW_H
#include <vector>
#include <msclr\marshal_cppstd.h>
#include "BaseAgent.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Globalization;
public ref class StatWindow
{
public:
	static StatWindow  ^ Initialize();
	void SetAgent(BaseAgent * Agent);
	void SetButtons(Label ^ Name, Label ^ X, Label ^ Y,Label ^ Stamina,Label ^ mHealth, Label ^ Age);
	

private:
	static StatWindow ^ mInstance;
	StatWindow();
	GroupBox ^ mBox;
	Label ^ mName;
	Label ^ mX;
	Label ^ mY;
	Label ^ mStamina;
	Label ^ mHealth;
	Label ^ mAge;

	

	
};
#endif


