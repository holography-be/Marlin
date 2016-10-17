// 
// 
// 

#include "DAC.h"
#include "Marlin.h"


// pour éviter une conversion coûteuse 
const PROGMEM uint16_t Volt[256] =
{
	0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240, 256, 273, 289, 305, 321, 337, 353,
	369, 385, 401, 417, 433, 449, 465, 481, 497, 513, 529, 546, 562, 578, 594, 610, 626, 642, 658,
	674, 690, 706, 722, 738, 754, 770, 786, 802, 819, 835, 851, 867, 883, 899, 915, 931, 947, 963, 979, 995,
	1011, 1027, 1043, 1059, 1075, 1092, 1108, 1124, 1140, 1156, 1172, 1188, 1204, 1220, 1236,
	1252, 1268, 1284, 1300, 1316, 1332, 1348, 1365, 1381, 1397, 1413, 1429, 1445, 1461, 1477, 1493, 1509,
	1525, 1541, 1557, 1573, 1589, 1605, 1621, 1638, 1654, 1670, 1686, 1702, 1718, 1734, 1750,
	1766, 1782, 1798, 1814, 1830, 1846, 1862, 1878, 1894, 1911, 1927, 1943, 1959, 1975, 1991, 2007, 2023,
	2039, 2055, 2071, 2087, 2103, 2119, 2135, 2151, 2167, 2184, 2200, 2216, 2232, 2248, 2264,
	2280, 2296, 2312, 2328, 2344, 2360, 2376, 2392, 2408, 2424, 2440, 2457, 2473, 2489, 2505, 2521, 2537,
	2553, 2569, 2585, 2601, 2617, 2633, 2649, 2665, 2681, 2697, 2713, 2730, 2746, 2762, 2778,
	2794, 2810, 2826, 2842, 2858, 2874, 2890, 2906, 2922, 2938, 2954, 2970, 2986, 3003, 3019, 3035, 3051,
	3067, 3083, 3099, 3115, 3131, 3147, 3163, 3179, 3195, 3211, 3227, 3243, 3259, 3276, 3292,
	3308, 3324, 3340, 3356, 3372, 3388, 3404, 3420, 3436, 3452, 3468, 3484, 3500, 3516, 3532, 3549, 3565,
	3581, 3597, 3613, 3629, 3645, 3661, 3677, 3693, 3709, 3725, 3741, 3757, 3773, 3789, 3805,
	3822, 3838, 3854, 3870, 3886, 3902, 3918, 3934, 3950, 3966, 3982, 3998, 4014, 4030, 4046, 4062, 4078, 4095
};



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

uint8_t DAC::getMin() {
	return _min;
}

uint8_t DAC::getMax() {
	return _max;
}

void DAC::setMaxPower(uint8_t max) {
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
void DAC::setLevel(uint8_t value) {
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
void DAC::setPower(uint8_t value) {
	if (value >= 0 && value <= 100) {
		//uint16_t tempValue = map(value, 0, 100, 0, _realMax);
		_dac.setVoltage(map(value, 0, 100, 0, _realMax), false);
		_currentLevel = map(value, 0, 100, 0, 255);
		_currentPower = value;
	}
	return;
}

uint8_t DAC::getLevel() {
	return _currentLevel;
}

uint8_t DAC::getPower() {
	return _currentPower;
}

uint8_t DAC::getRealPower() {
	return map(_currentPower, 0, 100, 0, _max);
}

uint8_t DAC::getMaxPower() {
	return _max;
}



