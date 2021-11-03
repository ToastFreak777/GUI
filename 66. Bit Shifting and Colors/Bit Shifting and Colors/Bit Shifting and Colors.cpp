#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	//0xFF123456		end result should look like this

	unsigned char alpha = 0xFF;
	unsigned char red = 0x12;
	unsigned char green = 0x34;
	unsigned char blue = 0x56;

	unsigned int color = alpha;


	color <<= 8;		//this will move all values in color left by 8bits which is one byte			//any values previously on the right of FF before the shift will be dropped off and padded with 0s
	color += red;
	color <<= 8;
	color +=green;
	color <<= 8;
	color += blue;

	cout << setfill('0') << setw(8) << hex << color << endl;

	return 0;
}
/*

what this does is moves the bits to the left and right pad with zeros.
	CODE-	Color=Color<<8; or Color<<=8 (more efficient arithmetic)
							   read->"shift equals"

	every 2 places in 0xFF]FF]FF]FF] is one byte
	so moving 8 bits will move two places because 8 bits is 1 byte
*/