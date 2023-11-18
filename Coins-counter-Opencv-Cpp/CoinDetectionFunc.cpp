#include"Header.h"
#include <iostream>




int b, g, r;


//function for working with a webcam
void CoinDetectionWebCam()
{
	int b, g, r;
	cv::VideoCapture cap(0);
	cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, 340);

	// if no webcam exit program
	if (!cap.isOpened())  
	{
		std::cout << "\n\n\n\n===============================\nError: Cannot open the webcam\n===============================\n\n\n\n";
		system("pause");
		exit(0);
	}



	ChooseColor(b, g, r);



	std::cout << "\n\n";

	while (true) {
		int TotalMoney = 0;	

		//reading image
		cv::Mat image;
		cap.read(image);

		//preprocessing image
		cv::Mat gray;
		cvtColor(image, gray, cv::COLOR_BGR2GRAY);
		cv::medianBlur(gray, gray, 5);



		//function for drawing circles
		std::vector<cv::Vec3f> circles;
		HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 8, 100, 30, 10, 200);// 2 last par min_radius & max_radius 
		

		if (!circles.empty()) {
			for (int i = 0; i < circles.size(); i++) {
				cv::Vec3i c = circles[i];
				cv::Point center = cv::Point(c[0], c[1]);
				circle(image, center, 1, cv::Scalar(b, g, r), 3, cv::LINE_AA); // circle center

				int radius = c[2];
				circle(image, center, radius, cv::Scalar(b, g, r), 3, cv::LINE_AA);	// circle outline
				if (radius > 1)
					TotalMoney += 1;
				//std::cout << radius << '\n';
			}
		}

		//display the image
		putText(image, "Total Money: " + std::to_string(TotalMoney), cv::Point(1, 100), cv::FONT_HERSHEY_PLAIN, 2, cv::Scalar(b, g, r), 4);
		imshow("circles", image);

		cv::waitKey(30);
	}
}






//function for working with pictures
void CoinDetectionImage()
{
	std::string path;
	std::cout << "Enter file path(whith file name and format(.jpg .png): ";
	std::cin >> path;

	//reading image
	cv::Mat image = cv::imread(path);




	// if no image exit program
	if (image.empty())  
	{
		std::cout << "\n\n\n\n========================================\nError: Cannot open the image - " << path << "\n"
			<< "======================================== \n\n"


			<< "======================================== \n"
			"Please check the file name or path and try again\n"
			<< "========================================\n";
		system("pause");
		exit(0);
	}



	std::cout << "\n\nwhat is the distance between coins \n==========================\nEnter number: \n" << "long - 16 \n" << "normal - 8\n" << "short - 2 \n==========================\n" << "Enter now: ";

	int coinsdist = 0;
	std::cin >> coinsdist;
	while (!(coinsdist >= 1 && coinsdist <= 16)) {
		std::cout << "Please enter number 1-16\n";
		std::cin >> coinsdist;
	}


	ChooseColor(b, g, r);


	while (true) {
		int TotalMoney = 0;	//reseting 
		//load image
		cv::Mat image = cv::imread(path);
		


		//preprocessing image
		cv::Mat gray;
		cvtColor(image, gray, cv::COLOR_BGR2GRAY);
		cv::medianBlur(gray, gray, 5);


		
		//function for drawing circles
		std::vector<cv::Vec3f> circles;
		HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 8, 100, 30, 10, 200);// 2 last par min_radius & max_radius 
	

		if (!circles.empty()) {
			for (int i = 0; i < circles.size(); i++) {
				cv::Vec3i c = circles[i];
				cv::Point center = cv::Point(c[0], c[1]);
				circle(image, center, 1, cv::Scalar(b, g, r), 3, cv::LINE_AA); // circle center

				int radius = c[2];
				circle(image, center, radius, cv::Scalar(b, g, r), 3, cv::LINE_AA);	// circle outline
				if (radius > 1)
					TotalMoney += 1;
			}
		}




		//display the image
		putText(image, "Total Money: " + std::to_string(TotalMoney), cv::Point(1, 100), cv::FONT_HERSHEY_PLAIN, 2, cv::Scalar(b, g, r), 4);
		cv::namedWindow("circles", cv::WINDOW_NORMAL);	//makes an image resizable
		imshow("circles", image);


		cv::waitKey(0);
	}
}
