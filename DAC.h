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
	 uint8_t _min;
	 uint8_t _max;
	 uint16_t _realMax;
	 float old_fvalue;
	 uint16_t old_ivalue;
	float convertToVoltage(uint16_t value);
	uint8_t _currentPower;
	uint8_t _currentLevel;

 public:
	void init();
	void init(uint8_t dac_i2c_address);
	void init(uint8_t dac_i2c_address, uint16_t max);
	void setVoltage(uint16_t value);
	//void setVoltage(float value);
	//void setPercentVoltage(uint16_t value);
	void setPower(uint8_t value);
	void setLevel(uint8_t value);
	void setMaxPower(uint8_t max);
	uint16_t currentValue;
	float currentVoltage;
	uint8_t getMin();
	uint8_t getMax();
	uint8_t getPower();
	uint8_t getLevel();
	uint8_t getRealPower();
	uint8_t getMaxPower();

};

#endif

