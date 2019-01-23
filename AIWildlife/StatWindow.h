#ifndef STATWINDOW_H
#define STATWINDOW_H
#include "Agents.h"
#include <vector>
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::Windows::Forms;
public ref class StatWindow
{
public:
	static StatWindow  ^ Initialize();
	void SetAgent(Agents * mAgent);
	void SetButtons(Label ^ Name, Label ^ X, Label ^ Y,Label ^ Stamina);
	

private:
	static StatWindow ^ mInstance;
	StatWindow();
	GroupBox ^ mBox;
	Label ^ mName;
	Label ^ mX;
	Label ^ mY;
	Label ^ mStamina;

	

	
};
#endif


