#include "CONFIG.h"
/*CONFIG_CYURD117attic_hum.cpp
INSTRUCTIONS
* be sure to modify FLAGS for HAYpROGS and HAYtIMRS
*/

/*CUSTOM CODE
Transformer D8 activated when either D5,D6 or D7 hi
srs.ti[0] (sr 0) onoff for D5
srs.ti[1] (sr 1) onoff for D6
srs.ti[2] (sr 2) onoff for D7
(see srs.ti_t and prgs.prg_t)
otherwise make some DUMMY custom function
*/
void customInit(){
  if(0==1){
    int dog =3;
  }
};
void customLoop() {
  if(0==1){
    int dog =3;
  }
};
 
// void customInit(){
//   pinMode(D8, OUTPUT);
//   digitalWrite(D8, HIGH);
// }
// void customLoop(){
//   int bef = digitalRead(D8);
//   if(srs.ti[0].onoff==1 || srs.ti[1].onoff==1 || srs.ti[2].onoff==1){
//     digitalWrite(D8, HIGH);
//   }else{
//     digitalWrite(D8, LOW);
//   }
//   int aft = digitalRead(D8);
//   if(aft != bef){
//     Serial.print("D8 is ");
//     Serial.println(aft);
//   }
// }


/*DESCRIPTION
master bedroom  greenhouse @ 12ParleyVale with 
HTU21D temp humidity sensor & timer/relay
CONFIG_CYURD004 running on espboth/secstidif
has no CUSTOM CODE
*/

/*LOCID 12ParleyVale
*/


/*SERVER
dev extern device variables*/
bool haywifi=true;
char devid[9]="CYURD004";
char owner[254]="tim@sitebuilt.net";
char pwd[24]="geniot";
char mqtt_server[60]="sitebuilt.net";
char mqtt_port[6]="1884";
/*dev*/

/*SPECS
CONFIG extern const device variables
INCOMING const mqtt topics*/
const topics_t TPC {
  5,
  {"devtime", "cmd", "prg", "req", "set"}
};
/*PORTS for INPUT*/
const portsin_t inpo {
  0, //DS18b20a
  0, //DS18b20b
  0, //DHT11
  0, //ANALOG
  0, //SPIdo
  0, //SPIcs
  0};//shares i2c D2 and D1
/*SE constant declarations*/  
const sen_t SE {
  1,//numtypes of different sensor types
  2,//numsens number of sensors
  {//senso_t stype: {nums,ids,type,model htu is i2c}
    {2, {0,1}, "temp-hum", "HTU21D"}
  }
};
/*------------------------------------------------------
CONFIG extern structures (initial values, changeable)*/
/*srs extern data structure initalization
state of relays and sensors */ 
srs_t srs {
  2,//numsr (se+cs)
  2,//numse of just sensors
  {{0,29,1,0},{1,18,1,0}},//se_t {{sr,reading,rec,isnew}}
  0,//numcs
  {//cs:{sr,reading,onoff,hi,lo,isnew}
  }, 
  1,//numti
  {{2,0,1,0}},
  0,//numdi difference control
  {}
};
/*prgs extern data structure initalization*/ 
prgs_t prgs{
  1,//numprgs
  //prg: {sr,aid,ev,numdata,prg[[hr,min,max,min]],port,hms}
  {{2,255,1,1,{{0,0,0}},D6,1504},}
};
/*flags extern data structure*/
flags_t f {//MODIFY HAYpROG and HAStIMR
  0,//aUTOMA
  0,//fORCErESET
  5,//cREMENT
  0,//HAStIMR 00000111 =1+2+4=7
  0,//IStIMERoN
  3,//HAYpROG 00000011 =1+2+4=7
  1023,//HAYsTATEcNG
  0,//CKaLARM
  0,//ISrELAYoN
  {0,0,0,0,0,0,0,0,0,0}//tIMElEFT[10]
};

// nxtalarr_t nxtal {
//   0,//num
//   {//sr,aid,hms (h*60+m)*20+sr
//     {0,255,29000},
//     {1,255,29000},
//     {2,255,29000},
//     {3,255,29000},
//     {99,255,29001},
//     {99,255,29002},
//     {99,255,29006},
//     {99,255,29004},
//     {99,255,29000},
//     {99,255,29000}
//   }
// };
    

// const srpos_t outpos {
//   3, //numpos
//   {{2,D0}, {7,D3}, {8,D4}} //pod.sr,pod.portnum
// };
