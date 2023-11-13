#include"Header.h"
#include <opencv2/opencv.hpp>
#include <iostream>





void CoinDetectionWebCam()
{
		cv::VideoCapture cap(0);

		if (!cap.isOpened())  // if no webcam exit program
		{
			std::cout << "\n\n\n\n===============================\nError: Cannot open the webcam\n===============================\n\n\n\n";
			system("pause");
		}

		cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
		cap.set(cv::CAP_PROP_FRAME_HEIGHT, 340);




		std::cout << "\n\n";

		while (true) {
			int TotalMoney = 0;	//reseting 

			cv::Mat image;
			cap.read(image);


			cv::Mat gray;
			cvtColor(image, gray, cv::COLOR_BGR2GRAY);
			cv::medianBlur(gray, gray, 5);




			std::vector<cv::Vec3f> circles;
			HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 8, 100, 30, 10, 200);
																				// 2 last par min_radius & max_radius 

			if (!circles.empty()) {
				for (int i = 0; i < circles.size(); i++) {
					cv::Vec3i c = circles[i];
					cv::Point center = cv::Point(c[0], c[1]);	// circle center
					circle(image, center, 1, cv::Scalar(255, 255, 0), 3, cv::LINE_AA);	// circle outline

					int radius = c[2];
					circle(image, center, radius, cv::Scalar(255, 0, 255), 3, cv::LINE_AA);
					if (radius > 1)
						TotalMoney += 1;
					//std::cout << radius << '\n';
				}
			}


			putText(image, "Total Money: " + std::to_string(TotalMoney), cv::Point(1, 100), cv::FONT_HERSHEY_PLAIN, 2, 10, 4);
			imshow("circles", image);
			
			cv::waitKey(1);	
			
		}
}







void CoinDetectionImage()
{
	std::string path;
	std::cout << "Enter file name(whith file format(.jpg .png): ";
	std::cin >> path;




	cv::Mat image = cv::imread(path);

	if (image.empty())  // if no image exit program
	{
		std::cout << "\n\n\n\n========================================\nError: Cannot open the image - " << path << "\n"
			<< "======================================== \n\n"


			<< "======================================== \n"
			"Please check the file name or path and try again\n"
			<< "========================================\n";
		system("pause");
		exit(0);
	}



	std::cout << "\n\nwhat is the distance between coins \n==========================\nEnter number: \n" << "alot - 16 \n" << "normal - 8\n" << "little - 2 \n==========================\n" << "Enter now: ";

	int coinsdist = 0;
	std::cin >> coinsdist;


	while (true) {
		int TotalMoney = 0;	//reseting 

		cv::Mat image = cv::imread(path);
		//load image




		cv::Mat gray;
		cvtColor(image, gray, cv::COLOR_BGR2GRAY);
		cv::medianBlur(gray, gray, 5);




		std::vector<cv::Vec3f> circles;
		cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / coinsdist,100, 30, 10, 200);
						//coinsdist - detect circles with different distances to each other		// 2 last par min_radius & max_radius 

		if (!circles.empty()) {
			for (int i = 0; i < circles.size(); i++) {
				cv::Vec3i c = circles[i];
				cv::Point center = cv::Point(c[0], c[1]);	// circle center
				circle(image, center, 1, cv::Scalar(255, 255, 0), 3, cv::LINE_AA);	// circle outline

				int radius = c[2];
				circle(image, center, radius, cv::Scalar(255, 0, 255), 3, cv::LINE_AA);
				if (radius > 1)
					TotalMoney += 1;
				//std::cout << radius << '\n';
			}
		}
		
	
	
		putText(image, "Total Money: " + std::to_string(TotalMoney), cv::Point(1, 100), cv::FONT_HERSHEY_PLAIN, 2, 10, 4);
		cv::namedWindow("circles", cv::WINDOW_NORMAL);
		imshow("circles", image);

		
		cv::waitKey(0);	
		system("pause");
	}
}