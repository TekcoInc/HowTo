#include "MyForm.h"

namespace Project1 {

	MyForm::MyForm()
	{
		InitializeComponent();
	}

	MyForm::~MyForm()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void MyForm::radButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		++counter;
		auto msg = L"Clicked " + counter;
		
		daMsg->ContentText = msg;

		daMsg->Show();
	}
}