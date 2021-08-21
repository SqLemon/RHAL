# RHAL - for blue pill

RHAL is a collection of  C++ functions that lets you control the stm32f103c8 chip.

## Description 📋

RHAL's main objective is to serve as a base platform for robotics development that needs too be simple but efficient.
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
- External interrupts (pending)
- Hardware encoder implementation (pending)

## Getting started 🚀️

### Dependencies

RHAL is based on the CMSIS framework. We recomend the usage of "Platform.io", but you can use any IDE that supports this framework

### Installation

- **PlatformIO**
  - you can directly download the library from platformio's library manager.
- **Direct download**
  - In case you decide to install it manualy, you can download and extract this project in any folder and the install it runing `pio lib install C:\your-path` in a PIO terminal

## Usage ⚙️

Once you have RHAL installed in your project, proceed to create a *main.cpp* file like the follownig.

```c++
#include <RHAL.h> //this includes the hole library

void main(){
    RHAL Rhal; //<!> needed for initialization
  
    while(1){
      /*
        updates system flags. 
        And optional function pointer con be passed for execution every 1 ms
      */
      Rhal.tick();
    }
}
```

**there are examples for the different modules in the [examples](https://github.com/SqLemon/RHAL/tree/main/examples) folder.**

## Authors ✒️

* Damián Melamed [@damimela]
* Ianick Noejovich [@iakanoe]

## License 📄

Copyright 2021 SquareLemon

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
