//Author: Johannes Lächele
//eMail: siddian@gmail.com

/*
 * Usage Notes:
 * 
 */

#ifndef _SPIMux_h_
#define _SPIMux_h_

class SPIMux {

	//stores the current index of the SS-Pin to use.
	//default value: 0
	unsigned mSSPinIndex;

	unsigned mNumSSPins;
	int* mSSPins;

public:
	/*
	 * create multiplexer by defining the pins to use for the slave select pin SS.
	 */
	SPIMux(unsigned numSSPins, int* SSPins);
	virtual ~SPIMux();

	/*
	 * selects channel with index SSChanIndex.
	 */
	void select (unsigned SSChanIndex);
	/*
	 * unselect current channel
	 */
	void unselect ();
};

#endif
