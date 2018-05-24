#ifndef TESTPR
#define TESTPR

//using namespace hls;


#include "ap_int.h"
#include "ap_cint.h"
#include "ap_utils.h"
#include "hls_stream.h"
struct ap_axis{
	ap_int <64> data;
	ap_uint<1> last;
	ap_uint<8> keep;


};
void  testpr(

		hls::stream <ap_axis> & packetIn,
		ap_int <48> eth_dst,
		ap_int <48> eth_src,
		hls::stream <ap_axis > & packetOut
);


#endif
