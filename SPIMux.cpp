
#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "SPIMux.h"

SPIMux::SPIMux(unsigned numSSPins, int* SSPins) {
	mSSPinIndex = 0;
	
	mNumSSPins = numSSPins;
	mSSPins = (int*) malloc(numSSPins * sizeof(int));
	for (unsigned i = 0; i < numSSPins; i++) {
		mSSPins[i] = SSPins[i];
		pinMode(mSSPins[i], OUTPUT);
		digitalWrite(mSSPins[i], HIGH);//set them to a defined state by default!
	}
}

SPIMux::~SPIMux () {
	free(mSSPins);
	mSSPins = 0;
}

void SPIMux::select (unsigned SSChanIndex) {
	if (SSChanIndex < mNumSSPins) {
		mSSPinIndex = SSChanIndex;
		digitalWrite(mSSPins[mSSPinIndex], LOW);
	}
}

void SPIMux::unselect () {
	digitalWrite(mSSPins[mSSPinIndex], HIGH);
}

