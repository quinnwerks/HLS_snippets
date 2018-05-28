#include "testpr.h"
#include <iostream>
using namespace std;
#define TEST_SIZE 5

int main(void){
	hls::stream <ap_axis> streamIn;
	hls::stream <ap_axis> streamOut;
	ap_int <48> nothing = 0x1345;

	int err = 0;

	for (int i = 0; i < TEST_SIZE; i++){
		ap_axis temp;
		temp.data = i;
		temp.keep = 0xab;
		temp.last = (i==TEST_SIZE-1);
		std::cout << "incoming data: " <<temp.data<< std::endl;
		streamIn.write(temp);
	}
	testpr(
			streamIn,
			nothing,
			nothing,
			streamOut
	);
	for (int i = 0; i < TEST_SIZE; i++){
		ap_axis blah;
		blah = streamOut.read();
		std::cout << "data should be: " << i + 69 <<std::endl;
		std::cout << "data is actually: " << blah.data << std::endl;
		if(i + 69 != blah.data){
			err = 1;
		}

	}

	return err;


}
