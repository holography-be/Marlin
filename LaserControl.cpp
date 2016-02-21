// 
// 
// 

#include "Marlin.h"
#include "LaserControl.h"

bool _isON;

void LaserControlClass::init()
{

	dac.init(DAC_I2C_ADRESS, 0, 255);
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


float LaserControlClass::getTemp() {
	// resistance at 25 degrees C
	#define THERMISTORNOMINAL 100000      
	// temp. for nominal resistance (almost always 25 C)
	#define TEMPERATURENOMINAL 25   
	// how many samples to take and average, more takes longer
	// but is more 'smooth'
	#define NUMSAMPLES 10
	// The beta coefficient of the thermistor (usually 3000-4000)
	#define BCOEFFICIENT 3950
	// the value of the 'other' resistor
	#define SERIESRESISTOR 9870   

	static uint8_t i;
	static float average = 0.0;
	static float steinhart = 0.0;

	// take N samples in a row, with a slight delay
	average = 0;
	for (i = 0; i< NUMSAMPLES; i++) {
		average += analogRead(Laser_Temp_PIN);
		delay(10);
	}
	average /= NUMSAMPLES;
	average = 1023 / average - 1;
	average = SERIESRESISTOR / average;
	steinhart = average / THERMISTORNOMINAL;     // (R/Ro)
	steinhart = log(steinhart);                  // ln(R/Ro)
	steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
	steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
	steinhart = 1.0 / steinhart;                 // Invert
	steinhart -= 273.15;                         // convert to C
	return steinhart;
}

bool LaserControlClass::isON() {
	return _isON;
}

LaserControlClass LaserControl;

