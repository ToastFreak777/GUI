#include<iostream>
using namespace std;

int main() {
	int Color = 0x12345678;

	/*
	
		red->12
		green->34
		blue->56
		alpha->78

	*/

	unsigned char red = (Color & 0xFF000000) >> 24;
	unsigned char green = (Color & 0x00FF0000) >> 16;
	unsigned char blue = (Color & 0x0000FF00) >> 8;
	unsigned char alpha = (Color & 0x000000FF);

	//Color: 100010111101111011111011
	//Mask:  111111110000000000000000
	//Result:100010110000000000000000

	cout << hex << (int)red << endl;
	cout << hex << (int)green << endl;
	cout << hex << (int)blue << endl;
	cout << hex << (int)alpha << endl;

	return 0;
}