// 
// 
// 

#include "DAC.h"
#include "Marlin.h"

void DAC::init() {	
	init(DAC_I2C_ADRESS,100);	
}

void DAC::init(uint8_t dac_ic2_address) {
	init(dac_ic2_address,100);
}

void DAC::init(uint8_t dac_i2c_address, uint16_t max) {
	_dac.begin(dac_i2c_address);
	DAC::_max = max;
	_realMax = 0;
	_currentPower = 0;
	_currentLevel = 0;
	currentValue = 0;
	currentVoltage = 0.00;
}

// apply voltage to DAC (0..255) or (min to max)
void DAC::setVoltage(uint16_t value) {
	if (old_ivalue != value) {
		uint16_t tempValue = (uint16_t)(map(constrain(value, _min, _max), _min, _max, 0, 4096));
		_dac.setVoltage(tempValue, false);
		currentVoltage = convertToVoltage(tempValue);
		currentValue = tempValue;
		old_fvalue = currentVoltage;
	}
	return;
}

//// apply voltage to DAC (0..5v)
//void DAC::setVoltage(float value) {
//	if (value != old_fvalue) {
//		uint16_t tempValue = map((long)(constrain(value, 0.00, 5.00) * 100), 0, 500, 0, 4096);
//		_dac.setVoltage(tempValue,false);
//		currentVoltage = value;
//		currentValue = map(tempValue,0,4096,_min,_max);
//		old_ivalue = currentValue;
//		old_fvalue = currentVoltage;
//	}
//	return;
//}


float DAC::convertToVoltage(uint16_t value) {
	return map(value, 0, 4096, 0, 500) / 100;
}

uint16_t DAC::getMin() {
	return _min;
}

uint16_t DAC::getMax() {
	return _max;
}

void DAC::setMaxPower(uint16_t max) {
	// shut off
	setPower(0);
	_max = max;
	_realMax = uint16_t(float(40.96 * _max));
	// Recalcul puissance
	setPower(_currentPower);
	return;
}

//void DAC::setPercentVoltage(uint16_t value) {
//	if (value >= 0 && value <= 100) {
//		float tempValue = ((float)map(value, 0, 100, 0, 500))/100;
//		setVoltage(tempValue);
//	}
//	return;
//}
//
// set Level from 0 to 255
void DAC::setLevel(uint16_t value) {
	if (value >= 0 && value <= 255) {
		//uint16_t tempValue = map(value, 0, 255, 0, _realMax);
		_dac.setVoltage(map(value, 0, 255, 0, _realMax), false);
		_currentLevel = value;
		_currentPower = map(value, 0, 255, 0, 100);
	}
	return;
}

//
// set Power from 0 to 100%
void DAC::setPower(uint16_t value) {
	if (value >= 0 && value <= 100) {
		//uint16_t tempValue = map(value, 0, 100, 0, _realMax);
		_dac.setVoltage(map(value, 0, 100, 0, _realMax), false);
		_currentLevel = map(value, 0, 100, 0, 255);
		_currentPower = value;
	}
	return;
}

uint16_t DAC::getLevel() {
	return _currentLevel;
}

uint16_t DAC::getPower() {
	return _currentPower;
}

uint16_t DAC::getRealPower() {
	return map(_currentPower, 0, 100, 0, _max);
}

uint16_t DAC::getMaxPower() {
	return _max;
}



