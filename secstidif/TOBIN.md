ESP8266 ctrl (ectrl)

(if we cant find solar control with dry contact relays)

The ectrl has 2 temperature sensor inputs and 4 relay outputs (125V 15 A). 

It will also have programmable setpoints for minimum tank  temp TLO, maximum tank temp THI, cooling solar temp SLO, tank temp tankless bypass differential TLDIFF(maybe the same as THI),  and maybe others. 

Every 10 seconds it will read STS and TTS. 

If solar temp STS > TTS then solar relay SR goes on. This turns on solar pump SP and primary pump PP.
Else if 
If tank temp TTS > THI then don't turn on solar pump

If Tank Temp TTS < TLO activate the tank temp relay TTR. If the zone valve ctrl ZVR106 is calling for heat the combination will activate the heat exchanger pump to add heat tankless heat to the heating circuit.

If tank temp TTS < TLO activate tankless bypass diverter relay TLBDR. Then any call for DHW will draw hot water from the tankless otherwise it will draw from the tank.
If tank temp TTS > TLO + TLDIFF deactivate tankless bypass relay so DHW will be drawn from tank.


So here is the deal as far as my involvement is concerned. I'd like to help, it seems you could use my help. It is ambitious project and as project leader you need to keep your people (me) in a position where they can successfully contribute. Your message to me was more than a month ago and as of today the control narrative exists only as crappy bullet points, the design merely pile of contradictory scrap paper. As a busy guy you are virtually unresponsive to your team (me) on this. There is a lot that I could have done by now and both you and I are running out of time. 

I don't even like doing circuit and software design in the summer. I'd rather be in the garden. Or on my boat or riding waves. And I will be on Friday as the heat returns. Next week we are on vacation on the cape. 

Every time I built a house or other project I wanted to be sure there were no mistakes mostly because I wanted to sleep at night. This thing is way sketchy. Perhaps I should pull out. 

Here is the ultimatum part: Real plans and a bullet proof narraitve in 24 hours else you are on your own.