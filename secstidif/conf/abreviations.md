# abreviation

## sensors

- htu: [HTU21D temp and humidity sensor](https://www.adafruit.com/product/1899) 
- DS18B20: [DS18B20 1-wire thermometer](https://www.analog.com/media/en/technical-documentation/data-sheets/ds18b20.pdf)
- DHT11 DHT12: [DHT11 DHT12 AM2302 temp/hum sensors](https://learn.adafruit.com/dht)

## structs and mqtt 
srs
- sr: sesnor or relay ID
- se: sensors only, not controlling relays
  - {sr, reading...}
- cs: relays controlled by sensors
  - {sr, reading, onoff, hilimit, lolimit...}
- ti: relays controlled by timers
  - {sr, onoff...}
- di: difference controller  
- numsr: total number of sensors and relays
- numse: number of sensors (not controlled)
- numcs: number of sensors operating relays
- numti: number of relays on timers
- numdi: number of difference controllers, each has a relay
- srs: structure holding all of the above information

prgs
- prg: a day's program for a particular relay
  - ev: a day's program has a number of events. 
  - prg[11][4]: 11 represents the max # of events allowed/allocated. 4 represents the maxdata allowed/allocated for each event Each event happens at an [hr,min ...]. Besides hr,min, the event can either turn a relay onoff [hr,min,onoff] or it can set a min/max or hilimit/lowlimit [hr,min hi, lo] for a sensor&relay
  - numdata: can be  either 1 or 2. 1 means [hr,min,onoff], 2 means [hr,min,hi,low]
- prgs: structure holding all the prg's operating on relays or senor&relay
  - numprgs: how many prg operating on relays or sensors&relays 
  - prg[numprgs]: an array of multiple prg
