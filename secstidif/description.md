## explanation of the design

Since both cs a ti's have an associated program, why do they need hilimit/lolimit or onoff in the srs structure?

Because it is the place that stores the the current values. 

## what happens in the loop

During the loop a message could come in from the outside. Or there could be a change in one of the sensor values. Or a running timer can display its progress or could reach the end of its run. Or it might be time to change a program. Or check the difference controller or custom code.

Sensors are read every loop. readSensors() calls setIfDif() which sets HAYsTATEcNG. 

Loop watches for HAYsTATEcNG, runs pubState() if it is >0.