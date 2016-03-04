// LaserControl.h

#ifndef _LASERCONTROL_h
#define _LASERCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "DAC.h"
#include "Marlin.h"

class LaserControlClass
{
 protected:
	DAC dac;
	const uint8_t _startSequence[3] = { Laser_Start_Sequence };
	const uint8_t _stopSequence[3] = { Laser_Stop_Sequence };
	const uint8_t _delai = Laser_Delai_Sequence;
 public:
	void init();
	//DAC getDac();
	bool Start();
	bool Stop();
	bool EmergencyStop();
	bool isON();
	void setMaxPower(uint8_t value);
	uint8_t getMaxPower();
	uint8_t getRealPower();
	void setLevel(uint8_t value);
	void setPower(uint8_t value);
	uint8_t getLevel();
	uint8_t getPower();
	float getTemp();
};

extern LaserControlClass LaserControl;

#endif

