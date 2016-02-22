// 
// 
// 

#include "Marlin.h"
#include "LaserControl.h"

bool _isON;

void LaserControlClass::init()
{

	dac.init(DAC_I2C_ADRESS, 100);
	dac.setVoltage(uint16_t(0));
	for (int i = 0; i < 3; i++) {
		pinMode(_startSequence[i],OUTPUT);
		digitalWrite(_startSequence[i],HIGH);
	}
	digitalWrite(ModuleRelais1Power, HIGH);
	digitalWrite(ModuleRelais2Power, HIGH);
}

bool LaserControlClass::Start() {
	if (!_isON) {
		// sortie driver à zéro
		dac.setPower(uint16_t(0));
		for (int i = 0; i < 3; i++) {
			digitalWrite(_startSequence[i], LOW);
			delay(Laser_Delai_Sequence);
		}
		delay(500);
		_isON = true;
	}
	return true;
}

bool LaserControlClass::Stop() {
	if (_isON) {
		dac.setPower(uint16_t(0));
		for (int i = 0; i < 3; i++) {
			digitalWrite(_stopSequence[i],HIGH);
			delay(Laser_Delai_Sequence);
		}
		_isON = false;
	}
	return true;
}

bool LaserControlClass::EmergencyStop() {
	if (_isON) {
		dac.setVoltage(uint16_t(0));
		for (int i = 0; i < 3; i++) {
			digitalWrite(_stopSequence[i], HIGH);
		}
		_isON = false;
	}
	return true;
}

void LaserControlClass::setPower(uint16_t value) {
	if (!_isON) return;
	if (value == dac.getPower()) return;
	dac.setPower(value);
	return;
}

void LaserControlClass::setMaxPower(uint16_t value) {
	if (value < 100 && value > 0) {
		dac.setMaxPower(value);
	}
}

uint16_t LaserControlClass::getRealPower() {
	return dac.getRealPower();
}

uint16_t LaserControlClass::getMaxPower() {
	return dac.getMaxPower();
}

uint16_t LaserControlClass::getPower() {
	return dac.getPower();
}

void LaserControlClass::setLevel(uint16_t value) {
	if (!_isON) return;
	if (value == dac.getLevel()) return;
	dac.setLevel(value);
	return;
}

uint16_t LaserControlClass::getLevel() {
	return dac.getLevel();
}

bool LaserControlClass::isON() {
	return _isON;
}

float LaserControlClass::getTemp() {
	return Thermistor.getTemp(Laser_Temp_PIN);
}

LaserControlClass LaserControl;

