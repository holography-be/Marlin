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
	 uint16_t _realMax;
	 float old_fvalue;
	 uint16_t old_ivalue;
	float convertToVoltage(uint16_t value);
	uint16_t _currentPower;
	uint16_t _currentLevel;

 public:
	void init();
	void init(uint8_t dac_i2c_address);
	void init(uint8_t dac_i2c_address, uint16_t max);
	void setVoltage(uint16_t value);
	//void setVoltage(float value);
	//void setPercentVoltage(uint16_t value);
	void setPower(uint16_t value);
	void setLevel(uint16_t value);
	void setMaxPower(uint16_t max);
	uint16_t currentValue;
	float currentVoltage;
	uint16_t getMin();
	uint16_t getMax();
	uint16_t getPower();
	uint16_t getLevel();
	uint16_t getRealPower();
	uint16_t getMaxPower();

};

#endif

