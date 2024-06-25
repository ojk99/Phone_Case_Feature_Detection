#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include <bcrypt.h>
#include "Connect.h"
#include "SignUp.h"
#include "hash.h"
#include "UserMenu.h"
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
	using namespace System::Text::RegularExpressions;//Ư�� ���ڸ� ã������ ���

	/// <summary>
	/// login�� ���� ����Դϴ�.
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
	public:
		//�̰��� ���� ����� ���� �߻�
		//�����̳� �Ʒ��ʿ� �����Ͻÿ�
		login(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			sql = new SQL_Query();
			txtList = gcnew array<TextBox^>(2);
			txtList[0] = tb_ID;
			txtList[1] = tb_PW;

			ID = tb_ID;
			PW = tb_PW;
			for (int i = 0; i < txtList->Length; i++)
			{
				txtList[i]->ForeColor = Color::DarkGray;
				if (txtList[i] == tb_ID)
					txtList[i]->Text = IdPlaceholder;
				else if (txtList[i] == tb_PW)
					txtList[i]->Text == PwPlaceholder;
					

				txtList[i]->GotFocus += gcnew EventHandler(&RemovePlaceholder);
				txtList[i]->LostFocus += gcnew EventHandler(&SetPlaceholder);
			}
			
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tb_ID;
	private: System::Windows::Forms::TextBox^ tb_PW;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ bt_Signup;
	private: System::Windows::Forms::Button^ bt_Login;










	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tb_ID = (gcnew System::Windows::Forms::TextBox());
			this->tb_PW = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bt_Signup = (gcnew System::Windows::Forms::Button());
			this->bt_Login = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tb_ID
			// 
			this->tb_ID->BackColor = System::Drawing::SystemColors::Window;
			this->tb_ID->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tb_ID->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->tb_ID->Location = System::Drawing::Point(240, 424);
			this->tb_ID->Margin = System::Windows::Forms::Padding(4);
			this->tb_ID->MaxLength = 20;
			this->tb_ID->Name = L"tb_ID";
			this->tb_ID->Size = System::Drawing::Size(404, 44);
			this->tb_ID->TabIndex = 2;
			this->tb_ID->Text = L"���̵�";
			// 
			// tb_PW
			// 
			this->tb_PW->BackColor = System::Drawing::SystemColors::Window;
			this->tb_PW->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->tb_PW->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->tb_PW->Location = System::Drawing::Point(240, 484);
			this->tb_PW->Margin = System::Windows::Forms::Padding(4);
			this->tb_PW->MaxLength = 20;
			this->tb_PW->Name = L"tb_PW";
			this->tb_PW->Size = System::Drawing::Size(404, 44);
			this->tb_PW->TabIndex = 3;
			this->tb_PW->Text = L"��й�ȣ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(333, 167);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(212, 77);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Log In";
			// 
			// bt_Signup
			// 
			this->bt_Signup->Location = System::Drawing::Point(459, 579);
			this->bt_Signup->Margin = System::Windows::Forms::Padding(4);
			this->bt_Signup->Name = L"bt_Signup";
			this->bt_Signup->Size = System::Drawing::Size(191, 60);
			this->bt_Signup->TabIndex = 1;
			this->bt_Signup->Text = L"Sign Up";
			this->bt_Signup->UseVisualStyleBackColor = true;
			this->bt_Signup->Click += gcnew System::EventHandler(this, &login::bt_Signup_Click);
			// 
			// bt_Login
			// 
			this->bt_Login->Font = (gcnew System::Drawing::Font(L"����", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->bt_Login->Location = System::Drawing::Point(240, 579);
			this->bt_Login->Margin = System::Windows::Forms::Padding(4);
			this->bt_Login->Name = L"bt_Login";
			this->bt_Login->Size = System::Drawing::Size(191, 60);
			this->bt_Login->TabIndex = 0;
			this->bt_Login->Text = L"Log In";
			this->bt_Login->UseVisualStyleBackColor = true;
			this->bt_Login->Click += gcnew System::EventHandler(this, &login::bt_Login_Click);
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(900, 683);
			this->Controls->Add(this->bt_Login);
			this->Controls->Add(this->bt_Signup);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tb_PW);
			this->Controls->Add(this->tb_ID);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &login::login_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		array<TextBox^>^ txtList;
		static System::String^ IdPlaceholder = "���̵�";
		static System::String^ PwPlaceholder = "��й�ȣ";
		static TextBox^ ID;
		static TextBox^ PW;
		SQL_Query* sql = NULL;

	private: static void RemovePlaceholder(Object^ sender, EventArgs^ e)
	{
		TextBox^ txt = (TextBox^)sender;
		if (txt->Text == IdPlaceholder || txt->Text == PwPlaceholder)
		{
			txt->ForeColor = Color::Black;
			txt->Text = System::String::Empty;
			if (txt == PW)
			{
				PW->PasswordChar = L'\u25CF';
			}
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
			}
		}
	
	private: System::Void bt_Signup_Click(System::Object^ sender, System::EventArgs^ e) {
		SignUp^ su = gcnew SignUp();
		su->ShowDialog();
	}

	private: System::Void bt_Login_Click(System::Object^ sender, System::EventArgs^ e) {
		std::vector<std::vector<MYSQL_ROW>> v = sql->UserList();
		MYSQL_ROW mr;
		int size = v.size();
		for (int i = -1; i < size; i++)
		{
			if (i == -1)
				i++;

			std::string s;	//sql���� �����鼭 ���̵� ���� ����
			std::string s2; //sql���� �����鼭 ��й�ȣ ���� ����

			if (size == 0)
			{
				System::Windows::Forms::MessageBox::Show("���̵� �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�");
				return;
			}
			else
			{
				mr = v.at(i).at(i);
				s.append(mr[1]);
				s2.append(mr[2]);
			}

			if (tb_ID->Text->Equals(IdPlaceholder) || System::String::IsNullOrWhiteSpace(tb_ID->Text))
			{
				System::Windows::Forms::MessageBox::Show("���̵� �Է��� �ּ���");
				return;
			}
			else if (tb_PW->Text->Equals(PwPlaceholder) || System::String::IsNullOrWhiteSpace(tb_PW->Text))
			{
				System::Windows::Forms::MessageBox::Show("��й�ȣ�� �Է��� �ּ���");
				return;
			}

			if (tb_ID->Text->Equals(gcnew System::String(s.c_str())))
			{
				std::string password = msclr::interop::marshal_as<std::string>(tb_PW->Text);
				password = hashToString(password);
				if (password == s2)
				{
					System::Windows::Forms::MessageBox::Show("�α��� ����");
					int userNum = std::atoi(mr[0]);
					
					UserMenu^ um = gcnew UserMenu(userNum);
					this->Hide();
					um->ShowDialog();
					this->Close();
					return;
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("���̵� �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�");
					return;
				}

			}
		}
		System::Windows::Forms::MessageBox::Show("���̵� �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�");
		return;
	}
	private: System::Void login_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		delete sql;
	}
};
}
