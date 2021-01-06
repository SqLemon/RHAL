# RHAL for STM3F103C8T6

The RHAL (Robotics Hardware Abstraction Layer) is created with the purpose of simplifying the use of the STM32F103C8T mounted on the prototyping board "blue-pill"

The functions were made to optimize the amount of code loaded into the chip while still maintaining simple and easy to use functions. This is improved with the use of C++. Different objects where created for the use of the embedded system peripherals.

## Pin objects

For every object in this list, the parameters PORT and PIN can be replaced with the defines "BLUEPILL_PA1" (changing PA1 for the desired pin) .

#### OutputPin(PORT, PIN, MODE = PUSH_PULL).

`OutputPin(Port::PORTA, 6, Mode::PUSH_PULL);`

mode can be PUSH_PULL or OPEN_DRAIN. In this particular case, the last parameter is redundant. 


#### InputPin(PORT, PIN, MODE = PULDOWN)

`InputPin(Port::PORTA, 6, Mode::PULLUP);`

mode can be PULLUP, PULLDOWN, FLOATING or ANALOG.


#### AlternativePin(PORT, PIN, MODE = PUSH_PULL

`AlternativePin(Port::PORTA, 6, Mode::OPEN_DRAIN);`


## Hardware Timer Objects

PWM

ENCODERS

(to be developed)
