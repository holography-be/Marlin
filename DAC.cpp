// 
// 
// 

#include "DAC.h"
#include "Marlin.h"

void DAC::init() {	
	init(DAC_I2C_ADRESS,0,255);	
}

void DAC::init(uint8_t dac_ic2_address) {
	init(dac_ic2_address,0,255);
}

void DAC::init(uint8_t dac_i2c_address, uint16_t min, uint16_t max) {
	_dac.begin(dac_i2c_address);
	DAC::_min = min;
	DAC::_max = max;
	currentValue = 0;
	currentVoltage = 0.00;
}

void DAC::setVoltage(uint16_t value) {
	if (old_ivalue != value) {
		uint16_t tempValue = (uint16_t)(map(constrain(value, _min, _max), _min, _max, 0, 4096));
		_dac.setVoltage(tempValue, false);
		currentVoltage = convertToVoltage(255);
		currentValue = value;
		old_fvalue = currentVoltage;
	}
}

void DAC::setVoltage(float value) {
	if (value != old_fvalue) {
		uint16_t tempValue = map((long)(constrain(value, 0.00, 5.00) * 100), 0, 500, 0, 4096);
		_dac.setVoltage(tempValue,false);
		currentVoltage = value;
		currentValue = map(tempValue,0,4096,_min,_max);
		old_ivalue = currentValue;
		old_fvalue = currentVoltage;
	}
}


float DAC::convertToVoltage(uint16_t value) {
	return map(value, 0, 4096, 0, 500) / 100;
}


DAC Dac;

