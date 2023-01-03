# if no hay wifi

set `ConnWIFI.cpp/getOnline()wifiManager.setConfigPortalTimeout(120)`, after which it will drop out of `!wifiManager.autoConnect("connectEspAP")` and start running the main loop(). if !haywifi then mqtt won't try to connect. 

Without wifi, the defaults will take over. They are the values that are baked in in CONFIG.cpp.

The next day, shortly after midnight, when `main.cpp/dailyAlarm()getTime()` goes off, if !haywifi, the device will again attempt to getOnline().

When messing with wifi at parley https://myfiosgateway.com/#/login admin, sort332urn