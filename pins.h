#ifndef PINS_H
#define PINS_H

#define X_MS1_PIN -1
#define X_MS2_PIN -1
#define Y_MS1_PIN -1
#define Y_MS2_PIN -1
#define Z_MS1_PIN -1
#define Z_MS2_PIN -1
#define E0_MS1_PIN -1
#define E0_MS2_PIN -1
#define E1_MS1_PIN -1
#define E1_MS2_PIN -1
#define DIGIPOTSS_PIN -1

/****************************************************************************************
* Arduino Mega pin assignment
*
****************************************************************************************/
#if MOTHERBOARD == 77
#define KNOWN_BOARD 1

//////////////////FIX THIS//////////////
#ifndef __AVR_ATmega1280__
 #ifndef __AVR_ATmega2560__
 #error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
 #endif
#endif


#if MOTHERBOARD == 77

    #define X_DIR_PIN          23
    #define X_STEP_PIN         25
    #define X_ENABLE_PIN       27
    #define X_MIN_PIN          22
    #define X_MAX_PIN          24   

    #define Y_DIR_PIN          29
    #define Y_STEP_PIN         31
    #define Y_ENABLE_PIN       33
    #define Y_MIN_PIN          26
    #define Y_MAX_PIN          28

    #define Z_DIR_PIN          35
    #define Z_STEP_PIN         37
    #define Z_ENABLE_PIN       39
    #define Z_MIN_PIN          30
    #define Z_MAX_PIN          32

    #define Z2_STEP_PIN        -1
    #define Z2_DIR_PIN         -1
    #define Z2_ENABLE_PIN      -1

    #define E0_DIR_PIN         41
    #define E0_STEP_PIN        43
    #define E0_ENABLE_PIN      45

	#define PROBE_Z_PIN		   34
	#define INTERLOCK_PIN      36


    #define SDPOWER            -1
    #define SDSS               53
    #define LED_PIN            13

    #define BEEPER             40	

    #define FAN_PIN            8 

	#define Relais1			   42
	#define Relais2			   40
	#define Relais3			   46
    #define Relais4            44
	#define ModuleRelaisPower  48
	#define Laser_Driver_PIN		Relais1
	#define Laser_Peltier_PIN		Relais2
	#define Laser_Diode_PIN			Relais3
	#define Laser_Temp_PIN			A0 // ANALOG

    #define Laser_Start_Sequence	 Laser_Driver_PIN,Laser_Peltier_PIN,Laser_Diode_PIN
  	#define Laser_Stop_Sequence		 Laser_Diode_PIN,Laser_Peltier_PIN,Laser_Driver_PIN
    #define Laser_Emergency_Sequence Laser_Diode_PIN,Laser_Driver_PIN // On laisse le Peltier 
	#define Laser_Delai_Sequence	 1500

  #define PS_ON_PIN          -1
  #define KILL_PIN           -1

  #define TEMP_BED_PIN       14   // ANALOG NUMBERING

#endif

// SPI for Max6675 Thermocouple 

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support  
  #define MAX_SCK_PIN          52
  #define MAX_MISO_PIN         50
  #define MAX_MOSI_PIN         51
  #define MAX6675_SS       53
#else
  #define MAX6675_SS       49
#endif

#endif

#ifndef KNOWN_BOARD
#error Unknown MOTHERBOARD value in configuration.h
#endif

//List of pins which to ignore when asked to change by gcode, 0 and 1 are RX and TX, do not mess with those!
#define _E0_PINS E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN,


#ifdef X_STOP_PIN
  #if X_HOME_DIR < 0
    #define X_MIN_PIN X_STOP_PIN
    #define X_MAX_PIN -1
  #else
    #define X_MIN_PIN -1
    #define X_MAX_PIN X_STOP_PIN
  #endif
#endif

#ifdef Y_STOP_PIN
  #if Y_HOME_DIR < 0
    #define Y_MIN_PIN Y_STOP_PIN
    #define Y_MAX_PIN -1
  #else
    #define Y_MIN_PIN -1
    #define Y_MAX_PIN Y_STOP_PIN
  #endif
#endif

#ifdef Z_STOP_PIN
  #if Z_HOME_DIR < 0
    #define Z_MIN_PIN Z_STOP_PIN
    #define Z_MAX_PIN -1
  #else
    #define Z_MIN_PIN -1
    #define Z_MAX_PIN Z_STOP_PIN
  #endif
#endif

#ifdef DISABLE_MAX_ENDSTOPS
#define X_MAX_PIN          -1
#define Y_MAX_PIN          -1
#define Z_MAX_PIN          -1
#endif

#define SENSITIVE_PINS {0, 1, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, Y_DIR_PIN, Y_ENABLE_PIN, Y_MIN_PIN, Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, PS_ON_PIN, \
                        FAN_PIN,                  \
                        _E0_PINS             \
                        analogInputToDigitalPin(TEMP_BED_PIN) }
#endif
