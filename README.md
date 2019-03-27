## Ghettorista ##

A DIY coffee machine controller aimed to help with fine tuning coffee
extraction.
This tools is mostly dedicated an mastering HX temperature and cooling flush.
It can be used to fine tune boiler temperature and operation with a PID.

### Features ###

#### Common features ####

- [ ] Detection of pump operation
- [ ] Trigger pump operation (cooling flush)
- [ ] Stopwatch for cooling and extraction monitoring
- [ ] Data export to time series database or mqtt

#### HX related features ####

- [ ] Temperature monitoring of group head
- [ ] Temperature offsetting to estimate water flow temperature

#### Single Boiler/Rossi related features ####

- [ ] Monitor boiler temperature
- [ ] PID controller for the heating element
- [ ] Post steam flush to cool to brewing temperature
