// DAC.h

#ifndef _DAC_h
#define _DAC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_MCP4725.h>

class DAC
{
 protected:
	 Adafruit_MCP4725 _dac;
	 uint16_t _min;
	 uint16_t _max;
	 float old_fvalue;
	 uint16_t old_ivalue;
	float convertToVoltage(uint16_t value);

 public:
	void init();
	void init(uint8_t dac_i2c_address);
	void init(uint8_t dac_i2c_address, uint16_t min, uint16_t max);
	void setVoltage(uint16_t value);
	void setVoltage(float value);
	void setMinMax(uint16_t min, uint16_t max);
	uint16_t currentValue;
	float currentVoltage;
	uint16_t getMin();
	uint16_t getMax();

};

#endif

