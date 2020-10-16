describe how you think an example embedded system device works and what design challenges it presents:

i am looking at my coffee maker and how it could potentially be a simple embedded system device:
* single/specific functionality: makes coffee* time sensitive: it has an automatic timer/clock and response time to turn on and off
* limited hw resources: simple computing and clock device with sensors 
* no human interaction/intervention: once set, it automatically functions turning on and off

the operation of the embedded system would mostly be clock based. a scheduled 'on' time is set and then once 'on' a duration is monitored to determine when it turns 'off'. it most likely also has a sensor to determine if the temperature of the coil has gone above 100c indicating all of water has boiled away and now the coil temperature is rising as a result triggering the system to remove power from the heater coil. a design challenge could be response time, removing power fast enough as to not have temperatures get to high.     
