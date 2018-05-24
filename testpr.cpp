#include "testpr.h"

void  testpr(

		hls::stream <ap_axis> & packetIn,
		ap_int <48> eth_dst,
		ap_int <48> eth_src,
		hls::stream <ap_axis > & packetOut
){

	ap_axis currPacketIn;
	ap_axis currPacketOut;
    ap_int <1> last = 0;

    currPacketIn = packetIn.read();

    currPacketOut.data = currPacketIn.data + 69; //heh

    currPacketOut.last = currPacketIn.last;

    currPacketOut.keep = 0xff;

	last = currPacketIn.last;
	packetOut.write(currPacketOut);

	while(!last){

		eth_dst = eth_src;

		currPacketIn = packetIn.read();

		currPacketOut.data = currPacketIn.data + 69; //heh

	    currPacketOut.last = currPacketIn.last;

		currPacketOut.keep = 0xff;

		packetOut.write(currPacketOut);

		last = currPacketIn.last;

	}







}

