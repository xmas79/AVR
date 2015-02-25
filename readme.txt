This is a drivers collection library for 8-bit AVR microcontrollers. It provides high level drivers for 
some devices I used:
- ADT7310 (Analog Devices), temperature sensor on SPI bus.
- MRF24J40 (Microchip), an IEEE 802.15.4 Transceiver on SPI bus.

The library has been designed with ease of coding AND performance in mind. This is the main reason why 
drivers are implemented as C++ templates.

Each driver makes use of some "generic" functionalities. In particular, each driver has been decoupled 
from the SPI bus management. In addition, the SPI bus management is decoupled from the CS signal management. 
This allows to target different AVRs with different hardware capabilities. In particular, three SPI 
implementations are provided:

SPI Interface:

- Hardware SPI for ARVs. This is the interface that allows AVRs with hardware SPI peripherals to take 
  care of SPI communication. It uses the SPDR register.
- Hardware USI for AVRs. This is the interface that allows AVRs with hardware USI peripherals to take 
  care of SPI communication. It uses the USICR register.
- Software bitbang. MISO, MOSI, SCK signals are fully configurable.

See below for instantiation examples.


CS signal management

CS signal is fully configurable. See below for instantiation examples.



Advantages over simple constructors:

Constructors are powerful "configuration" patterns. It could allow to instantiate different drivers 
with different port/pin configurations. However, the port/pin mapping is done at runtime. As an example, 
suppose you have the CS signal at Port A / Pin 7. A constructor "toy" example could be:

volatile uint8_t *CS_PORT;
uint8_t CS_PIN;
ADT7310::ADT7310(volatile uint8_t *cs_port, uint8_t cs_pin)
{
	CS_PORT = cs_port;
	CS_PIN = cs_pin;
}
and then the typical following statements would be used to set high/low the CS signal:
CS_PORT |= (1 << CS_PIN); // Set high CS
CS_PORT &= ~(1 << CS_PIN); // Set low

These instructions would be compiled as: 
1. load 0x01 into one register (say R24)
2. load CS_PIN value into another register (say R25)
3. left shifts of the R24 
4. decrement R25
5. go to ste 3 until R25 is zero
This is quite inefficient. The problem lies in the fact that the code cannot be optimized more than this 
since the CS_PIN value is only known at runtime. 

Conversely, templates allow both CS_PORT and CS_PIN value to be known at compile time, and the same code 
can be optimized to simple sbi/cbi instructions, with huge speed/flash gains.


Advantages over inheritance and virtual functions:

Inheritance is another powerful and flexible technique. However, it introduces the virtual tables, and the 
compiled code is usually big and inefficient because of indirect calls and table lookups, even if from the 
programming point of view seems elegant.

But, once again, knowing everything about a class allows the compiler to best optimize the code.




Instantiation examples

ADT7310 driver with hardware SPI:

#include "AVR8_CS.h"
#include "AVR8_SPI.h"
#include "ADT7310.h"

using namespace ADT7310;

const int CS_PORT = _SFR_IO_ADDR(PORTA);
ADT7310Driver<AVR8_CS<AVR8_SPI, CS_PORT, 7> > temp_sensor;

and then use it as usual:

int16_t temp = temp_sensor.ReadTemperature();

the instantiation line reads as follow:

"I want the ADT7310Driver, which is 'Chip Selectable' at port 'CS_PORT' (which is defined as port A) 
and 'pin 7', and has the SPI hardware interface".

The same driver can be instantiated with USI hardware by simply changing AVR8_SPI with AVR8_SPI_USI:

ADT7310Driver<AVR8_CS<AVR8_SPI_USI, CS_PORT, 7> > temp_sensor;



A more complex instantiation pattern is the bitbang interface:

ADT7310Driver<AVR8_CS<AVR8_SPI_BITBANG<OUT_PORT, 6, IN_PORT, 5, CLOCK_PORT, 4, SPI_MODE_3>, CS_PORT, 7> > tempSensor;


It can be read as:

"I want the ADT7310Driver, which is 'Chip Selectable' at port 'CS_PORT' (which is defined as port A) and 'pin 7', 
and has the SPI software interface configured as follow: MOSI is at OUT_PORT pin 6, MISO is at IN_PORT, pin 5, 
SCK is at CLOCK_PORT pin 4, and the SPI bus should be configured as mode 3".

