#include "mt1337.hpp"

MT1337::MT1337(int seed) {
	index = 624;
	mt[0] = seed;
	
	
	for (int n = 1; n < 624; n++) {
		mt[n] = 1812433253 * ( mt[n-1] ^ mt[n -1] >> 30) + n; 
	} 
};

int MT1337::extractNumber() {
	int y = 0;
	if (index >= 624) {
		twistIt();
		index = 0;
	}
	y = mt[index];
	y = y ^ y >> 11;
	y = y ^ (y << 7 & 2636928640);
	y = y ^ (y << 15 & 4022730752);
	y = y ^ y >> 18;

	index++;

	return y;
}

void MT1337::twistIt() {
	int y = 0;
	for (int n = 0; n < 624; n++) {
		y = (mt[n] & 0x80000000) + (mt[n+1 % 624] & 0x7fffffff);
		mt[n] = mt[(n + 397) % 624] ^ y >> 1;

		if (y % 2 != 0) {
			mt[n] = mt[n] ^ 0x9908b0df;
		}
	}

	index = 0;
}
