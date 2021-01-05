# RHAL for STM3F103C8T6

The RHAL (Robotics Hardware Abstraction Layer) is created with the porpouse of simplifying the use of the STM32F103C8T mounted on the prototyping bord "blue-pill"

The functions were maid to optimize de amount of coude loaded into the chip while still maintaining simple and easy to use functions. This is imporoved with the use of C++. Diferent Objects where created for the use of the embeded system peripherals.

## Pin objects

For every object in this list the parameters PORT, PIN can be reeplaced with de defines "BLUEPILL_PA1" (changing PA1 with the desired pin) .

#### OutputPin(PORT, PIN, MODE = PUSH_PULL).

`OutputPin(Port::PORTA, 6, Mode::PUSH_PULL);`

mode can be PUSH_PULL or OPEN_DRAIN. In this particular case, the last parameter is roduntant. 


#### InputPin(PORT, PIN, MODE = PULDOWN)

`InputPin(Port::PORTA, 6, Mode::PULLUP);`

mode can be PULLUP, PULLDOWN, FLOATING or ANALOG.


#### AlternativePin(PORT, PIN, MODE = PUSH_PULL

`AlternativePin(Port::PORTA, 6, Mode::OPEN_DRAIN);`


## Hardware Timer Objects

PWM

ENCODERS

(to be developed)
