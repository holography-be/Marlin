// Thermistor.h

#ifndef _THERMISTOR_h
#define _THERMISTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ThermistorClass
{
 protected:


 public:
	static float getTemp(int pinNumber);
};

extern ThermistorClass Thermistor;

#endif

