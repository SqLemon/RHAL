RHAL - for blue pill
====================

RHAL is a collection of  C++ functions that lets you control the stm32f103c8 chip. 

##Its main objective is to serve as a base platform for robotics development that needs too be simple but efficient.
Supported functionalities are:

- GPIO
  - inputs with pullup and pulldown
  - outputs with pushpull and opendrain modes
- Hardware timers
  - Timers interrupts
  - PWM
  - Encoder interface
- Software timers
- ADC
- External interrupts
- Hardware encoder implementation

Installing RHAL in your project
-------------------------------

RHAL is over a CMSIS framework. We recomend the useage of "Platform.io". The library can be downloaded from platformio's library manager.

In case you decide to install it manualy, you can download and extract this project and the installing runing the following code in a terminal.

`pio lib install C:\your-path`

If the header files are not being recognized by intellisence, you coud press *ctrl+shift+P*  to open visualStudio options and then run "PlatformIO: rebuild intellisence index"

UsageUsage
