/*
 * AVR8_SPI.h
 *
 * Created: 25/02/2015 14.26.48
 *  Author: xmas79
 */ 

#ifndef AVR8_SPI_H_
#define AVR8_SPI_H_

#include <avr/io.h>

namespace AVR8
{
	class AVR8_SPI
	{
	public:
		__attribute__((always_inline)) void PrepareSPI(){};
			
		inline uint8_t SPISend(uint8_t cData)
		{
			SPDR = cData;
			loop_until_bit_is_set(SPSR, SPIF);
			return SPDR;
		};
	};
}

#endif 