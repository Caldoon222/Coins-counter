#include "Header.h"


int main()
{
	int check;
	std::cout << "Are you using Webcam(1) or Image(0) Enter number: ";
	std::cin >> check;
	while (!(check >= 0 && check <= 1)) {
		std::cout << "Please enter number 1 or 0\n";
		std::cin >> check;
	}


	std::cout << '\n';
	switch (check)
	{
	 case(1):
		CoinDetectionWebCam();
		break;
	 case(0):
		CoinDetectionImage();
		break;
	}


	return 0;
}