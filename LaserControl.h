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
	const uint16_t _startSequence[3] = { Laser_Start_Sequence };
	const uint16_t _stopSequence[3] = { Laser_Stop_Sequence };
	const uint16_t _delai = Laser_Delai_Sequence;
 public:
	void init();
	//DAC getDac();
	bool Start();
	bool Stop();
	bool EmergencyStop();
	float getTemp();
	bool isON();
	void setLevel(uint16_t value);
	void setPower(uint16_t value);
	uint16_t getLevel();
	uint16_t getPower();
};

extern LaserControlClass LaserControl;

#endif

