#ifndef LANGUAGE_H
#define LANGUAGE_H

// NOTE: IF YOU CHANGE THIS FILE / MERGE THIS FILE WITH CHANGES
//
//   ==> ALWAYS TRY TO COMPILE MARLIN WITH/WITHOUT "ULTIPANEL" / "ULTRALCD" / "SDSUPPORT" #define IN "Configuration.h" 
//   ==> ALSO TRY ALL AVAILABLE "LANGUAGE_CHOICE" OPTIONS

// Languages
// 1  English
// 2  Polish
// 3  French
// 4  German
// 5  Spanish
// 6  Russian
// 7  Italian
// 8  Portuguese
// 9  Finnish
// 10 Aragonese
// 11 Dutch
// 12 Catalan
// 13 Basque-Euskera

#ifndef LANGUAGE_CHOICE
  #define LANGUAGE_CHOICE 1  // Pick your language from the list above
#endif

#define PROTOCOL_VERSION "1.0"


  #define MACHINE_NAME "Vertex"
  #define FIRMWARE_URL "http://www.vertex3dprinter.eu/"



#ifndef MACHINE_UUID
   #define MACHINE_UUID "00000000-0000-0000-0000-000000000000"
#endif


#define STRINGIFY_(n) #n
#define STRINGIFY(n) STRINGIFY_(n)


// Common LCD messages
/* nothing here as of yet */

// Common serial messages
#define MSG_MARLIN "Marlin"



#if LANGUAGE_CHOICE == 1

// LCD Splashscreen Messages
// Please note these can be 20 characters!

        #define MSG_SPLASH_NAME " VERTEX  3D PRINTER"
        #define MSG_SPLASH_FIRMWARE "M:1.0 V:1.4 HEADS:1"
        #define MSG_SPLASH_WEBSITE1 " vertex3dprinter.eu"
        #define MSG_SPLASH_WEBSITE2 "    velleman.eu"

        #define MSG_SPLASH_NAME_SMALL "VERTEX 3D PRINTER"
        #define MSG_SPLASH_FIRMWARE_SMALL "M:1.0 V:1.4 HDS:1"
        #define MSG_SPLASH_WEBSITE1_SMALL "     K8400.eu"
        #define MSG_SPLASH_WEBSITE2_SMALL "   velleman.eu"

// LCD Menu Messages
// Please note these are limited to 17 characters!

  #define WELCOME_MSG MACHINE_NAME " is ready"
  #define MSG_SD_INSERTED "Card inserted"
  #define MSG_SD_REMOVED "Card removed"
  #define MSG_MAIN "Main menu"
  #define MSG_AUTOSTART "Autostart"
  #define MSG_DISABLE_STEPPERS "Disable motors"
  #define MSG_AUTO_HOME "Auto home"
  #define MSG_SET_ORIGIN "Set origin"
  #define MSG_PREHEAT_PLA "Preheat PLA"
  #define MSG_PREHEAT_PLA0 "Preheat PLA 1"
  #define MSG_PREHEAT_PLA1 "Preheat PLA 2"
  #define MSG_PREHEAT_PLA2 "Preheat PLA 3"
  #define MSG_PREHEAT_PLA012 "Preheat PLA All"
  #define MSG_PREHEAT_PLA_BEDONLY "Preheat PLA Bed"
  #define MSG_PREHEAT_PLA_SETTINGS "Preheat PLA conf"
  #define MSG_PREHEAT_ABS "Preheat ABS"
  #define MSG_PREHEAT_ABS0 "Preheat ABS 1"
  #define MSG_PREHEAT_ABS1 "Preheat ABS 2"
  #define MSG_PREHEAT_ABS2 "Preheat ABS 3"
  #define MSG_PREHEAT_ABS012 "Preheat ABS All"
  #define MSG_PREHEAT_ABS_BEDONLY "Preheat ABS Bed"
  #define MSG_PREHEAT_ABS_SETTINGS "Preheat ABS conf"
  #define MSG_COOLDOWN "Cooldown"
  #define MSG_SWITCH_PS_ON "Switch power on"
  #define MSG_SWITCH_PS_OFF "Switch power off"
  #define MSG_EXTRUDE "Extrude"
  #define MSG_RETRACT "Retract"
  #define MSG_MOVE_AXIS "Move axis"
  #define MSG_MOVE_X "Move X"
  #define MSG_MOVE_Y "Move Y"
  #define MSG_MOVE_Z "Move Z"
  #define MSG_MOVE_E "Extruder 1"
  #define MSG_MOVE_E1 "Extruder 2"
  #define MSG_MOVE_E2 "Extruder 3"
  #define MSG_MOVE_01MM "Move 0.1mm"
  #define MSG_MOVE_1MM "Move 1mm"
  #define MSG_MOVE_10MM "Move 10mm"
  #define MSG_SPEED "Speed"
  #define MSG_NOZZLE "Nozzle 1"
  #define MSG_NOZZLE1 "Nozzle 2"
  #define MSG_NOZZLE2 "Nozzle 3"
  #define MSG_BED "Bed"
  #define MSG_FAN_SPEED "Fan speed"
  #define MSG_FLOW "Flow"
  #define MSG_FLOW0 "Flow 1"
  #define MSG_FLOW1 "Flow 2"
  #define MSG_FLOW2 "Flow 3"
  #define MSG_CONTROL "Settings"
  #define MSG_MIN " \002 Min"
  #define MSG_MAX " \002 Max"
  #define MSG_FACTOR " \002 Fact"
  #define MSG_AUTOTEMP "Autotemp"
  #define MSG_ON "On "
  #define MSG_OFF "Off"
  #define MSG_PID_P "PID-P"
  #define MSG_PID_I "PID-I"
  #define MSG_PID_D "PID-D"
  #define MSG_PID_C "PID-C"
  #define MSG_ACC  "Accel"
  #define MSG_VXY_JERK "Vxy-jerk"
  #define MSG_VZ_JERK "Vz-jerk"
  #define MSG_VE_JERK "Ve-jerk"
  #define MSG_VMAX "Vmax "
  #define MSG_X "x"
  #define MSG_Y "y"
  #define MSG_Z "z"
  #define MSG_E "e"
  #define MSG_VMIN "Vmin"
  #define MSG_VTRAV_MIN "VTrav min"
  #define MSG_AMAX "Amax "
  #define MSG_A_RETRACT "A-retract"
  #define MSG_XSTEPS "Xsteps/mm"
  #define MSG_YSTEPS "Ysteps/mm"
  #define MSG_ZSTEPS "Zsteps/mm"
  #define MSG_ESTEPS "Esteps/mm"
  #define MSG_RECTRACT "Rectract"
  #define MSG_TEMPERATURE "Temperature"
  #define MSG_MOTION "Motion"
  #define MSG_CONTRAST "LCD contrast"
  #define MSG_STORE_EPROM "Store memory"
  #define MSG_LOAD_EPROM "Load memory"
  #define MSG_RESTORE_FAILSAFE "Restore failsafe"
  #define MSG_REFRESH "Refresh"
  #define MSG_WATCH "Status screen"
  #define MSG_PREPARE "Control printer"
  #define MSG_TUNE "Tune print job"
  #define MSG_PAUSE_PRINT "Pause print job"
  #define MSG_RESUME_PRINT "Resume print job"
  #define MSG_STOP_PRINT "Stop print job"
  #define MSG_CARD_MENU "Print from SD"
  #define MSG_NO_CARD "No SD card"
  #define MSG_DWELL "Waiting..."
  #define MSG_USERWAIT "Waiting for user"
  #define MSG_RESUMING "Resuming print"
  #define MSG_NO_MOVE "No move."
  #define MSG_KILLED "KILLED. "
  #define MSG_STOPPED "STOPPED. "
  #define MSG_CONTROL_RETRACT  "Retract mm"
  #define MSG_CONTROL_RETRACTF "Retract  V"
  #define MSG_CONTROL_RETRACT_ZLIFT "Hop mm"
  #define MSG_CONTROL_RETRACT_RECOVER "UnRet +mm"
  #define MSG_CONTROL_RETRACT_RECOVERF "UnRet  V"
  #define MSG_AUTORETRACT "AutoRetr."
  #define MSG_FILAMENTCHANGE "Change filament"
  #define MSG_INIT_SDCARD "Init. SD card"
  #define MSG_CNG_SDCARD "Change SD card"
  #define MSG_ZPROBE_OUT "Z probe out. bed"
  #define MSG_POSITION_UNKNOWN "Home X/Y before Z"
  #define MSG_ZPROBE_ZOFFSET "Z Offset"
  #define MSG_BABYSTEP_X "Babystep X"
  #define MSG_BABYSTEP_Y "Babystep Y"
  #define MSG_BABYSTEP_Z "Babystep Z"
  #define MSG_ENDSTOP_ABORT "Endstop abort"
        #define MSG_LOAD_FILAMENT "Load filament"
        #define MSG_UNLOAD_FILAMENT "Unload filament"
        #define MSG_LOAD_ABS_EX1 "Load ABS right"
        #define MSG_UNLOAD_ABS_EX1 "Unload ABS right"
        #define MSG_LOAD_ABS_EX2 "Load ABS left"
        #define MSG_UNLOAD_ABS_EX2 "Unload ABS left"
        #define MSG_LOAD_PLA_EX1 "Load PLA right"
        #define MSG_UNLOAD_PLA_EX1 "Unload PLA right"
        #define MSG_LOAD_PLA_EX2 "Load PLA left"
        #define MSG_UNLOAD_PLA_EX2 "Unload PLA left"
        #define MSG_EXTRUDER_1 "Right (EXT.1)"
        #define MSG_EXTRUDER_2 "Left (EXT.2)"
        #define MSG_LOAD_TEXT0 " Insert filament"
        #define MSG_LOAD_TEXT1 " until 1.5cm is"
        #define MSG_LOAD_TEXT2 " visible in tube"
        #define MSG_LOAD_TEXT3 "Then press button"
        #define MSG_FIRMWARE "Firmware version"
        #define MSG_LED_MENU "Set LED color"
        #define MSG_LED_BLUE "Blue"
        #define MSG_LED_LIGHTBLUE "Lightblue"
        #define MSG_LED_PURPLE "Purple"
        #define MSG_LED_RED "Red"
        #define MSG_LED_GREEN "Green"
        #define MSG_LED_YELLOW "Yellow"
        #define MSG_LED_WHITE "White"
        #define MSG_LED_OFF "Off"


// Serial Console Messages

  #define MSG_Enqueing "enqueing \""
  #define MSG_POWERUP "PowerUp"
  #define MSG_EXTERNAL_RESET " External Reset"
  #define MSG_BROWNOUT_RESET " Brown out Reset"
  #define MSG_WATCHDOG_RESET " Watchdog Reset"
  #define MSG_SOFTWARE_RESET " Software Reset"
  #define MSG_AUTHOR " | Author: "
  #define MSG_CONFIGURATION_VER " Last Updated: "
  #define MSG_FREE_MEMORY " Free Memory: "
  #define MSG_PLANNER_BUFFER_BYTES "  PlannerBufferBytes: "
  #define MSG_OK "ok"
  #define MSG_FILE_SAVED "Done saving file."
  #define MSG_ERR_LINE_NO "Line Number is not Last Line Number+1, Last Line: "
  #define MSG_ERR_CHECKSUM_MISMATCH "checksum mismatch, Last Line: "
  #define MSG_ERR_NO_CHECKSUM "No Checksum with line number, Last Line: "
  #define MSG_ERR_NO_LINENUMBER_WITH_CHECKSUM "No Line Number with checksum, Last Line: "
  #define MSG_FILE_PRINTED "Done printing file"
  #define MSG_BEGIN_FILE_LIST "Begin file list"
  #define MSG_END_FILE_LIST "End file list"
  #define MSG_M104_INVALID_EXTRUDER "M104 Invalid extruder "
  #define MSG_M105_INVALID_EXTRUDER "M105 Invalid extruder "
  #define MSG_M200_INVALID_EXTRUDER "M200 Invalid extruder "
  #define MSG_M218_INVALID_EXTRUDER "M218 Invalid extruder "
  #define MSG_M221_INVALID_EXTRUDER "M221 Invalid extruder "
  #define MSG_ERR_NO_THERMISTORS "No thermistors - no temperature"
  #define MSG_M109_INVALID_EXTRUDER "M109 Invalid extruder "
  #define MSG_HEATING "Heating extruder"
  #define MSG_HEATING_COMPLETE "Heating done."
  #define MSG_BED_HEATING "Heating bed."
  #define MSG_BED_DONE "Bed heating done."
  #define MSG_M115_REPORT "MACHINE_TYPE:" MACHINE_NAME " FIRMWARE_NAME:Modified_Marlin_V1 FIRMWARE_URL:" FIRMWARE_URL " PROTOCOL_VERSION:" PROTOCOL_VERSION "\n"
  #define MSG_COUNT_X " Count X: "
  #define MSG_ERR_KILLED "Printer halted. kill() called!"
  #define MSG_ERR_STOPPED "Printer stopped due to errors. Fix the error and use M999 to restart. (Temperature is reset. Set it after restarting)"
  #define MSG_RESEND "Resend: "
  #define MSG_UNKNOWN_COMMAND "Unknown command: \""
  #define MSG_ACTIVE_EXTRUDER "Active Extruder: "
  #define MSG_INVALID_EXTRUDER "Invalid extruder"
  #define MSG_X_MIN "x_min: "
  #define MSG_X_MAX "x_max: "
  #define MSG_Y_MIN "y_min: "
  #define MSG_Y_MAX "y_max: "
  #define MSG_Z_MIN "z_min: "
  #define MSG_Z_MAX "z_max: "
  #define MSG_M119_REPORT "Reporting endstop status"
  #define MSG_ENDSTOP_HIT "TRIGGERED"
  #define MSG_ENDSTOP_OPEN "open"
  #define MSG_HOTEND_OFFSET "Hotend offsets:"

  #define MSG_SD_CANT_OPEN_SUBDIR "Cannot open subdir"
  #define MSG_SD_INIT_FAIL "SD init fail"
  #define MSG_SD_VOL_INIT_FAIL "volume.init failed"
  #define MSG_SD_OPENROOT_FAIL "openRoot failed"
  #define MSG_SD_CARD_OK "SD card ok"
  #define MSG_SD_WORKDIR_FAIL "workDir open failed"
  #define MSG_SD_OPEN_FILE_FAIL "open failed, File: "
  #define MSG_SD_FILE_OPENED "File opened: "
  #define MSG_SD_SIZE " Size: "
  #define MSG_SD_FILE_SELECTED "File selected"
  #define MSG_SD_WRITE_TO_FILE "Writing to file: "
  #define MSG_SD_PRINTING_BYTE "SD printing byte "
  #define MSG_SD_NOT_PRINTING "Not SD printing"
  #define MSG_SD_ERR_WRITE_TO_FILE "error writing to file"
  #define MSG_SD_CANT_ENTER_SUBDIR "Cannot enter subdir: "

  #define MSG_STEPPER_TOO_HIGH "Steprate too high: "
  #define MSG_ENDSTOPS_HIT "endstops hit: "
  #define MSG_ERR_COLD_EXTRUDE_STOP " cold extrusion prevented"
  #define MSG_ERR_LONG_EXTRUDE_STOP " too long extrusion prevented"
  #define MSG_BABYSTEPPING_X "Babystepping X"
  #define MSG_BABYSTEPPING_Y "Babystepping Y"
  #define MSG_BABYSTEPPING_Z "Babystepping Z"
  #define MSG_SERIAL_ERROR_MENU_STRUCTURE "Error in menu structure"

#endif





#if LANGUAGE_CHOICE == 3

// LCD Menu Messages
// Please note these are limited to 17 characters!

  #define WELCOME_MSG MACHINE_NAME " prete."
  #define MSG_SD_INSERTED "Carte inseree"
  #define MSG_SD_REMOVED "Carte retiree"
  #define MSG_MAIN "Menu principal"
  #define MSG_AUTOSTART "Demarrage auto"
  #define MSG_DISABLE_STEPPERS "Arreter moteurs"
  #define MSG_AUTO_HOME "Home auto."
  #define MSG_SET_ORIGIN "Regler origine"
  #define MSG_PREHEAT_PLA " Prechauffage PLA"
  #define MSG_PREHEAT_PLA0 "Prechauff. PLA 1"
        #define MSG_PREHEAT_PLA1 "Prechauff. PLA 2"
  #define MSG_PREHEAT_PLA2 "Prechauff. PLA 3"
  #define MSG_PREHEAT_PLA012 "Prech. PLA Tout"
  #define MSG_PREHEAT_PLA_BEDONLY "Prech. PLA Plateau"
  #define MSG_PREHEAT_PLA_SETTINGS "Regl. prech. PLA"
  #define MSG_PREHEAT_ABS "Prechauffage ABS"
  #define MSG_PREHEAT_ABS0 "Prechauff. ABS 1"
  #define MSG_PREHEAT_ABS1 "Prechauff. ABS 2"
  #define MSG_PREHEAT_ABS2 "Prechauff. ABS 3"
  #define MSG_PREHEAT_ABS012 "Prech. ABS Tout"
  #define MSG_PREHEAT_ABS_BEDONLY "Prech. ABS Plateau"
  #define MSG_PREHEAT_ABS_SETTINGS "Regl. prech. ABS"
  #define MSG_COOLDOWN "Refroidir"
  #define MSG_SWITCH_PS_ON "Allumer alim."
  #define MSG_SWITCH_PS_OFF "Eteindre alim."
  #define MSG_EXTRUDE "Extrusion"
  #define MSG_RETRACT "Retraction"
  #define MSG_PREHEAT_PLA "Prechauffage PLA"
  #define MSG_PREHEAT_ABS "Prechauffage ABS"
  #define MSG_MOVE_AXIS "Deplacer un axe"
  #define MSG_MOVE_X "Move X"
  #define MSG_MOVE_Y "Move Y"
  #define MSG_MOVE_Z "Move Z"
  #define MSG_MOVE_E "Extruder"
  #define MSG_MOVE_E1 "Extruder2"
  #define MSG_MOVE_E2 "Extruder3"
  #define MSG_MOVE_01MM "Move 0.1mm"
  #define MSG_MOVE_1MM "Move 1mm"
  #define MSG_MOVE_10MM "Move 10mm"
  #define MSG_SPEED " Vitesse"
  #define MSG_NOZZLE "Buse"
  #define MSG_NOZZLE1 "Buse2"
  #define MSG_NOZZLE2 "Buse3"
  #define MSG_BED "Plateau"
  #define MSG_FAN_SPEED "Vite. ventilateur"
  #define MSG_FLOW "Flux"
  #define MSG_FLOW0 "Flux 0"
  #define MSG_FLOW1 "Flux 1"
  #define MSG_FLOW2 "Flux 2"
  #define MSG_CONTROL "Controler"
  #define MSG_MIN " \002 Min"
  #define MSG_MAX " \002 Max"
  #define MSG_FACTOR " \002 Facteur"
  #define MSG_AUTOTEMP "Temp. Auto."
  #define MSG_ON "Marche "
  #define MSG_OFF "Arret"
  #define MSG_PID_P "PID-P"
  #define MSG_PID_I "PID-I"
  #define MSG_PID_D "PID-D"
  #define MSG_PID_C "PID-C"
  #define MSG_ACC "Accel"
  #define MSG_VXY_JERK "Vxy-jerk"
  #define MSG_VZ_JERK "Vz-jerk"
  #define MSG_VE_JERK "Ve-jerk"
  #define MSG_VMAX "Vmax"
  #define MSG_X "x"
  #define MSG_Y "y"
  #define MSG_Z "z"
  #define MSG_E "e"
  #define MSG_VMIN "Vmin"
  #define MSG_VTRAV_MIN "Vdepl min"
  #define MSG_AMAX "Amax "
  #define MSG_A_RETRACT "A-retract"
  #define MSG_XSTEPS "Xpas/mm"
  #define MSG_YSTEPS "Ypas/mm"
  #define MSG_ZSTEPS "Zpas/mm"
  #define MSG_ESTEPS "Epas/mm"
  #define MSG_TEMPERATURE "Temperature"
  #define MSG_MOTION "Mouvement"
  #define MSG_CONTRAST "Contraste LCD"
  #define MSG_STORE_EPROM "Sauver config"
  #define MSG_LOAD_EPROM "Lire config"
  #define MSG_RESTORE_FAILSAFE "Restaurer defauts"
  #define MSG_REFRESH "Actualiser"
  #define MSG_WATCH "Surveiller"
  #define MSG_PREPARE "Preparer"
  #define MSG_TUNE "Regler"
  #define MSG_PAUSE_PRINT "Interrompre impr."
  #define MSG_RESUME_PRINT "Reprendre impr."
  #define MSG_STOP_PRINT "Arreter impr."
  #define MSG_CARD_MENU "Impr. depuis SD"
  #define MSG_NO_CARD "Pas de carte"
  #define MSG_DWELL "Repos..."
  #define MSG_USERWAIT "Atten. de l'util."
  #define MSG_RESUMING "Repri. de l'impr."
  #define MSG_NO_MOVE "Aucun mouvement."
  #define MSG_KILLED "MORT."
  #define MSG_STOPPED "STOPPE."
  #define MSG_STEPPER_RELEASED "RELACHE."
  #define MSG_CONTROL_RETRACT "Retraction mm"
  #define MSG_CONTROL_RETRACTF "Retraction V"
  #define MSG_CONTROL_RETRACT_ZLIFT "Hop mm"
  #define MSG_CONTROL_RETRACT_RECOVER "UnRet +mm"
  #define MSG_CONTROL_RETRACT_RECOVERF "UnRet V"
  #define MSG_AUTORETRACT "Retract. Auto."
  #define MSG_FILAMENTCHANGE "Changer filament"
  #define MSG_INIT_SDCARD "Init. la carte SD"
  #define MSG_CNG_SDCARD "Changer de carte"
  #define MSG_ZPROBE_OUT "Z sonde exte. lit"
  #define MSG_POSITION_UNKNOWN "Rev. dans XY av.Z"
  #define MSG_ZPROBE_ZOFFSET "Offset Z"
  #define MSG_BABYSTEP_X "Babystep X"
  #define MSG_BABYSTEP_Y "Babystep Y"
  #define MSG_BABYSTEP_Z "Babystep Z"
  #define MSG_ENDSTOP_ABORT "Butee abandon"
  #define MSG_CONTRAST "Contrast"

// Serial Console Messages

  #define MSG_Enqueing "Mise en tampon \""
  #define MSG_POWERUP "Allumage"
  #define MSG_EXTERNAL_RESET " RAZ Externe"
  #define MSG_BROWNOUT_RESET " RAZ defaut alim."
  #define MSG_WATCHDOG_RESET " RAZ Watchdog"
  #define MSG_SOFTWARE_RESET " RAZ logicielle"
  #define MSG_AUTHOR " | Auteur: "
  #define MSG_CONFIGURATION_VER " Derniere MaJ: "
  #define MSG_FREE_MEMORY " Memoire libre: "
  #define MSG_PLANNER_BUFFER_BYTES " PlannerBufferBytes: "
  #define MSG_OK "ok"
  #define MSG_FILE_SAVED "Fichier enregistre."
  #define MSG_ERR_LINE_NO "Le numero de ligne n'est pas la derniere ligne + 1, derniere ligne: "
  #define MSG_ERR_CHECKSUM_MISMATCH "Erreur somme de controle, derniere ligne: "
  #define MSG_ERR_NO_CHECKSUM "Pas de somme de controle avec le numero de ligne, derniere ligne: "
  #define MSG_ERR_NO_LINENUMBER_WITH_CHECKSUM "Pas de numero de ligne avec somme de controle, derniere ligne: "
  #define MSG_FILE_PRINTED "Impression terminee"
  #define MSG_BEGIN_FILE_LIST "Debut de la liste de fichiers"
  #define MSG_END_FILE_LIST "Fin de la liste de fichiers"
  #define MSG_M104_INVALID_EXTRUDER "M104 Extruder invalide"
  #define MSG_M105_INVALID_EXTRUDER "M105 Extruder invalide"
  #define MSG_M200_INVALID_EXTRUDER "M200 Extruder invalide"
  #define MSG_M218_INVALID_EXTRUDER "M218 Extruder invalide"
  #define MSG_M221_INVALID_EXTRUDER "M221 Extruder invalide"
  #define MSG_ERR_NO_THERMISTORS "Pas de thermistor, pas de temperature"
  #define MSG_M109_INVALID_EXTRUDER "M109 Extruder invalide "
  #define MSG_HEATING "En chauffe..."
  #define MSG_HEATING_COMPLETE "Chauffe terminee."
  #define MSG_BED_HEATING "Chauffe du lit."
  #define MSG_BED_DONE "Chauffe du lit terminee."
  #define MSG_M115_REPORT "FIRMWARE_NAME:Marlin V1; Sprinter/grbl mashup for gen6 FIRMWARE_URL:" FIRMWARE_URL " PROTOCOL_VERSION:" PROTOCOL_VERSION " MACHINE_TYPE:" MACHINE_NAME " EXTRUDER_COUNT:" STRINGIFY(EXTRUDERS) " UUID:" MACHINE_UUID "\n"
  #define MSG_COUNT_X " Compteur X: "
  #define MSG_ERR_KILLED "Impression arretee. kill() appelee!"
  #define MSG_ERR_STOPPED "Impression arretee a cause d'erreurs. Corriger les erreurs et utiliser M999 pour la reprendre. (Temperature remise a zero. Reactivez la apres redemarrage)"
  #define MSG_RESEND "Renvoie: "
  #define MSG_UNKNOWN_COMMAND "Commande inconnue: \""
  #define MSG_ACTIVE_EXTRUDER "Extrudeur actif: "
  #define MSG_INVALID_EXTRUDER "Extrudeur invalide"
  #define MSG_X_MIN "x_min: "
  #define MSG_X_MAX "x_max: "
  #define MSG_Y_MIN "y_min: "
  #define MSG_Y_MAX "y_max: "
  #define MSG_Z_MIN "z_min: "
  #define MSG_Z_MAX "z_max: "
  #define MSG_M119_REPORT "Affichage du status des fin de course"
  #define MSG_ENDSTOP_HIT "DECLENCHE"
  #define MSG_ENDSTOP_OPEN "OUVERT"
  #define MSG_HOTEND_OFFSET "Hotend offsets:"

  #define MSG_SD_CANT_OPEN_SUBDIR "Impossible d'ouvrir le sous-repertoire"
  #define MSG_SD_INIT_FAIL "Echec de l'initialisation de la SD"
  #define MSG_SD_VOL_INIT_FAIL "Echec de volume.init"
  #define MSG_SD_OPENROOT_FAIL "Echec openRoot"
  #define MSG_SD_CARD_OK "Carte SD Ok"
  #define MSG_SD_WORKDIR_FAIL "Echec d'ouverture workDir"
  #define MSG_SD_OPEN_FILE_FAIL "Echec d'ouverture, Fichier: "
  #define MSG_SD_FILE_OPENED "Fichier ouvert: "
  #define MSG_SD_SIZE " Taille: "
  #define MSG_SD_FILE_SELECTED "Fichier selectionne"
  #define MSG_SD_WRITE_TO_FILE "Ecriture dans le fichier: "
  #define MSG_SD_PRINTING_BYTE "Octet impression SD "
  #define MSG_SD_NOT_PRINTING "Pas d'impression SD"
  #define MSG_SD_ERR_WRITE_TO_FILE "Erreur d'ecriture dans le fichier"
  #define MSG_SD_CANT_ENTER_SUBDIR "Impossible d'entrer dans le sous-repertoire: "

  #define MSG_STEPPER_TOO_HIGH "Steprate trop eleve: "
  #define MSG_ENDSTOPS_HIT "Fin de course atteint: "
  #define MSG_ERR_COLD_EXTRUDE_STOP " Extrusion a froid evitee"
  #define MSG_ERR_LONG_EXTRUDE_STOP " Extrusion longue evitee"
  #define MSG_BABYSTEPPING_X "Babystepping X"
  #define MSG_BABYSTEPPING_Y "Babystepping Y"
  #define MSG_BABYSTEPPING_Z "Babystepping Z"
  #define MSG_SERIAL_ERROR_MENU_STRUCTURE "Error in menu structure"

#endif



#endif // ifndef LANGUAGE_H
