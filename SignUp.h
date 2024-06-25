#pragma once
#include "login.h"
#include <iostream>
#include <mysql.h>
#include <string>
#include <bcrypt.h>
#include "hash.h"
#include "Connect.h"
#include <msclr/marshal_cppstd.h>
#pragma comment(lib,"bcrypt.lib")
#pragma comment(lib,"libmysql.lib")

//using namespace cv;

namespace OpenCVTeamProjectWinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;//특수 문자를 찾기위해 사용

	/// <summary>
	/// SignUp에 대한 요약입니다.
	/// </summary>
	public ref class SignUp : public System::Windows::Forms::Form
	{
	public:
		SignUp(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			sql = new SQL_Query();
			txtList = gcnew array<TextBox^>(3);
			txtList[0] = tb_ID;
			txtList[1] = tb_PW;
			txtList[2] = tb_PWC;

			ID = tb_ID;
			PW = tb_PW;
			PWC = tb_PWC;
			for (int i = 0; i < txtList->Length; i++)
			{
				txtList[i]->ForeColor = Color::DarkGray;
				if (txtList[i] == tb_ID)
					txtList[i]->Text = IdPlaceholder;
				else if (txtList[i] == tb_PW)
					txtList[i]->Text == PwPlaceholder;
				else if (txtList[i] == tb_PWC)
					txtList[i]->Text == PwPlaceholder2;

				txtList[i]->GotFocus += gcnew EventHandler(&RemovePlaceholder);
				txtList[i]->LostFocus += gcnew EventHandler(&SetPlaceholder);
			}
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tb_PW;
	private: System::Windows::Forms::TextBox^ tb_ID;
	private: System::Windows::Forms::TextBox^ tb_PWC;
	private: System::Windows::Forms::Button^ bt_Signup;

	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb_PW = (gcnew System::Windows::Forms::TextBox());
			this->tb_ID = (gcnew System::Windows::Forms::TextBox());
			this->tb_PWC = (gcnew System::Windows::Forms::TextBox());
			this->bt_Signup = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(333, 167);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(257, 77);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Sign Up";
			// 
			// tb_PW
			// 
			this->tb_PW->BackColor = System::Drawing::SystemColors::Window;
			this->tb_PW->Font = (gcnew System::Drawing::Font(L"돋움", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tb_PW->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->tb_PW->Location = System::Drawing::Point(240, 479);
			this->tb_PW->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_PW->MaxLength = 20;
			this->tb_PW->Name = L"tb_PW";
			this->tb_PW->Size = System::Drawing::Size(404, 44);
			this->tb_PW->TabIndex = 2;
			this->tb_PW->Text = L"비밀번호";
			// 
			// tb_ID
			// 
			this->tb_ID->BackColor = System::Drawing::SystemColors::Window;
			this->tb_ID->Font = (gcnew System::Drawing::Font(L"돋움", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tb_ID->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->tb_ID->Location = System::Drawing::Point(240, 424);
			this->tb_ID->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_ID->MaxLength = 20;
			this->tb_ID->Name = L"tb_ID";
			this->tb_ID->Size = System::Drawing::Size(404, 44);
			this->tb_ID->TabIndex = 1;
			this->tb_ID->Text = L"아이디";
			// 
			// tb_PWC
			// 
			this->tb_PWC->BackColor = System::Drawing::SystemColors::Window;
			this->tb_PWC->Font = (gcnew System::Drawing::Font(L"돋움", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tb_PWC->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->tb_PWC->Location = System::Drawing::Point(240, 533);
			this->tb_PWC->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_PWC->MaxLength = 20;
			this->tb_PWC->Name = L"tb_PWC";
			this->tb_PWC->Size = System::Drawing::Size(404, 44);
			this->tb_PWC->TabIndex = 3;
			this->tb_PWC->Text = L"비밀번호 확인";
			// 
			// bt_Signup
			// 
			this->bt_Signup->Location = System::Drawing::Point(346, 613);
			this->bt_Signup->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->bt_Signup->Name = L"bt_Signup";
			this->bt_Signup->Size = System::Drawing::Size(191, 60);
			this->bt_Signup->TabIndex = 0;
			this->bt_Signup->Text = L"Sign Up";
			this->bt_Signup->UseVisualStyleBackColor = true;
			this->bt_Signup->Click += gcnew System::EventHandler(this, &SignUp::bt_Signup_Click);
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(905, 709);
			this->Controls->Add(this->bt_Signup);
			this->Controls->Add(this->tb_PWC);
			this->Controls->Add(this->tb_PW);
			this->Controls->Add(this->tb_ID);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			this->Name = L"SignUp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ㅇ";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SignUp::SignUp_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		array<TextBox^>^ txtList;
		static System::String^ IdPlaceholder = "아이디";
		static System::String^ PwPlaceholder = "비밀번호";
		static System::String^ PwPlaceholder2 = "비밀번호 확인";
		static TextBox^ ID;
		static TextBox^ PW;
		static TextBox^ PWC;
		SQL_Query* sql = NULL;

	private:
		static void RemovePlaceholder(Object^ sender, EventArgs^ e)
		{
			TextBox^ txt = (TextBox^)sender;
			if (txt->Text == IdPlaceholder || txt->Text == PwPlaceholder || txt->Text == PwPlaceholder2)
			{
				txt->ForeColor = Color::Black;
				txt->Text = System::String::Empty;
				if (txt == PW)
					PW->PasswordChar = L'\u25CF';
				else if (txt == PWC)
					PWC->PasswordChar = L'\u25CF';
			}
		}

	private:
		static void SetPlaceholder(Object^ sender, EventArgs^ e)
		{
			TextBox^ txt = (TextBox^)sender;
			if (System::String::IsNullOrWhiteSpace(txt->Text))
			{
				txt->ForeColor = Color::DarkGray;
				if (txt == ID)
					txt->Text = IdPlaceholder;
				else if (txt == PW)
				{
					txt->Text = PwPlaceholder;
					PW->PasswordChar = '\0';
				}
				else if (txt == PWC)
				{
					txt->Text = PwPlaceholder2;
					PWC->PasswordChar = '\0';
				}
			}
		}
	private: System::Void bt_Signup_Click(System::Object^ sender, System::EventArgs^ e) {
		std::vector<std::vector<MYSQL_ROW>> v = sql->UserList();
		MYSQL_ROW mr;
		int size = v.size();
		for (int i = -1; i < size; i++)
		{
			if (i == -1)
				i++;

			std::string s;	//sql행을 읽으면서 아이디 값을 저장

			if (size == 0)
			{
				s.append("");
			}
			else
			{
				mr = v.at(i).at(i);
				s.append(mr[1]);
			}

			if (tb_ID->Text->Equals(IdPlaceholder) || System::String::IsNullOrWhiteSpace(tb_ID->Text))
			{
				System::Windows::Forms::MessageBox::Show("아이디를 입력해 주세요");
				return;
			}
			else if (tb_PW->Text->Equals(PwPlaceholder) || System::String::IsNullOrWhiteSpace(tb_PW->Text))
			{
				System::Windows::Forms::MessageBox::Show("비밀번호를 입력해 주세요");
				return;
			}
			else if (tb_PWC->Text->Equals(PwPlaceholder2) || System::String::IsNullOrWhiteSpace(tb_PWC->Text))
			{
				System::Windows::Forms::MessageBox::Show("비밀번호 확인을 입력해 주세요");
				return;
			}

			System::String^ urlCheck = Regex::Replace(tb_ID->Text, L"[^a-zA-z0-9]", L"", RegexOptions::Singleline);
			System::String^ urlCheck2 = Regex::Replace(tb_ID->Text, L"[^a-zA-z]", L"", RegexOptions::Singleline);
			System::String^ urlCheck3 = Regex::Replace(tb_ID->Text, L"[^0-9]", L"", RegexOptions::Singleline);

			if (tb_ID->Text->Length < 6 || tb_ID->Text->Length > 20)
			{
				System::Windows::Forms::MessageBox::Show("아이디는 6~20자 사이로 설정 하세요");
				return;
			}
			else if (tb_ID->Text->Equals(urlCheck) == false)
			{
				System::Windows::Forms::MessageBox::Show("아이디는 소문자, 대문자, 숫자를 조합하여 사용 하세요");
				return;
			}
			else if (!(tb_ID->Text->Equals(urlCheck2) == false && tb_ID->Text->Equals(urlCheck3) == false))
			{
				System::Windows::Forms::MessageBox::Show("영문자와 숫자가 포함 되어야 합니다");
				return;
			}
			else if (tb_ID->Text->Equals(gcnew System::String(s.c_str())))
			{
				System::Windows::Forms::MessageBox::Show("이미 존재하는 아이디 입니다");
				return;
			}

			System::String^ urlCheck4 = Regex::Replace(tb_PW->Text, L"[^a-zA-z0-9]", L"", RegexOptions::Singleline);
			System::String^ urlCheck5 = Regex::Replace(tb_PW->Text, L"[^a-zA-z]", L"", RegexOptions::Singleline);
			System::String^ urlCheck6 = Regex::Replace(tb_PW->Text, L"[^0-9]", L"", RegexOptions::Singleline);

			if (tb_PW->Text->Length < 8 || tb_PW->Text->Length > 20)
			{
				System::Windows::Forms::MessageBox::Show("비밀번호는 8자 이상 20자 이하로 설정 하세요");
				return;
			}
			else if (tb_PW->Text->Equals(urlCheck4) == false)
			{
				System::Windows::Forms::MessageBox::Show(tb_PW->Text);
				System::Windows::Forms::MessageBox::Show("비밀번호는 영문자, 숫자를 조합하여 사용하세요");
				return;
			}
			else if (!(tb_PW->Text->Equals(urlCheck5) == false && tb_PW->Text->Equals(urlCheck6) == false))
			{
				System::Windows::Forms::MessageBox::Show("비밀번호는 영문자와 숫자가 포함 되어야 합니다");
				return;
			}
			else if (!tb_PW->Text->Equals(tb_PWC->Text))
			{
				System::Windows::Forms::MessageBox::Show("비밀번호가 같지 않습니다");
				return;
			}
		}
		std::string id = msclr::interop::marshal_as<std::string>(tb_ID->Text);
		std::string password = msclr::interop::marshal_as<std::string>(tb_PW->Text);
		password = hashToString(password);

		if (password == "")
		{
			std::cout << "오류" << std::endl;
			return;
		}
		sql->InsertUser(id,password);

		System::Windows::Forms::MessageBox::Show("회원가입 완료");

		this->Hide();
		this->Close();
	}
private: System::Void SignUp_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	delete sql;
}
};
}
