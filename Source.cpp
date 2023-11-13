#include <iostream>
#include "Header.h"







int main()
{
	int check;
	std::cout << "Are you using Webcam(1) or Image(0) Enter number: ";
	std::cin >> check;

	switch (check)
	{
	 case(1):
		CoinDetectionWebCam();
	 case(0):
		CoinDetectionImage();
	}


	return 0;
}