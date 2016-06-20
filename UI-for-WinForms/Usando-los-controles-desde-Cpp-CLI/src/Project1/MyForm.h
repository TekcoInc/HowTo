#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public Telerik::WinControls::UI::RadForm
	{

	private:
		System::ComponentModel::Container ^components;
		Telerik::WinControls::UI::RadButton^ btnClickMe;
		Telerik::WinControls::UI::RadDesktopAlert^ daMsg;
		int counter = 0;

	public:
		MyForm(void);
		~MyForm();

        #pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnClickMe = (gcnew Telerik::WinControls::UI::RadButton());
			this->daMsg = (gcnew Telerik::WinControls::UI::RadDesktopAlert());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnClickMe))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this))->BeginInit();

			this->SuspendLayout();
			// 
			// btnClickMe
			// 
			this->btnClickMe->Location = System::Drawing::Point(12, 12);
			this->btnClickMe->Name = L"btnClickMe";
			this->btnClickMe->Size = System::Drawing::Size(110, 24);
			this->btnClickMe->TabIndex = 0;
			this->btnClickMe->Text = L"Click Me!";
			this->btnClickMe->Click += gcnew System::EventHandler(this, &MyForm::radButton1_Click);
			// 
			// daMsg
			// 
			this->daMsg->CaptionText = L"New notification";
			this->daMsg->ContentText = L"";
			this->daMsg->AutoClose = true;
			this->daMsg->AutoCloseDelay = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 270);
			this->Controls->Add(this->btnClickMe);
			this->Name = L"MyForm";
			this->Text = L"Mi Formulario Telerik";
			// 
			// 
			// 
			this->RootElement->ApplyShapeToControl = true;	

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnClickMe))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this))->EndInit();

			this->ResumeLayout(false);
			this->PerformLayout();
		}
		#pragma endregion

		System::Void radButton1_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
