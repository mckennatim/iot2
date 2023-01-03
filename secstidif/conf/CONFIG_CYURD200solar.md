# CONFIG_CYURD200solar

ESP8266 ctrl (ectrl)

The ectrl has 3 temperature sensor inputs and 4 relay outputs (125V 15 A). 

* solar relay 0 (SR) fires depending on the difference between sensor 0(STS) and sensor 1(TTS), which tunrs on the solar pump and primary pump
* heatxchng relay 1 fires depending on hilimit THI and lolimit TLO of sensor 1 (TTS)
* tanklessBypass relay 2 fires depending on hilimit TLHI and lolimit TLLO of sensor 1 (TTS)

It will also have programmable setpoints for minimum tank  temp TLO, maximum tank temp THI, cooling solar temp SLO, tank temp tankless bypass hilimit TLHI and lolimit TLLO,  and maybe others. 

Every 10 seconds it will read STS and TTS. 

If solar temp STS > TTS then solar relay SR goes on. This turns on solar pump SP and primary pump PP.
Else if 
If tank temp TTS > THI then don't turn on solar pump

If Tank Temp TTS < TLO activate the tank temp relay TTR. If the zone valve ctrl ZVR106 is calling for heat the combination will activate the heat exchanger pump to add heat tankless heat to the heating circuit.

If tank temp TTS < TLO activate tankless bypass diverter relay TLBDR. Then any call for DHW will draw hot water from the tankless otherwise it will draw from the tank.
If tank temp TTS > TLO + TLDIFF deactivate tankless bypass relay so DHW will be drawn from tank.