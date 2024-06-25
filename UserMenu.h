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
	/// UserMenu�� ���� ����Դϴ�.
	/// </summary>
	public ref class UserMenu : public System::Windows::Forms::Form
	{
	public:
		UserMenu(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
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
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
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
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
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
            this->bt_certify->Font = (gcnew System::Drawing::Font(L"����", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(129)));
            this->bt_certify->Location = System::Drawing::Point(610, 27);
            this->bt_certify->Name = L"bt_certify";
            this->bt_certify->Size = System::Drawing::Size(218, 83);
            this->bt_certify->TabIndex = 0;
            this->bt_certify->Text = L"����";
            this->bt_certify->UseVisualStyleBackColor = true;
            this->bt_certify->Click += gcnew System::EventHandler(this, &UserMenu::bt_certify_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"����", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(129)));
            this->label1->Location = System::Drawing::Point(6, 31);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(228, 48);
            this->label1->TabIndex = 1;
            this->label1->Text = L"���� ����";
            // 
            // lb_circle
            // 
            this->lb_circle->AutoSize = true;
            this->lb_circle->Font = (gcnew System::Drawing::Font(L"����", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(129)));
            this->lb_circle->ForeColor = System::Drawing::Color::Red;
            this->lb_circle->Location = System::Drawing::Point(236, 31);
            this->lb_circle->Name = L"lb_circle";
            this->lb_circle->Size = System::Drawing::Size(68, 48);
            this->lb_circle->TabIndex = 1;
            this->lb_circle->Text = L"��";
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
            this->bt_ReRagist->Font = (gcnew System::Drawing::Font(L"����", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(129)));
            this->bt_ReRagist->Location = System::Drawing::Point(31, 148);
            this->bt_ReRagist->Name = L"bt_ReRagist";
            this->bt_ReRagist->Size = System::Drawing::Size(306, 137);
            this->bt_ReRagist->TabIndex = 3;
            this->bt_ReRagist->Text = L"����";
            this->bt_ReRagist->UseVisualStyleBackColor = true;
            this->bt_ReRagist->Click += gcnew System::EventHandler(this, &UserMenu::bt_ReRagist_Click);
            // 
            // bt_Search
            // 
            this->bt_Search->Font = (gcnew System::Drawing::Font(L"����", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(129)));
            this->bt_Search->Location = System::Drawing::Point(522, 148);
            this->bt_Search->Name = L"bt_Search";
            this->bt_Search->Size = System::Drawing::Size(306, 137);
            this->bt_Search->TabIndex = 3;
            this->bt_Search->Text = L"Ž��";
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
        
        //���� ����
        bool certify;

        //ž�� ����
        System::String^ searchURL;
        int selectNum;

		
	public:
        //Ž�� ���� �ű� ���
		void phoneRagistration()
		{
            VideoCapture cap(CAMNUM);
            if (!cap.isOpened())
            {
                std::cout << "ī�޶� ����" << std::endl;
                return;
            }

            //����� ���� �ʱ�ȭ
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


            checkNum = gcnew array<array<int>^>(3); // 3x3 ��ķ� ����
            for (int i = 0; i < 3; i++)
            {
                checkNum[i] = gcnew array<int>(3); // �� �࿡ 3���� �� ����
                for (int j = 0; j < 3; j++)
                {
                    checkNum[i][j] = 0; // ���÷� �迭�� 0���� �ʱ�ȭ
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
                    std::cout << "ĸó ����" << std::endl;
                    break;
                }
                if (img_frame.empty())
                {
                    std::cout << "�̹��� ����" << std::endl;
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

                //�Ͻ���׷� ��źȭ
                Mat img_contrast;
                equalizeHist(img_binary, img_contrast);

                Mat img_processed;
                subtract(255, img_contrast, img_processed);

                Mat img_close;
                morphologyEx(img_processed, img_close, MORPH_CLOSE, kernel);

                // ������ ã��
                // ������ ����� ���ؼ��� ����ȭ �̹����� ����ؾ� �Ѵ�.
                std::vector<std::vector<cv::Point>> contours;
                findContours(img_close, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

                // ������ �� ���� ū �� ����

                double maxArea = 0; // �ִ� ���� �ʱ�ȭ
                int maxIndex = -1; // �ִ� ������ �ε��� �ʱ�ȭ 
                //-1�� �ʱ�ȭ�ϴ� ���� �迭�� �� ���ε�
                //0���� �� ��� 0��° �ε����� �� �� �ֱ� ����
                //0���� �ص� ������

                //��� ������ ���⿡ ���� �ݺ��� ����
                for (int i = 0; i < contours.size(); i++)
                {
                    //contourArea�� �������� ������ ����ϴ� �Լ�
                    double area = contourArea(contours[i]); //������ ���� ���

                    if (area > maxArea) // �ִ� �������� ũ��
                    {
                        //�ִ� ���� ���� �� �ε����� ���� 
                        maxArea = area;
                        maxIndex = i;
                    }
                }

                this->maxIndex = maxIndex;
                // ��� ���� �׸���
                if (maxIndex >= 0) // maxIndex�� ���� �� ���
                {
                    //boundingRect�� ������ ������ �׸� �� �ִ� �ּ� �簢�� ���
                    boundingBox = boundingRect(contours[maxIndex]);

                    // ��� ������ ����, ���� ũ��
                    int width = boundingBox.width;
                    int height = boundingBox.height;
                    checkWidth = width;
                    checkHeight = height;
                    if ((width >= 100 && height >= 100) && (width <= 600 && height <= 600))
                    {
                        // ȭ�鿡 ǥ��
                        rectangle(img_frame, boundingBox, Scalar(0, 0, 255), 1);
                        std::string sizeText = "Width: " + std::to_string(width) + "  Height: " + std::to_string(height);
                        putText(img_frame, sizeText, cv::Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);

                        // �� ����
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

                // ������ ȭ�鿡 ǥ��
                imshow("Frame", img_frame);
                //imshow("Result", img_close);

                int key = waitKey(1);
                if (key == 27) //ESC�� ������ ����
                {
                    timer1->Stop();
                    System::Windows::Forms::MessageBox::Show("����� ���� �մϴ�.");

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
                    std::cout << "ĸó ����" << std::endl;
                    break;
                }

                // �̹��� ��ó��
                Mat img_gray;
                cvtColor(img_frame, img_gray, COLOR_BGR2GRAY);

                Mat g;
                GaussianBlur(img_gray, g, cv::Size(3, 3), 1);


                std::vector<Vec3f> circles; //floatŸ�� 3ä�� ���� ����
                    
                HoughCircles(img_gray, circles, HOUGH_GRADIENT, 1, 20, 60, 45, 1, 30);
                for (size_t i = 0; i < circles.size(); i++)
                {
                    Vec3i c = circles[i]; //1�� 3�� ���� c
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

            System::Windows::Forms::MessageBox::Show("����� �Ϸ�Ǿ����ϴ�");
		}

        //����
        void userCertify()
        {
            VideoCapture cap(CAMNUM);
            if (!cap.isOpened())
            {
                std::cout << "ī�޶� ����" << std::endl;
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
                    std::cout << "ĸó ����" << std::endl;
                    break;
                }
                if (img_frame.empty())
                {
                    std::cout << "�̹��� ����" << std::endl;
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

                //�Ͻ���׷� ��źȭ
                Mat img_contrast;
                equalizeHist(img_binary, img_contrast);

                Mat img_processed;
                subtract(255, img_contrast, img_processed);

                Mat img_close;
                morphologyEx(img_processed, img_close, MORPH_CLOSE, kernel);

                // ������ ã��
                // ������ ����� ���ؼ��� ����ȭ �̹����� ����ؾ� �Ѵ�.
                std::vector<std::vector<cv::Point>> contours;
                findContours(img_close, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

                // ������ �� ���� ū �� ����

                double maxArea = 0; // �ִ� ���� �ʱ�ȭ
                int maxIndex = -1; // �ִ� ������ �ε��� �ʱ�ȭ 
                //-1�� �ʱ�ȭ�ϴ� ���� �迭�� �� ���ε�
                //0���� �� ��� 0��° �ε����� �� �� �ֱ� ����
                //0���� �ص� ������

                //��� ������ ���⿡ ���� �ݺ��� ����
                for (int i = 0; i < contours.size(); i++)
                {
                    //contourArea�� �������� ������ ����ϴ� �Լ�
                    double area = contourArea(contours[i]); //������ ���� ���

                    if (area > maxArea) // �ִ� �������� ũ��
                    {
                        //�ִ� ���� ���� �� �ε����� ���� 
                        maxArea = area;
                        maxIndex = i;
                    }
                }

                // ��� ���� �׸���
                if (maxIndex >= 0) // maxIndex�� ���� �� ���
                {
                    //boundingRect�� ������ ������ �׸� �� �ִ� �ּ� �簢�� ���
                    boundingBox = boundingRect(contours[maxIndex]);

                    // ��� ������ ����, ���� ũ��
                    int width = boundingBox.width;
                    int height = boundingBox.height;
                    checkWidth = width;
                    checkHeight = height;
                    if ((width >= 100 && height >= 100) && (width <= 600 && height <= 600))
                    {
                        // ȭ�鿡 ǥ��
                        rectangle(img_frame, boundingBox, Scalar(0, 0, 255), 1);
                        std::string sizeText = "Width: " + std::to_string(width) + "  Height: " + std::to_string(height);
                        putText(img_frame, sizeText, cv::Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);

                        // �� ����
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

                            
                            std::cout << "Similarity (��ġ��) : " << final_score << " % " << std::endl;
                            
                            if(final_score >= 60)
                                firstCheck = true;
                        }
                    }

                }

                imshow("Frame", img_frame);

                int key = waitKey(1);
                if (key == 27) //ESC�� ������ ����
                {
                    System::Windows::Forms::MessageBox::Show("���� �ߴ�");
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
        //Ž��
        void phoneSearch()
        {
            VideoCapture cap(CAMNUM);
            if (!cap.isOpened())
            {
                std::cout << "ī�޶� ����" << std::endl;
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
                    std::cout << "ĸó ����" << std::endl;
                    break;
                }
                if (img_frame.empty())
                {
                    std::cout << "�̹��� ����" << std::endl;
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

                //�Ͻ���׷� ��źȭ
                Mat img_contrast;
                equalizeHist(img_binary, img_contrast);

                Mat img_processed;
                subtract(255, img_contrast, img_processed);

                Mat img_close;
                morphologyEx(img_processed, img_close, MORPH_CLOSE, kernel);

                // ������ ã��
                // ������ ����� ���ؼ��� ����ȭ �̹����� ����ؾ� �Ѵ�.
                std::vector<std::vector<cv::Point>> contours;
                findContours(img_close, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

                // ������ �� ���� ū �� ����

                double maxArea = 0; // �ִ� ���� �ʱ�ȭ
                int maxIndex = -1; // �ִ� ������ �ε��� �ʱ�ȭ 
                //-1�� �ʱ�ȭ�ϴ� ���� �迭�� �� ���ε�
                //0���� �� ��� 0��° �ε����� �� �� �ֱ� ����
                //0���� �ص� ������

                //��� ������ ���⿡ ���� �ݺ��� ����
                for (int i = 0; i < contours.size(); i++)
                {
                    //contourArea�� �������� ������ ����ϴ� �Լ�
                    double area = contourArea(contours[i]); //������ ���� ���

                    if (area > maxArea) // �ִ� �������� ũ��
                    {
                        //�ִ� ���� ���� �� �ε����� ���� 
                        maxArea = area;
                        maxIndex = i;
                    }
                }

                // ��� ���� �׸���
                if (maxIndex >= 0) // maxIndex�� ���� �� ���
                {
                    //boundingRect�� ������ ������ �׸� �� �ִ� �ּ� �簢�� ���
                    boundingBox = boundingRect(contours[maxIndex]);

                    // ��� ������ ����, ���� ũ��
                    int width = boundingBox.width;
                    int height = boundingBox.height;
                    checkWidth = width;
                    checkHeight = height;
                    if ((width >= 100 && height >= 100) && (width <= 600 && height <= 600))
                    {
                        // ȭ�鿡 ǥ��
                        rectangle(img_frame, boundingBox, Scalar(0, 0, 255), 1);
                        std::string sizeText = "Width: " + std::to_string(width) + "  Height: " + std::to_string(height);
                        putText(img_frame, sizeText, cv::Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);

                        // �� ����
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

                        //i�� 2�϶�
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


                            std::cout << "Similarity (��ġ��) : " << final_score << " % " << std::endl;

                            if (final_score >= 60)
                            {
                                pb->Image = System::Drawing::Image::FromFile(gcnew System::String(url.c_str()));
                                timer_search->Stop();

                                if (System::Windows::Forms::MessageBox::Show("Ž�� �Ϸ�\n�̹����� ����� ���� �޴��� �ΰ���?", "Ž�� ���", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
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

                // ������ ȭ�鿡 ǥ��
                imshow("Frame", img_frame);


                if (waitKey(1) == 27) //ESC�� ������ ����
                {
                    System::Windows::Forms::MessageBox::Show("Ž�� ����");
                    return;
                }

                
            }

            cap.release();
            destroyAllWindows();

        }

        // �̹��� ��ó�� �Լ�
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

        // ORB Ư¡�� ����Ͽ� �̹��� ���ϴ� �Լ�
        double compareFeature(const Mat& img1, const Mat& img2) {
            double retVal = 0;
            auto startTime = static_cast<double>(getTickCount());

            // �̹����� Ű����Ʈ ����
            std::vector<KeyPoint> keypoints1, keypoints2;
            Mat descriptors1, descriptors2;

            //// ORB Ű����Ʈ �ִ� ���� ����
            int maxKeypoints = 100;

            // ORB Ű����Ʈ �����ڿ� ����� ������ ����
            Ptr<FeatureDetector> detector = ORB::create(maxKeypoints);//�ִ밳�� 100
            Ptr<DescriptorExtractor> extractor = ORB::create();

            //�̹��� ��ó�� ����, �ʿ�� ����� ��
            //Mat img_close = IMG(img1);
            //Mat img_close2 = IMG(img2);

            // Ű����Ʈ ����
            detector->detect(img1, keypoints1);
            detector->detect(img2, keypoints2);

            // ����� ����
            extractor->compute(img1, keypoints1, descriptors1);
            extractor->compute(img2, keypoints2, descriptors2);

            // ����� ��ó ����
            Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");

            // �� �̹����� ����Ʈ ��Ī
            std::vector<DMatch> matches;
            double max_dist = 0;
            double min_dist = 100;

            // ���� ����
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
                std::cout << "Ű����Ʈ ����= " << matches.size() << std::endl;
                std::cout << "max_dist=" << max_dist << ", min_dist=" << min_dist << std::endl;

                // ���� ��Ī ���� (�Ÿ��� 20 ������ ���)
                for (int i = 0; i < descriptors1.rows; i++) {
                    if (matches[i].distance <= 75) {
                        retVal++;
                    }
                }
                std::cout << "��Ī ����=" << retVal << std::endl;
            }

            auto estimatedTime = static_cast<int>((getTickCount() - startTime) / getTickFrequency() * 1000);
            std::cout << "�ҿ� �ð�=" << estimatedTime << "ms" << std::endl;

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
            System::Windows::Forms::MessageBox::Show("��ϵ� �ڵ����� �����ϴ�\n�ڵ��� ����� �ϰڽ��ϴ�");
            phoneRagistration();
        }
    }
    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        if (maxIndex >= 0 && (checkWidth >= 100 && checkHeight >= 100) && (checkWidth <= 600 && checkHeight <= 600))
        {
            std::cout << "���� : " << h << std::endl;
            std::cout << "ä�� : " << s << std::endl;
            std::cout << "�� : " << v << std::endl;
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
            System::Windows::Forms::MessageBox::Show("�̹� �����Ǿ� �ֽ��ϴ�.");
        }
        else
        {
            userCertify();
        }
    }
    private: System::Void bt_ReRagist_Click(System::Object^ sender, System::EventArgs^ e) {
        if (certify)
        {
            if (System::Windows::Forms::MessageBox::Show("���� �Ͻðڽ��ϱ�?", "����", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
            {
                phoneRagistration();
            }
        }
        else
        {
            System::Windows::Forms::MessageBox::Show("������ �ؾ��մϴ�");
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
            System::Windows::Forms::MessageBox::Show("������ �ؾ��մϴ�");
        }
    }
};
}
