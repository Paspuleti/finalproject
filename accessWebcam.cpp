#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	int return_value;
	
	return_value = MessageBoxA(NULL, "Do your parents know you're a turd?", "Important Message",
		MB_ICONEXCLAMATION | MB_YESNO);
	
	if (return_value == 6)//yes
	{
		cout << "yes" << endl;//test for which button pressed
		//open a window with webcam feed
	}
	else if (return_value == 7)//no
	{
		cout << "no" << endl;//test for which button pressed
	}
	return 0;
}
