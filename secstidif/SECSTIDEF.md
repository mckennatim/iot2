# secstidef - Sensors, Controlled Sensors, Timers: Default operation without WIFI

7/13/21

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