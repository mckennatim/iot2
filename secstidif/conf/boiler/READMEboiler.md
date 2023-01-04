# secsti - SEnsors, Controlled Sensors, TImers 
based on esp device that can have sesnors, controlled sensors and timers

## boiler

    /*DESCRIPTION
    Boiler
    hay 2 temp sensors
    hay 1 input to detect 5v when fan is on
    hay 1 relay to handle outdoor reset
    CONFIG_boiler running on espboth/secsti
    has CUSTOM CODE
    */

    /*LOCID 12ParleyVale
    */

When fan is on srstate should say so and it should get recorded to database.

### how does outdoor reset get simulated?
An aquastat is a device used in hydronic heating systems for controlling water temperature. To prevent the boiler from firing too often, aquastats have a high limit temperature and a low limit. If the thermostat is calling for heat, the boiler will fire until the high limit is reached, then shut off (even if the thermostat is still calling for heat). The boiler will re-fire if the boiler water temperature drops below a range around the high limit. The high limit exists for the sake of efficiency and safety. The boiler will also fire (regardless of thermostat state) when the boiler water temperature goes below a range around the low limit, ensuring that the boiler water temperature remains above a certain point. The low limit is intended for tankless domestic hot water---it ensures that boiler water is always warm enough to heat the domestic hot water. Many aquastats also have a differential ("diff") control which determines the size of the range around the "low" and/or "high" controls.

https://terrylove.com/forums/index.php?threads/outdoor-reset-controls-worth-it.41510/

https://forum.heatinghelp.com/discussion/143596/outdoor-reset-vs-thermostat-setback

When it is cold outside the boiler shouldn't be messed with.

When schedule changes and the temp needs to recover asap, the boiler shouldn't be messed with.

When it is warm outside and the house temp in near the setpt, the boiler should stop calling for heat (tstat open) once the water temp reaches (set of) particular value(s) The circulator should continue. For example, on a warm day the boiler would turn off once the watrer reaches say 150 degrees. The tstat might still be calling for heat. Once the temperature goes down 
