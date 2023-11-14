#include "Header.h"


int main()
{
	int check;
	std::cout << "Are you using Webcam(1) or Image(0) Enter number: " << '\n';
	std::cin >> check;




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