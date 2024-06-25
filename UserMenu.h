#pragma once
#include <tchar.h>
#include <opencv2/opencv.hpp>
#include <mysql.h>
#include "Connect.h"
#include "InputBox.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>
#pragma comment(lib,"libmysql.lib")

using namespace cv;

namespace OpenCVTeamProjectWinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// UserMenu에 대한 요약입니다.
	/// </summary>
	public ref class UserMenu : public System::Windows::Forms::Form
	{
	public:
		UserMenu(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		UserMenu(int userNum)
		{
			InitializeComponent();
			this->userNum = userNum;
			sql = new SQL_Query();
            certify = false;
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~UserMenu()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Timer^ timer1;
    private: System::Windows::Forms::Timer^ timer_lensScan;
    private: System::Windows::Forms::Button^ bt_certify;

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ lb_circle;

    private: System::Windows::Forms::GroupBox^ groupBox1;
    private: System::Windows::Forms::Button^ bt_ReRagist;
    private: System::Windows::Forms::Button^ bt_Search;



    private: System::Windows::Forms::Timer^ timer_search;
    private: System::Windows::Forms::PictureBox^ pb;




    protected:
    private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
            this->components = (gcnew System::ComponentModel::Container());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer_lensScan = (gcnew System::Windows::Forms::Timer(this->components));
            this->bt_certify = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->lb_circle = (gcnew System::Windows::Forms::Label());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->bt_ReRagist = (gcnew System::Windows::Forms::Button());
            this->bt_Search = (gcnew System::Windows::Forms::Button());
            this->timer_search = (gcnew System::Windows::Forms::Timer(this->components));
            this->pb = (gcnew System::Windows::Forms::PictureBox());
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb))->BeginInit();
            this->SuspendLayout();
            // 
            // timer1
            // 
            this->timer1->Interval = 1000;
            this->timer1->Tick += gcnew System::EventHandler(this, &UserMenu::timer1_Tick);
            // 
            // timer_lensScan
            // 
            this->timer_lensScan->Interval = 1000;
            this->timer_lensScan->Tick += gcnew System::EventHandler(this, &UserMenu::timer_lensScan_Tick);
            // 
            // bt_certify
            // 
            this->bt_certify->Font = (gcnew System::Drawing::Font(L"굴림", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(129)));
            this->bt_certify->Location = System::Drawing::Point(610, 27);
            this->bt_certify->Name = L"bt_certify";
            this->bt_certify->Size = System::Drawing::Size(218, 83);
            this->bt_certify->TabIndex = 0;
            this->bt_certify->Text = L"인증";
            this->bt_certify->UseVisualStyleBackColor = true;
            this->bt_certify->Click += gcnew System::EventHandler(this, &UserMenu::bt_certify_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"굴림", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(129)));
            this->label1->Location = System::Drawing::Point(6, 31);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(228, 48);
            this->label1->TabIndex = 1;
            this->label1->Text = L"인증 상태";
            // 
            // lb_circle
            // 
            this->lb_circle->AutoSize = true;
            this->lb_circle->Font = (gcnew System::Drawing::Font(L"굴림", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(129)));
            this->lb_circle->ForeColor = System::Drawing::Color::Red;
            this->lb_circle->Location = System::Drawing::Point(236, 31);
            this->lb_circle->Name = L"lb_circle";
            this->lb_circle->Size = System::Drawing::Size(68, 48);
            this->lb_circle->TabIndex = 1;
            this->lb_circle->Text = L"●";
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->label1);
            this->groupBox1->Controls->Add(this->lb_circle);
            this->groupBox1->Location = System::Drawing::Point(12, 12);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(325, 98);
            this->groupBox1->TabIndex = 2;
            this->groupBox1->TabStop = false;
            // 
            // bt_ReRagist
            // 
            this->bt_ReRagist->Font = (gcnew System::Drawing::Font(L"굴림", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(129)));
            this->bt_ReRagist->Location = System::Drawing::Point(31, 148);
            this->bt_ReRagist->Name = L"bt_ReRagist";
            this->bt_ReRagist->Size = System::Drawing::Size(306, 137);
            this->bt_ReRagist->TabIndex = 3;
            this->bt_ReRagist->Text = L"재등록";
            this->bt_ReRagist->UseVisualStyleBackColor = true;
            this->bt_ReRagist->Click += gcnew System::EventHandler(this, &UserMenu::bt_ReRagist_Click);
            // 
            // bt_Search
            // 
            this->bt_Search->Font = (gcnew System::Drawing::Font(L"굴림", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(129)));
            this->bt_Search->Location = System::Drawing::Point(522, 148);
            this->bt_Search->Name = L"bt_Search";
            this->bt_Search->Size = System::Drawing::Size(306, 137);
            this->bt_Search->TabIndex = 3;
            this->bt_Search->Text = L"탐색";
            this->bt_Search->UseVisualStyleBackColor = true;
            this->bt_Search->Click += gcnew System::EventHandler(this, &UserMenu::bt_Search_Click);
            // 
            // timer_search
            // 
            this->timer_search->Interval = 10;
            this->timer_search->Tick += gcnew System::EventHandler(this, &UserMenu::timer_search_Tick);
            // 
            // pb
            // 
            this->pb->Location = System::Drawing::Point(-3, 440);
            this->pb->Name = L"pb";
            this->pb->Size = System::Drawing::Size(876, 352);
            this->pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pb->TabIndex = 4;
            this->pb->TabStop = false;
            // 
            // UserMenu
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(873, 789);
            this->Controls->Add(this->pb);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->bt_Search);
            this->Controls->Add(this->bt_ReRagist);
            this->Controls->Add(this->bt_certify);
            this->Name = L"UserMenu";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"UserMenu";
            this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &UserMenu::UserMenu_FormClosed);
            this->Shown += gcnew System::EventHandler(this, &UserMenu::UserMenu_Shown);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

	private:
        const int CAMNUM = 0;

		int userNum;
		SQL_Query* sql = NULL;

        uint h;
        uint s;
        uint v;
        int width;
        int height;
        int maxIndex;
        int compareNum;
        int checkWidth;
        int checkHeight;
        bool checkTime;
        bool breakDetection;
        array<array<int>^>^ checkNum; //  h = checkNum[0], width = checkNum[1], height = checkNum[2]

        //lens search
        int searchTime;
        size_t maxCount;
        size_t circlesSize;
        bool checkLensTime;
        
        //인증 변수
        bool certify;

        //탑색 변수
        System::String^ searchURL;
        int selectNum;

		
	public:
        //탐색 없이 신규 등록
		void phoneRagistration()
		{
            VideoCapture cap(CAMNUM);
            if (!cap.isOpened())
            {
                std::cout << "카메라 에러" << std::endl;
                return;
            }

            //사용할 변수 초기화
            compareNum = 0;
            checkWidth = 0;
            checkHeight = 0;
            checkTime = false;
            breakDetection = false;
            this->maxIndex = -1;
            this->h = 0;
            this->s = 0;
            this->v = 0;
            this->width = 0;
            this->height = 0;


            checkNum = gcnew array<array<int>^>(3); // 3x3 행렬로 가정
            for (int i = 0; i < 3; i++)
            {
                checkNum[i] = gcnew array<int>(3); // 각 행에 3개의 열 생성
                for (int j = 0; j < 3; j++)
                {
                    checkNum[i][j] = 0; // 예시로 배열을 0으로 초기화
                }
            }

            timer1->Start();
            Rect boundingBox;
            while (1)
            {
                Mat img_frame;

                bool ret = cap.read(img_frame);

                if (!ret)
                {
                    std::cout << "캡처 에러" << std::endl;
                    break;
                }
                if (img_frame.empty())
                {
                    std::cout << "이미지 에러" << std::endl;
                    return;
                }

                Mat img_gray;
                cvtColor(img_frame, img_gray, COLOR_BGR2GRAY);

                Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(5, 5));

                Mat img_dilate;
                dilate(img_gray, img_dilate, kernel, cv::Point(-1, -1), 1);

                Mat img_erode;
                erode(img_dilate, img_erode, kernel, cv::Point(-1, -1), 1);

                Mat img_blur;
                GaussianBlur(img_erode, img_blur, cv::Size(3, 3), 0);

                Mat img_binary;
                adaptiveThreshold(img_blur, img_binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);

                //하스토그램 평탄화
                Mat img_contrast;
                equalizeHist(img_binary, img_contrast);

                Mat img_processed;
                subtract(255, img_contrast, img_processed);

                Mat img_close;
                morphologyEx(img_processed, img_close, MORPH_CLOSE, kernel);

                // 컨투어 찾기
                // 컨투어 사용을 위해서는 이진화 이미지를 사용해야 한다.
                std::vector<std::vector<cv::Point>> contours;
                findContours(img_close, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

                // 컨투어 중 가장 큰 것 선택

                double maxArea = 0; // 최대 영역 초기화
                int maxIndex = -1; // 최대 영역의 인덱스 초기화 
                //-1로 초기화하는 것은 배열에 들어갈 값인데
                //0으로 할 경우 0번째 인덱스로 들어갈 수 있기 때문
                //0으로 해도 무방함

                //모든 컨투어 검출에 대한 반복을 위함
                for (int i = 0; i < contours.size(); i++)
                {
                    //contourArea는 윤곽선의 면적을 계산하는 함수
                    double area = contourArea(contours[i]); //컨투어 영역 계산

                    if (area > maxArea) // 최대 영역보다 크면
                    {
                        //최대 영역 갱신 후 인덱스에 저장 
                        maxArea = area;
                        maxIndex = i;
                    }
                }

                this->maxIndex = maxIndex;
                // 경계 상자 그리기
                if (maxIndex >= 0) // maxIndex가 검출 된 경우
                {
                    //boundingRect은 컨투어 주위에 그릴 수 있는 최소 사각형 계산
                    boundingBox = boundingRect(contours[maxIndex]);

                    // 경계 상자의 가로, 세로 크기
                    int width = boundingBox.width;
                    int height = boundingBox.height;
                    checkWidth = width;
                    checkHeight = height;
                    if ((width >= 100 && height >= 100) && (width <= 600 && height <= 600))
                    {
                        // 화면에 표시
                        rectangle(img_frame, boundingBox, Scalar(0, 0, 255), 1);
                        std::string sizeText = "Width: " + std::to_string(width) + "  Height: " + std::to_string(height);
                        putText(img_frame, sizeText, cv::Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);

                        // 색 검출
                        Mat img_roi = img_frame(boundingBox);

                        Mat img_hsv;
                        cvtColor(img_roi, img_hsv, COLOR_BGR2HSV);

                        Mat img_out;
                        img_frame.copyTo(img_out);


                        uchar* pointer_row = img_hsv.ptr<uchar>(img_hsv.rows / 2);

                        //
                        uint h = pointer_row[(img_hsv.cols / 2) * 3 + 0];
                        uint s = pointer_row[(img_hsv.cols / 2) * 3 + 1];
                        uint v = pointer_row[(img_hsv.cols / 2) * 3 + 2];

                        this->h = h;
                        this->s = s;
                        this->v = v;
                        this->width = width;
                        this->height = height;
                    }
                    
                }

                // 프레임 화면에 표시
                imshow("Frame", img_frame);
                //imshow("Result", img_close);

                int key = waitKey(1);
                if (key == 27) //ESC를 누르면 종료
                {
                    timer1->Stop();
                    System::Windows::Forms::MessageBox::Show("등록을 종료 합니다.");

                    cap.release();
                    destroyAllWindows();
                    return;
                }

                if (breakDetection)
                {
                    sql->InsertPhone(checkNum[0][0], checkNum[0][1], checkNum[0][2], userNum);
                    sql->UpdateUserPhone(userNum);

                    std::string url = ".\\image\\";
                    url.append(sql->SelectPhoneNo(userNum));

                    std::wstring wurl(url.begin(), url.end());

                    if ((_waccess(wurl.c_str(), 0)) == -1)
                    {
                        CreateDirectory(wurl.c_str(), NULL);
                    }
                    url.append("\\WARPING_VIEW_1.jpg");
                    imwrite(url, img_frame(boundingBox));
                    break;
                }
            }

            timer_lensScan->Start();
            checkLensTime = false;
            maxCount = 0;
            searchTime = 0;
            Mat img_frame;

            while (true) {
                bool ret = cap.read(img_frame);
                if (!ret) {
                    std::cout << "캡처 실패" << std::endl;
                    break;
                }

                // 이미지 전처리
                Mat img_gray;
                cvtColor(img_frame, img_gray, COLOR_BGR2GRAY);

                Mat g;
                GaussianBlur(img_gray, g, cv::Size(3, 3), 1);


                std::vector<Vec3f> circles; //float타입 3채널 벡터 선언
                    
                HoughCircles(img_gray, circles, HOUGH_GRADIENT, 1, 20, 60, 45, 1, 30);
                for (size_t i = 0; i < circles.size(); i++)
                {
                    Vec3i c = circles[i]; //1열 3행 벡터 c
                    cv::Point center(c[0], c[1]);
                    int radius = c[2];
                    circle(img_frame, center, radius, Scalar(0, 255, 0), 2);
                    circle(img_frame, center, 2, Scalar(0, 0, 255), 3);
                }

                circlesSize = circles.size();
                   

                imshow("Frame", img_frame);
                waitKey(1);

                if (checkLensTime) {
                    break;
                }
            }

            InputBox^ ib = gcnew InputBox();
            ib->ShowDialog();
            System::String^ csString = ib->phoneName;
            std::string phoneName = msclr::interop::marshal_as<std::string>(csString);
            
            sql->UpdatePhoneName(phoneName, maxCount, userNum);

            cap.release();
            destroyAllWindows();

            System::Windows::Forms::MessageBox::Show("등록이 완료되었습니다");
		}

        //인증
        void userCertify()
        {
            VideoCapture cap(CAMNUM);
            if (!cap.isOpened())
            {
                std::cout << "카메라 에러" << std::endl;
                return;
            }

            MYSQL_ROW mr = sql->UserPhoneInfo(userNum);
            int phoneNo = std::atoi(mr[0]);
            int sqlH = std::atoi(mr[1]);
            int sqlWidth = std::atoi(mr[2]);
            int sqlHeight = std::atoi(mr[3]);
            bool firstCheck = false;

            std::string url = ".\\image\\";
            url.append(sql->SelectPhoneNo(userNum)).append("\\WARPING_VIEW_1.jpg");

            Rect boundingBox;
            while (1)
            {
                Mat img_frame;

                bool ret = cap.read(img_frame);

                if (!ret)
                {
                    std::cout << "캡처 에러" << std::endl;
                    break;
                }
                if (img_frame.empty())
                {
                    std::cout << "이미지 에러" << std::endl;
                    return;
                }

                Mat img_gray;
                cvtColor(img_frame, img_gray, COLOR_BGR2GRAY);

                Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(5, 5));

                Mat img_dilate;
                dilate(img_gray, img_dilate, kernel, cv::Point(-1, -1), 1);

                Mat img_erode;
                erode(img_dilate, img_erode, kernel, cv::Point(-1, -1), 1);

                Mat img_blur;
                GaussianBlur(img_erode, img_blur, cv::Size(3, 3), 0);

                Mat img_binary;
                adaptiveThreshold(img_blur, img_binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);

                //하스토그램 평탄화
                Mat img_contrast;
                equalizeHist(img_binary, img_contrast);

                Mat img_processed;
                subtract(255, img_contrast, img_processed);

                Mat img_close;
                morphologyEx(img_processed, img_close, MORPH_CLOSE, kernel);

                // 컨투어 찾기
                // 컨투어 사용을 위해서는 이진화 이미지를 사용해야 한다.
                std::vector<std::vector<cv::Point>> contours;
                findContours(img_close, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

                // 컨투어 중 가장 큰 것 선택

                double maxArea = 0; // 최대 영역 초기화
                int maxIndex = -1; // 최대 영역의 인덱스 초기화 
                //-1로 초기화하는 것은 배열에 들어갈 값인데
                //0으로 할 경우 0번째 인덱스로 들어갈 수 있기 때문
                //0으로 해도 무방함

                //모든 컨투어 검출에 대한 반복을 위함
                for (int i = 0; i < contours.size(); i++)
                {
                    //contourArea는 윤곽선의 면적을 계산하는 함수
                    double area = contourArea(contours[i]); //컨투어 영역 계산

                    if (area > maxArea) // 최대 영역보다 크면
                    {
                        //최대 영역 갱신 후 인덱스에 저장 
                        maxArea = area;
                        maxIndex = i;
                    }
                }

                // 경계 상자 그리기
                if (maxIndex >= 0) // maxIndex가 검출 된 경우
                {
                    //boundingRect은 컨투어 주위에 그릴 수 있는 최소 사각형 계산
                    boundingBox = boundingRect(contours[maxIndex]);

                    // 경계 상자의 가로, 세로 크기
                    int width = boundingBox.width;
                    int height = boundingBox.height;
                    checkWidth = width;
                    checkHeight = height;
                    if ((width >= 100 && height >= 100) && (width <= 600 && height <= 600))
                    {
                        // 화면에 표시
                        rectangle(img_frame, boundingBox, Scalar(0, 0, 255), 1);
                        std::string sizeText = "Width: " + std::to_string(width) + "  Height: " + std::to_string(height);
                        putText(img_frame, sizeText, cv::Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);

                        // 색 검출
                        Mat img_roi = img_frame(boundingBox);

                        Mat img_hsv;
                        cvtColor(img_roi, img_hsv, COLOR_BGR2HSV);

                        Mat img_out;
                        img_frame.copyTo(img_out);


                        uchar* pointer_row = img_hsv.ptr<uchar>(img_hsv.rows / 2);

                        
                        uint h = pointer_row[(img_hsv.cols / 2) * 3 + 0];
                        uint s = pointer_row[(img_hsv.cols / 2) * 3 + 1];
                        uint v = pointer_row[(img_hsv.cols / 2) * 3 + 2];

                        int checkH = sqlH - h;
                        int checkWidth = sqlWidth - width;
                        int checkHeight = sqlHeight - height;


                        if (((checkH >= -3 && checkH <= 3)) && ((checkWidth >= -5 && checkWidth <= 5)) &&
                            ((checkHeight >= -5 && checkHeight <= 5)))
                        {
                            Mat targetImage = img_frame(boundingBox);

                            Mat standardImage = imread(url, IMREAD_ANYCOLOR);

                            double final_score = compareFeature(targetImage, standardImage);

                            
                            std::cout << "Similarity (일치율) : " << final_score << " % " << std::endl;
                            
                            if(final_score >= 60)
                                firstCheck = true;
                        }
                    }

                }

                imshow("Frame", img_frame);

                int key = waitKey(1);
                if (key == 27) //ESC를 누르면 종료
                {
                    System::Windows::Forms::MessageBox::Show("인증 중단");
                    cap.release();
                    destroyAllWindows();
                    return;
                }

                if (firstCheck)
                    break;
            }

            cap.release();
            destroyAllWindows();

            certify = true;
            lb_circle->ForeColor = Color::LawnGreen;
        }


        ////////////////////////////////////////////////////
        //탐색
        void phoneSearch()
        {
            VideoCapture cap(CAMNUM);
            if (!cap.isOpened())
            {
                std::cout << "카메라 에러" << std::endl;
                return;
            }

            selectNum = 0;
            searchURL = "";

            timer_search->Start();
            Rect boundingBox;
            while (1)
            {
                Mat img_frame;

                bool ret = cap.read(img_frame);

                if (!ret)
                {
                    std::cout << "캡처 에러" << std::endl;
                    break;
                }
                if (img_frame.empty())
                {
                    std::cout << "이미지 에러" << std::endl;
                    return;
                }

                Mat img_gray;
                cvtColor(img_frame, img_gray, COLOR_BGR2GRAY);

                Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(5, 5));

                Mat img_dilate;
                dilate(img_gray, img_dilate, kernel, cv::Point(-1, -1), 1);

                Mat img_erode;
                erode(img_dilate, img_erode, kernel, cv::Point(-1, -1), 1);

                Mat img_blur;
                GaussianBlur(img_erode, img_blur, cv::Size(3, 3), 0);

                Mat img_binary;
                adaptiveThreshold(img_blur, img_binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);

                //하스토그램 평탄화
                Mat img_contrast;
                equalizeHist(img_binary, img_contrast);

                Mat img_processed;
                subtract(255, img_contrast, img_processed);

                Mat img_close;
                morphologyEx(img_processed, img_close, MORPH_CLOSE, kernel);

                // 컨투어 찾기
                // 컨투어 사용을 위해서는 이진화 이미지를 사용해야 한다.
                std::vector<std::vector<cv::Point>> contours;
                findContours(img_close, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

                // 컨투어 중 가장 큰 것 선택

                double maxArea = 0; // 최대 영역 초기화
                int maxIndex = -1; // 최대 영역의 인덱스 초기화 
                //-1로 초기화하는 것은 배열에 들어갈 값인데
                //0으로 할 경우 0번째 인덱스로 들어갈 수 있기 때문
                //0으로 해도 무방함

                //모든 컨투어 검출에 대한 반복을 위함
                for (int i = 0; i < contours.size(); i++)
                {
                    //contourArea는 윤곽선의 면적을 계산하는 함수
                    double area = contourArea(contours[i]); //컨투어 영역 계산

                    if (area > maxArea) // 최대 영역보다 크면
                    {
                        //최대 영역 갱신 후 인덱스에 저장 
                        maxArea = area;
                        maxIndex = i;
                    }
                }

                // 경계 상자 그리기
                if (maxIndex >= 0) // maxIndex가 검출 된 경우
                {
                    //boundingRect은 컨투어 주위에 그릴 수 있는 최소 사각형 계산
                    boundingBox = boundingRect(contours[maxIndex]);

                    // 경계 상자의 가로, 세로 크기
                    int width = boundingBox.width;
                    int height = boundingBox.height;
                    checkWidth = width;
                    checkHeight = height;
                    if ((width >= 100 && height >= 100) && (width <= 600 && height <= 600))
                    {
                        // 화면에 표시
                        rectangle(img_frame, boundingBox, Scalar(0, 0, 255), 1);
                        std::string sizeText = "Width: " + std::to_string(width) + "  Height: " + std::to_string(height);
                        putText(img_frame, sizeText, cv::Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);

                        // 색 검출
                        Mat img_roi = img_frame(boundingBox);

                        Mat img_hsv;
                        cvtColor(img_roi, img_hsv, COLOR_BGR2HSV);

                        Mat img_out;
                        img_frame.copyTo(img_out);


                        uchar* pointer_row = img_hsv.ptr<uchar>(img_hsv.rows / 2);

                        //
                        uint h = pointer_row[(img_hsv.cols / 2) * 3 + 0];
                        uint s = pointer_row[(img_hsv.cols / 2) * 3 + 1];
                        uint v = pointer_row[(img_hsv.cols / 2) * 3 + 2];
                        std::string url = msclr::interop::marshal_as<std::string>(searchURL->ToString());

                        std::istringstream iss(url);
                        std::string str_buf;
                        std::string str[5];
                        int i = 0;

                        //i가 2일때
                        while (getline(iss, str_buf, '\\')) {
                            str[i] = str_buf;
                            i++;
                        }

                        if (str[2].empty())
                        {
                            continue;
                        }

                        MYSQL_ROW mr = sql->PhoneInfo(str[2]);

                        int phoneNo = std::atoi(mr[0]);
                        int sqlH = std::atoi(mr[1]);
                        int sqlWidth = std::atoi(mr[2]);
                        int sqlHeight = std::atoi(mr[3]);

                        int checkH = sqlH - h;
                        int checkWidth = sqlWidth - width;
                        int checkHeight = sqlHeight - height;

                        if (((checkH >= -3 && checkH <= 3)) && ((checkWidth >= -5 && checkWidth <= 5)) &&
                            ((checkHeight >= -5 && checkHeight <= 5)))
                        {
                            Mat targetImage = img_frame(boundingBox);
                            
                            Mat standardImage = imread(url, IMREAD_ANYCOLOR);

                            double final_score = compareFeature(targetImage, standardImage);


                            std::cout << "Similarity (일치율) : " << final_score << " % " << std::endl;

                            if (final_score >= 60)
                            {
                                pb->Image = System::Drawing::Image::FromFile(gcnew System::String(url.c_str()));
                                timer_search->Stop();

                                if (System::Windows::Forms::MessageBox::Show("탐색 완료\n이미지의 결과와 같은 휴대폰 인가요?", "탐색 결과", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
                                {
                                    break;
                                }
                                else
                                {
                                    timer_search->Start();
                                    pb->Image = nullptr;
                                }
                                
                            }
                                
                        }
                    }

                }

                // 프레임 화면에 표시
                imshow("Frame", img_frame);


                if (waitKey(1) == 27) //ESC를 누르면 종료
                {
                    System::Windows::Forms::MessageBox::Show("탐색 종료");
                    return;
                }

                
            }

            cap.release();
            destroyAllWindows();

        }

        // 이미지 전처리 함수
        Mat IMG(Mat img1) {

            Mat img_gray;
            cvtColor(img1, img_gray, COLOR_BGR2GRAY);

            Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(3, 3));
            Mat img_dilate;
            dilate(img_gray, img_dilate, kernel, cv::Point(-1, -1), 1);

            Mat img_erode;
            erode(img_dilate, img_erode, kernel, cv::Point(-1, -1), 1);

            Mat img_blur;
            GaussianBlur(img_erode, img_blur, cv::Size(3, 3), 0);

            Mat img_binary;
            adaptiveThreshold(img_blur, img_binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);

            Mat img_contrast;
            equalizeHist(img_binary, img_contrast);

            Mat img_processed;
            bitwise_not(img_contrast, img_processed);

            Mat img_close;
            morphologyEx(img_processed, img_close, MORPH_CLOSE, kernel);

            return img_close;
        }

        // ORB 특징을 사용하여 이미지 비교하는 함수
        double compareFeature(const Mat& img1, const Mat& img2) {
            double retVal = 0;
            auto startTime = static_cast<double>(getTickCount());

            // 이미지의 키포인트 선언
            std::vector<KeyPoint> keypoints1, keypoints2;
            Mat descriptors1, descriptors2;

            //// ORB 키포인트 최대 개수 설정
            int maxKeypoints = 100;

            // ORB 키포인트 검출자와 기술자 추출자 정의
            Ptr<FeatureDetector> detector = ORB::create(maxKeypoints);//최대개수 100
            Ptr<DescriptorExtractor> extractor = ORB::create();

            //이미지 전처리 생략, 필요시 사용할 것
            //Mat img_close = IMG(img1);
            //Mat img_close2 = IMG(img2);

            // 키포인트 검출
            detector->detect(img1, keypoints1);
            detector->detect(img2, keypoints2);

            // 기술자 추출
            extractor->compute(img1, keypoints1, descriptors1);
            extractor->compute(img2, keypoints2, descriptors2);

            // 기술자 매처 정의
            Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");

            // 두 이미지의 포인트 매칭
            std::vector<DMatch> matches;
            double max_dist = 0;
            double min_dist = 100;

            // 예외 방지
            // Assertion failed (type == src2.type() && src1.cols == src2.cols && (type == CV_32F || type == CV_8U)
            if (descriptors2.cols == descriptors1.cols) {
                matcher->match(descriptors1, descriptors2, matches);

                for (int i = 0; i < descriptors1.rows; i++) {
                    double dist = matches[i].distance;
                    if (dist < min_dist)
                        min_dist = dist;
                    if (dist > max_dist)
                        max_dist = dist;
                }
                std::cout << "\n/////////////////////////////////////////" << std::endl;
                std::cout << "키포인트 개수= " << matches.size() << std::endl;
                std::cout << "max_dist=" << max_dist << ", min_dist=" << min_dist << std::endl;

                // 좋은 매칭 추출 (거리가 20 이하인 경우)
                for (int i = 0; i < descriptors1.rows; i++) {
                    if (matches[i].distance <= 75) {
                        retVal++;
                    }
                }
                std::cout << "매칭 개수=" << retVal << std::endl;
            }

            auto estimatedTime = static_cast<int>((getTickCount() - startTime) / getTickFrequency() * 1000);
            std::cout << "소요 시간=" << estimatedTime << "ms" << std::endl;

            return (retVal / matches.size()) * 100;
        }



	/// <summary>
	/// /////////////////////////////////////////////////////
	/// </summary>
	private: System::Void UserMenu_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		delete sql;
	}
    private: System::Void UserMenu_Shown(System::Object^ sender, System::EventArgs^ e) {
        MYSQL_ROW Row = sql->UserInfo(userNum);
        if (Row[3] == NULL)
        {
            System::Windows::Forms::MessageBox::Show("등록된 핸드폰이 없습니다\n핸드폰 등록을 하겠습니다");
            phoneRagistration();
        }
    }
    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        if (maxIndex >= 0 && (checkWidth >= 100 && checkHeight >= 100) && (checkWidth <= 600 && checkHeight <= 600))
        {
            std::cout << "색상 : " << h << std::endl;
            std::cout << "채도 : " << s << std::endl;
            std::cout << "명도 : " << v << std::endl;
            std::cout << "Width : " << width << std::endl;
            std::cout << "Height : " << height << std::endl;
            
            checkNum[compareNum][0] = h;
            checkNum[compareNum][1] = width;
            checkNum[compareNum][2] = height;

            if (checkTime)
            {
                int h1 = checkNum[0][0] - checkNum[1][0];
                int h2 = checkNum[0][0] - checkNum[2][0];
                int w1 = checkNum[0][1] - checkNum[1][1];
                int w2 = checkNum[0][1] - checkNum[2][1];
                int e1 = checkNum[0][2] - checkNum[1][2];
                int e2 = checkNum[0][2] - checkNum[2][2];
                if (((h1 >= -3 && h1 <= 3) && (h2 >= -3 && h2 <= 3)) && ((w1 >= -5 && w1 <= 5) && (w2 >= -5 && w2 <= 5)) &&
                    ((e1 >= -5 && e1 <= 5) && (e2 >= -5 && e2 <= 5)))
                {
                    breakDetection = true;
                    timer1->Stop();
                }
            }

            if (compareNum == 2)
            {
                compareNum = 0;
                checkTime = true;
            }
            else
                compareNum++;
        }
    }
    private: System::Void timer_lensScan_Tick(System::Object^ sender, System::EventArgs^ e) {
        if (searchTime < 5)
        {
            if (maxCount < circlesSize)
            {
                maxCount = circlesSize;
            }
            searchTime++;
        }
        else
        {
            timer_lensScan->Stop();
            checkLensTime = true;
        }
    }

    private: System::Void bt_certify_Click(System::Object^ sender, System::EventArgs^ e) {
        if (certify)
        {
            System::Windows::Forms::MessageBox::Show("이미 인증되어 있습니다.");
        }
        else
        {
            userCertify();
        }
    }
    private: System::Void bt_ReRagist_Click(System::Object^ sender, System::EventArgs^ e) {
        if (certify)
        {
            if (System::Windows::Forms::MessageBox::Show("재등록 하시겠습니까?", "재등록", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
            {
                phoneRagistration();
            }
        }
        else
        {
            System::Windows::Forms::MessageBox::Show("인증을 해야합니다");
        }
    }
    private: System::Void timer_search_Tick(System::Object^ sender, System::EventArgs^ e) {
        std::vector<MYSQL_ROW> searchRow = sql->AllPhoneNum();
        std::string s = searchRow.at(selectNum)[0];

        searchURL = ".\\image\\"+ gcnew System::String(s.c_str()) + "\\WARPING_VIEW_1.jpg";
        //System::Console::WriteLine(searchURL);

        if (selectNum == searchRow.size() - 1)
            selectNum = 0;
        else
            selectNum++;
    }
    private: System::Void bt_Search_Click(System::Object^ sender, System::EventArgs^ e) {
        if (certify)
        {
            phoneSearch();
        }
        else
        {
            System::Windows::Forms::MessageBox::Show("인증을 해야합니다");
        }
    }
};
}
