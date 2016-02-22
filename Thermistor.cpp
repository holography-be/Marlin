// 
// 
// 

#include "Thermistor.h"


float ThermistorClass::getTemp(int pinNumber) {
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
		average += analogRead(pinNumber);
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

ThermistorClass Thermistor;

