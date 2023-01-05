# READMElog 
copied from /mnt/e/fs/www/pio/pio-ardui/EspBoth/README.md on 1/2/23

## greenfield setup windows10 (not WSL)
1. install vscode
2. install platformio extension
can't find com port
3. install wemos driver goto https://www.wemos.cc/en/latest/ch340_driver.html. install driver with device plugged in


## resources

https://tttapa.github.io/ESP8266/Chap04%20-%20Microcontroller.html

https://steve.fi/hardware/d1-pins/

## tips
* printf doesn't always print , use Serail.println
* constant values you need access too in multiple files are best declared in a .h file ex: `struct sen_t { .... };, extern const sent_t SE;` then intialized or set in a .cpp file  ex: `const labels_t la {
  {"devtime", "cmd"},2};` 
## weird shit
* in main you have to have `Sched sched;` even though there is no use of that class in main. (req.processInc does use Sched, declaring it in Reqs is not enough) else you get

      undefined reference to `sched'
      collect2.exe: error: ld returned 1 exit status
      *** [.pio\build\d1_mini\firmware.elf] Error 1t
## log

### 1/4/23 02a-oragnaize_conf-abbrev-ports-boards

### 1/2/23 01-iot2_w_secstdif
most current code is secstidif= Sensors-Contolled_Sensors-Timers-Differential_Controller

### 8/5/21 17-secstidif-CYURD200solar
new directory with different name

secstidif = Sensors-Contolled_Sensors-Timers-Differential_Controller are all the functions built into this codebase.

CYURD200solar = CYURD200 is the microcontrollers id, whose owner is tobinmckenna@gmail.com and which is running his solar project. It is also the name of the configuration file CONFUG_CYURD200solar that has been copied into CONFIG.cpp and CONFIG.h. This configuration implements 

    /*SERVER
    dev extern device variables*/
    char devid[9]="CYURD200";
    char owner[254]="tobinmckenna@gmail.com";
    char pwd[24]="xxxxx";
    char mqtt_server[60]="sitebuilt.net";
    char mqtt_port[6]="1884";
    /*dev*/

    srs_t srs {
      4,//numsr (se+cs)
      4,//numse of just sensors
      {//se:{sr,reading,rec,isnew}
        {0,45,1,0},//solar temp J9
        {1,45,1,0},//tank temp J5
        {2,45,1,0},//slab temp J4
        {3,45,1,0}//outdoor temp J8
      },
      2,//numcs
      {//cs:{sr,reading,onoff,hi,lo,isnew}
        {1,120,0,138,100,1,0}, //heatexch
        {1,121,0,180,140,1,0}  //tankles
      }, 
      0,//numti
      {},
      1,//numdi difference control
      {/*di:{sa,sb,don,doff,maxa.maxb,port,onoff,rec,isnew}
            {solar,tank, solar-tank} 
      */
        {0,1,6,2,200,200,D1,0,1,0}
      }
    };
    /*prgs extern data structure initalization*/ 
    prgs_t prgs{
      2,//numprgs
      { //prg: {sr,aid,ev,numdata,prg[[hr,min,max,min]],port,hms}
        {1,255,1,2,{{0,0,80,78}},D8,1504}, //hxch
        {1,255,1,2,{{0,0,75,71}},D7,1503}  //tankles
      }
    };

Solar  = Controller for Tobin's Solar augmented heating system which adds solar panels, a drain down tank, a storage tank and diverters to existing tankles DHW + heat exchanger feeding radiant and baseboard heat.

* copied dependencies to lib_deps in platformio.ini. Hopefully the compiler will realize what is needed and go and get them.

### 7/27/21  16-secstidef-CYURD200solar
Forget about working without wifi (for now), just make it work for these new conditions

#### 2 relays depending on 1 sensor

    { //prg: {sr,aid,ev,numdata,prg[[]],port,hms}
      {1,255,1,2,{{0,0,80,78}},D8,1504}, //hxch
      {1,255,1,2,{{0,0,75,71}},D7,1503}  //tankles
    }

No longer choosing cs idx by sr, now choosing cs by prg index

Trying to separate sensor readings and update from what happens after. You should just be able to check all your sensor values.


### 7/15/21  15-secstidef-CYURD200solar
secstidef stands for sensors, controlled sensors(like thermostats), timers and def(ault function) - the curent goal of modifying the code so it doesn't spin its wheels without the internet.

To compile copy the contents of CONFIG_CYURD200solar.cpp and .h files into CONFIG.h and CONFIG.cpp in the src directory of espBoth/secstidef/ then compile. 

I am using vscode with the platformio extension instead of the arduino gui.

To work for the solar project it needs to also work as a differential controller, ie comparing two sensors.

I put the pcb files in zKicad/esp8266v1. you would need to download kicad to mess with them

### 7/13/21 14a-ifnoWIFI

set `ConnWIFI.cpp/getOnline()wifiManager.setConfigPortalTimeout(120)`, after which it will drop out of `!wifiManager.autoConnect("connectEspAP")` and start running the main loop(). if !haywifi then mqtt won't try to connect. 

Without wifi, the defaults will take over. They are the values that are baked in in CONFIG.cpp.

The next day, shortly after midnight, when `main.cpp/dailyAlarm()getTime()` goes off, if !haywifi, the device will again attempt to getOnline().

When messing with wifi at parley https://myfiosgateway.com/#/login admin, sort332urn

### 7/13/21 14-solar
At the start of Tobin's solar project.

Allow microcontroller operation in the absense of wifi. Builds on code in secsti

<s> Allow microcontroller operation in the absense of wifi.</s> Builds on code in secsti

Changes:

sched.cpp 
* 155 - change 0 to i
* checkRelays - srs.cs[ici.idx] -> srs.cs[i]
reqs.cpp   
* rewrote Reqs::pubState(int hc)


cp src/CONFIG.cpp conf/CONFIG_CYURD117attic_hum.cpp
cp src/CONFIG.h conf/CONFIG_CYURD117attic_hum.h
cp src/CONFIG.cpp conf/CONFIG_CYURD118attic_htu.cpp
cp src/CONFIG.h conf/CONFIG_CYURD118attic_htu.h
cp src/CONFIG.cpp conf/CONFIG_CYURD004mbgh_htu-relay.cpp
cp src/CONFIG.h conf/CONFIG_CYURD004mbgh_htu-relay.h

cp src/CONFIG.cpp conf/CONFIG_CYURD126cascada.cpp
cp src/CONFIG.h conf/CONFIG_CYURD126cascada.h
touch conf/CONFIG_CYURD126cascada.json

### 10/17/20 13-test-MAX31855zanshin
again tried to get these chips to work,
works on this 
### 4/22/20 12-secsti-CUSTON_CODE
added CUSTOM CODE
* added function declarations `void customInit(); void customLoop();` and defined the functions in CONFIG.cpp
* added calls in `main.cpp` in `initShit()` and `loop()`


Implementing Cascada

Changes to secsti needed: dr (dependant relay)

* need the funtionality that makes ouput port hi whenever any of 3 other ports are hi else lo
* has no sensor related to it or timer running with it
* has no prog


### 4/10/20 11-secsti-req_pub

### 4/9/20 10-secsti-ddd
* modified `srs` data type to distinguish between `rec` - whether you want to record new values of this sensor and `isnew` to distinguish between newly sensed values and prg settings and just requests for srstate from apps

### 4/8/20 09-espbothREADME-incoming-outgoing_message_types-INNERworkings

#### device INCOMING Message topics `/devtime/req/cmd/prg/set`

##### from server (provides data)
- [x] /devtime `{dow,unix,LLLL,zone,mysql}` -> sched.deseriTime, sched.actTime()

##### from app 

req.desiriReq()
- [x] /req `{\"id\":0, \"req\":"srstates"}`->f.HAYsTATEcNG = 31;
- [x] /req `{\"id\":1, \"req\":"sched"}` -> req.pubPrg(31)
- [x] /req `{\"id\":2, \"req\":"flags"}` ->req.pubFlags()
- [x] /req `{"id\":3, \"req\":"timr"}`  ->req.pubTimr()

req.deseriCmd() alter schedule currently running (insert into srs) 
- [x] /cmd (cs) `{"id":${sr},"sra":[hilimit,lolimit]}`
- [x] /cmd (ti) `{"id":${sr},"sra":[onoff]}`

sched.deseriProg replace program on device
uses JsonArray$ ev.size() to distinguish cs/ti
- [x] /prg (ti) `{"id":sr,"pro":[[hr,min,onoff], [7,45,0]]}`
- [x] /prg (cs) `{"id":sr,"pro":[[hr,min,hilimit,lolimit], [7,45,68,66]]}`

only now used in /spa1/aapoj/paho2&pahoRaw
- [ ] /set `{"devid":"CYURD001", "owner":"tim@sitebuilt.net", "pwd":"gekkt", "mqtt_server":"sitebuilt.net", "mqtt_port":"1884", "sensor_type":""}`


#### device OUTGOING message topics `/time/srstate/flags/timr/sched`

##### to server 
sever returns `/devtime` and `/prg` messages 
- [x] /time `the time is being requested`

##### to app 
uses `[ici.type:[se=0,cs=1.ti=2], ici.idx:idx_in_type] = req.getTypeIdx(sr);`
- [x] /srstate (se,ti) `{\"id\":sr, \"darr\":[onoff/reading], \"new\":rec}`
- [x] /srstate (cs) `{\"id\":sr, \"darr\":[reading,onoff.hilimit,lolimit], \"new\":rec}`

req.pubFlags() RUNSon req or if (f.CKaLARM>0)
- [x] /flags  `{"aUTOMA":true,"fORCErESET":false,"cREMENT":5,"HAStIMR":28,"IStIMERoN":0,"HAYpROG":0,"HAYpROGcNG":31,"HAYsTATEcNG":31,"CKaLARM":0,"ISrELAYoN":3,"tIMElEFT":[0,0,0,0,0]}`

req.pubTimr() takes everthing from flag values <br/>
RUNSon req || if (f.CKaLARM>0) || if (f.IStIMERoN >0) after sched.updTimers(); || schedAdjRelay()
- [ ] /timr `{"cREMENT":5,"IStIMERoN":0,"ISrELAYoN":3,"tIMElEFT":[0,0,0,0,0]}`

req.pubPrg(f.CKaLARM) (should be pubSched()) uses prg_t prgs, req.creaJson(), req.clPub() (not sure alarmid is needed) <br/>
RUNSon req || if (f.CKaLARM>0) 
- [x] /sched `{id:sr, aid:alarmid, ev:#ofeventsinday, numdata:cshilo/tionoff, pro:[[hr,min,onoff], [hr,min,hilimit,lolimit]] }`

#### INNER WORKINGS: f.CKaLARM
Causes the inital publication of a prg and initial publications of /timr. But more importantly it causes sched.ckAlarm() to run which set up the state to curr and sets and alarm to run until the next schedule event. After it does what it need to do in loop then clears f.CKaLARM
* in req.processIncoming /devtime it is set to 31
* if (f.CKaLARM>0) triggers req.pubPrg(f.CKaLARM) and req.pubTimr() in mail loop
* is set in sched.deseriProg on a /prg message from app or server
* sched.ckAlarms() updates prg based for (f.CKaLARM & 2) == 2)
* gets cleared (unset) in loop after it does what it causes to be done `f.CKaLARM=f.CKaLARM & 0;` sets everything to zero
* gets set in bm8() f.CKaLARM=f.CKaLARM | 8; Callback of timer resets program to next event

#### INNER WORKINGS: sched.ckAlarm() (shold be move2nextPrgEvent())
Instantiates a new program event. It runs when a new /prg message comes in or when a alarm finishes. 
* frees existing alarm and sets a new one
* changes current srs data for
  * (cs) by 
    * updating current srs (state) hilimit & lolimit from prg, 
    * sched.adjRelay() based on new cur, 
    * sets HAYsTATEcNG, 
    * sets alarmOnce() til next and gives it a callback to run when it is over
  * (ti) by 
    * updating current srs (state) onoff from prg, 
    * set f.ISrELAYoN flag if state is on
    * sched.setTleft(*p, cur, nxt, tleft); and sets f.IStIMERoN. Eventually sets f.tIMElEFT which doesn't control anything, and is just an approximation to publish to apps
    * sets alarmOnce() til next and gives it a callback to run when it is over

#### REWRITE hurdles TODO
The biggest obvious hurdle would be not to have a sched.ckAlarms with a specific callback meaning you have to hard code for each device setup or some general endless ifelse for all possible future device setups. https://forum.arduino.cc/index.php?topic=421834.0 has a possible solution. On every run through ckAlarms the alarmId can be connected to an srid. 

    struct aidsr_t {
      int:endtime; //maybe hr*600+min*10+srid
      int:sr;
      AlarmID_t aid;
    }
    struct srthm_t{
      aidsr_t aidsr[6]
    }
    
    extern srthm_t aids;

Then each time you start and alarm you can add the endtime,sr,aid to aids and then sort it https://www.youtube.com/watch?v=W4A_PxSXO1E so the next alarm that ends is on top. Then inside the cb() you can pop of the top of aids and reset f.CKaLARM for that (cs or ti).

To sort maybe I need to initalize  all the endtime to be bigger than 24*60 so that they never are on top?

?????? What if the device is scheduled to do more than one thing at a particular time? you could get the wrong srid and reschedule that srid but would you lose the other one? ANS: maybe the callback would run and the next callback will run when that one finishes. that would be good. OR ELSE DON'T SCHEDULE SR EVENTS ON A DEVICE TO RUN AT THE SAME MINUTE. Maybe that is already taken care of in ckAlarms()

    int asec = second()+id;        
    p->aid = Alarm.alarmOnce(p->prg[nxt][0],p->prg[nxt][1], asec, bm2);

### 4/7/2020 08-secsti
New codebase for esp8266 microcontrollers, should also work on esp32.

Built in `espBoth/multisensor` sensor only, no relay code. Expanded the srs data of CONFIG.h type to

        struct se_t {//sensors
          int sr;
          int reading;
          int rec;
        };
        struct cs_t {//controlled sensors
          int sr;
          int reading;
          int onoff;
          int hilimit;
          int lolimit;
          int rec;   
        };
        struct ti_t {//timers
          int sr;
          int onoff;
          int rec;   
        };
        struct srs_t {
          int numse;
          se_t se[5];
          int numcs;
          cs_t cs[1];
          int numti;
          ti_t ti[2];
        };
        extern srs_t srs;

which covers all cuurent configutation se - sensor only, cs - controlled sensor, ti - just a timer .  `main.setSrs()` distinguishes between se and cs, witing the reading to the right place and calling `sched.adjRelay()` for controlled sensors. `main.setIfDif()`  sets the sensitivity of the sensor, determining how big a change warrants publishing.   

`req.pubState()` uses `getTypeIdx(sr)` to find which srs type to read from and which local idx holds that sensors data.



### 3/29/20 07-multisensor-pubState
All sensors except max31855 working and publishing

### 3/28/20 05-multisensor-CONFIG
constant values you need access too in multiple files are best declared in a .h file ex: `struct sen_t { .... };, extern const sent_t SE;` then intialized or set in a .cpp file  ex: `const labels_t la {
  {"devtime", "cmd"},2};`

TODO - publish from the device, the current state of the sensors. PROBLEM - App is used to seeing state data from sensors with [64, 0, 68,59] even if there is no hilimit or lolimit or state.


### 3/27/20 04-multisensor-processInc_devtime
SOFAR - Added enough of `Regs.h` and `Reqs.cpp`  ans `Sched.h` and `Sched.cpp` to allow it to process incoming devtime request and set the device. THIS IS WHERE `ArduinoJson` starts to get used but left it at version 5.14.0.

Incorporated a couple of Sched member functions to respond to the handleCallback function that mqtt uses when something comes in. When something does come in the raw data is put into itopic and ipayload and then the NEW_MAIL flag is set. The main loop picks up the flag and processesIn(oming) message wheter it be {"devtime", "cmd", "prg", "req", "set", "progs"} and sched.actTime()case 0 is devtime which calls sched.deseriTime() 

weird shit: 

### 3/25/20 03-multisensor-MAX31855
SOFAR - Cannot get MAX31855 to work as sensor. Probably problem with the board

DOES NOT WORK

The SPI Interface uses 4 lines for data exchange:

* SCLK-Serial Clock: Clock signal (from lead) Ot
her designations: SCK, CLK
* MOSI-Master Output, Slave Input: Data from leading to Vedomo
mudrugie notation: SDI, DI, SI
* MISO — Master Input, Slave Output: Data from the Vedushhemudrug
ie-driven notation: SDO, do, SO
* SS-Slave Select: Slave selection; is established by the
Other designations: nCS, CS, CSB, CSN, nSS, STE

MAX 31855 still not working  (probably board problem not SPI) though Nokia 5110 SPI display does (in test)

* CLK - > D5(14)SCK
* CS  ->  D8(15)SS
* D0  ->  D6(12)MISO
### 3/24/20 02-multisensor-mq
SOFAR - Moved light code to multsensors and added some sensors as well as `MQclient.h` and `MQclient.cpp` and added db entries so the device could connect to the mqtt broker. `MQclient.cpp` makes a proper request to the broker for the proper time and the broker hears it.

* CONST.h to set up a device. trying to allow processing of input by stepping through arrays
* Leaving build flags D in platfromio.ini
* mq works but maybe should not be sticking with ArduinoJSON 5.13 as I move on
* sensors working so far 
    * BH1750 light sensor. Light sensor id sn i2c device. 
    * DS18B20 onewire temp sensor. Can have multiple banks of multiple sensors
    * DHT11/22 remember dht.begin()
    * hygrometer uses analog A0 constrain and map

### 3/21/20 00-light+config
SOFAR - Added `config.h` and `config.c` to run the code to connect to WIFI

### 3/20/20 00-light
SOFAR - just sensors working without internet using a new `CONST.h` as a config file, now being able to iterate through it in `redSensors()`

^REBUILDING THE CODEBASE^