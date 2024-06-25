#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <mysql.h>
#include "Connect.h"
#pragma comment(lib,"libmysql.lib")
using namespace cv;
//using namespace std;

namespace OpenCVTeamProjectWinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		SQL_Query* sql;

		MyForm(void)
		{
			InitializeComponent();
			sql = new SQL_Query();
		}


	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 688);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(370, 163);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(577, 688);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(221, 156);
			this->button2->TabIndex = 1;
			this->button2->Text = L"sql 테스트";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(492, 264);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"-";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(312, 360);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(395, 203);
			this->button3->TabIndex = 3;
			this->button3->Text = L"DB 끊기";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1130, 881);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
			Mat img_color;

			VideoCapture cap(0);

			if (!cap.isOpened())
			{
				std::cout << "카메라를 열 수 없습니다." << std::endl;
				return;
			}

			while (1)
			{
				bool ret = cap.read(img_color);

				if (!ret)
				{
					std::cout << "캡처 실패" << std::endl;
					break;
				}

				Mat img_gray;
				cvtColor(img_color, img_gray, COLOR_BGR2GRAY);

				Mat img_binary;
				adaptiveThreshold(img_gray, img_binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY_INV, 7, 5);

				//이진화 결과를 개선하기 위해 모폴로지 닫기 연산을 해줌(팽창 후 침식)
				Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(3, 3));
				//morphologyEx(img_binary, img_binary, MORPH_CLOSE, kernel, Point(-1,-1), 2);

				//x,y 좌표 데이터 셋트를 한 요소로 컨투어 표현하는 점들의 집합(어레이)선언
				std::vector<std::vector<cv::Point>> contours;

				//컨투어를 검출, 컨투어의 일부 구간이 직선인 경우 시작 좌표와 끝 좌표만 저장
				findContours(img_binary, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);


				//한번에 모든 컨투어를 그릴 수도 있음
				drawContours(img_color, contours, -1, Scalar(0, 255, 0), 3);

				imshow("binary", img_binary);
				imshow("result", img_color);

				int key = waitKey(1);
				if (key == 27)
					break;
			}
			cap.release();
			destroyAllWindows();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//MYSQL Conn;	//MySQL 정보를 담을 구조체
		//MYSQL* ConnPtr = NULL;	//MySQL 핸들
		//MYSQL_RES* Result;		//쿼리 성공시 결과를 담는 구조체포인터
		//MYSQL_ROW Row;			//쿼리 성공시 결과로 나온 행의 정보를 담는 구조체
		//int Stat;				//쿼리 요청 후 결과(성공, 실패)
		//mysql_init(&Conn);
		//ConnPtr = mysql_real_connect(&Conn, "localhost", "root", "0000", "opencv", 3306, (char*)NULL, 0);

		//if (ConnPtr == NULL)
		//{
		//	cout << "DB 연결 오류" << endl;
		//	mysql_close(ConnPtr);
		//	return;
		//}

		//const char* Query = "SELECT * FROM user";
		//Stat = mysql_query(ConnPtr, Query);

		//if (Stat != 0)
		//{
		//	
		//	cout << "쿼리 에러 : " << mysql_error(&Conn) << endl;
		//	mysql_close(ConnPtr);
		//	return;
		//}

		//Result = mysql_store_result(ConnPtr);
		//while ((Row = mysql_fetch_row(Result)) != NULL)
		//{
		//	std::string s;
		//	s.append("NO : ").append(Row[0]).append(", ID : ").append(Row[1]);
		//	label1->Text = gcnew System::String(s.c_str()); //표준 문자열을 System::String으로 변환
		//	
		//	//원본 : 링커 -> 시스템 하위 시스템 = 윈도우
		//	//수정 : 하위시스템 = 콘솔
		//	cout << "테스트" << endl;
		//	Console::WriteLine("테스트2");
		//}
		//mysql_free_result(Result);	//결과 비우기

		//mysql_close(ConnPtr);

		std::string s = sql->TestQuery();
		label1->Text = gcnew System::String(s.c_str());
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		delete sql;
	}
};
}
