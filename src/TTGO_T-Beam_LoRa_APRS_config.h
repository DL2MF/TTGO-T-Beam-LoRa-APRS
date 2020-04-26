// Tracker for LoRA APRS Header for configuration
//
// TTGO T-Beam includes GPS module + optional DHT22 (not yet DONE)
//
// can be used as tracker only, tracker plus weather reports (temperature and humidity) or weather reports station only
//
// updated from OE1ACM sketch by OE3CJB to enable WX data to be sent via LoRa APRS.
// one package is with position and battery voltage
// the next is with weather data in APRS format
//
// licensed under CC BY-NC-SA
//
// version: V1.1beta
// last update: 22.11.2019
//
// change history
// version V1.0
// added HW Version V1.0 support
// added presetting in the header TTGO...config.h to prevent long initial setup at first boot up
// added "SPACE" to allowed letters for callsign for shorter callsigns - has to be added at the end
// added smart beaconing
//
// version V1.2
// first released version

// SET HW version
// #define T_BEAM_V1_0    // use this for newer Boards AKA Rev1 (second board release)
#define T_BEAM_V0_7    // use this for older Boards AKA Rev0.x (first board release)

// SET temperature sensor type
// #define DHT22        // default sensor DHT22 (supports temp & humidity)
// #define DS18B20      // use this if you use DS18B20 (supports temp))
// #define BME280          // use this for BOSCH BME280 (supports temp, pressure / humidity)

// USER DATA - USE THESE LINES TO MODIFY YOUR PREFERENCES
// IF NOT CHANGED you have to go through the configuration routine at first boot up of the TTGO T-Beam

#define DONT_USE_FLASH_MEMORY   // uncomment if you don't want to use Flashmemory - instead data below must be corrected

#define APRS_MODE TRACKER       // Mobile APRS-Tracker sending position data   
//#define APRS_MODE WX_MOVE     // Mobile APRS-Tracker sending position data and sensor/wheater data   
//#define APRS_MODE WX_FIXED    // Fixed APRS-Weather station
//#define APRS_MODE WX_TRACKER  // tbd

#define CALLSIGN "DL2MF -7"     // enter your callsign here - less then 6 letter callsigns please add "spaces" so total length is 6 (without SSID)
#define WX_CALLSIGN "DL0CN -13"  // use same callsign but you can use different SSID
#define LATIDUDE_PRESET "5236.66N"   // please in APRS notation DDMM.mmN or DDMM.mmN 5236.62N
#define LONGITUDE_PRESET "01016.96E" // please in APRS notation DDDMM.mmE or DDDMM.mmE 01016.94E
#define APRS_SYMBOL "["         // other symbols are
                                // "_" => Weather Station
                                // "O" => Balloon
                                // ">" => CAR
                                // "[" => RUNNER
                                // "b" => BICYCLE
                                // "<" => MOTORCYCLE
#define APRS_DEST "APB2MF"      // APRS-Destination override (officially assigned by WB4APRS)

// POWER LEVEL PARAMETERS       - 2020-04-10 - DL2MF added new smart options
#define LOW_TXPOWER 5           // low power level in dBm used while GPS search and when fixed location operation (like WX-station)
#define STD_TXPOWER 20          // normal power level in dBm (valid 5-20)
#define MAX_TXPOWER 20          // maximum power level 20dbM (HW restriction)

// SMART BEACONING PARAMETERS   - 2020-04-10 - DL2MF added new smart options
#define TURN_ANGLE 25           // enter turn angle for smart direction depending beaconing (default=30)
#define TURN_TIME 3             // seconds for TURN_ANGLE depending TX
#define SLOW_RATE 300           // slow speed TX rate
#define SLOW_SPEED 3            // slow speed in km/h
#define FAST_RATE 90            // high speed TX rate
#define FAST_SPEED 6           // fast speed in km/h
#define STOP_BEACON 1           // send one beacon when stopping movement (0-false / 1-true) 
                                // beacon is send once only, after TX average speed must be reached again

// TRANSMIT INTERVAL
#define MAX_TIME 300             // set here MAXIMUM delay time in Sec - SLOW_RATE may overwrite (minimum time is hardcoded, set dynamic when smart beaconing is used)

// show RX values
#define SHOW_RX_PACKET       // uncomment to show received LoRa APS packets for the time given below
#define SHOW_RX_TIME 5000       // show RX packet for milliseconds (5000 = 5secs)
