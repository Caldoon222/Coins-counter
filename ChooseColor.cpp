#include <iostream>



//function to select circle color
int ChooseColor(int& b, int& g, int& r) {

	std::cout << "COLOR CHECK\n1 - BLUE\n2 - RED\n3 - GREEN\n4 - YELLOW\n5 - PURPLE\nEnter now: ";
	int colorcheck;
	std::cin >> colorcheck;


	while (!(colorcheck >= 1 && colorcheck <= 5)) {
		std::cout << "Please enter number 1-5\n";
		std::cin >> colorcheck;
	}


	switch (colorcheck)
	{
	case 1:	//BLUE
	{
		b = 255;
		g = 1;
		r = 1;
		break;
	}

	case 2:	//RED
	{
		b = 1;
		g = 1;
		r = 255;
		break;
	}
	case 3:	//GREEN
	{
		b = 1;
		g = 255;
		r = 1;
		break;
	}
	case 4:	//YELLOW
	{
		b = 1;
		g = 255;
		r = 255;
		break;
	}
	case 5:	//PURPLE
	{
		b = 128;
		g = 1;
		r = 128;
		break;
	}
	}
	return b, g, r;
}