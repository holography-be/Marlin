// 
// 
// 

#include "Marlin.h"
#include "LaserControl.h"

bool _isON;

void LaserControlClass::init()
{

	LaserPWM = 0;
	for (int i = 0; i < 3; i++) {
		pinMode(_startSequence[i],OUTPUT);
		digitalWrite(_startSequence[i],HIGH);
	}
	digitalWrite(ModuleRelaisPower, HIGH);
	pinMode(2, OUTPUT);
	analogWrite(3,0);
}

bool LaserControlClass::Start() {
	if (!_isON) {
		// sortie driver à zéro
		LaserPWM = 0;
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
		LaserPWM = 0;
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
		LaserPWM = 0;
		for (int i = 0; i < 2; i++) {
			digitalWrite(_stopSequence[i], HIGH);
		}
		_isON = false;
	}
	return true;
}

void LaserControlClass::setPower(uint8_t value) {
	if (!_isON) return;
	if (value == LaserPWM) return;
	LaserPWM = value;
	return;
}

uint8_t LaserControlClass::getPower() {
	if (_isON) {
		return LaserPWM;
	}
	return 0;
}

bool LaserControlClass::isON() {
	return _isON;
}

float LaserControlClass::getTemp() {
	return Thermistor.getTemp(Laser_Temp_PIN);
}

LaserControlClass LaserControl;

