/*
 * AVR8_CS.h
 *
 * Created: 25/02/2015 14.20.01
 *  Author: xmas79
 */ 

#ifndef AVR8_CS_H_
#define AVR8_CS_H_

#include <avr/io.h>

namespace AVR8
{
	template<typename T, uint8_t CS_PORT, uint8_t CS_PIN>
	class AVR8_CS : public T
	{
	public:
		__attribute__((always_inline)) void SelectDevice() { _SFR_IO8(CS_PORT) &= ~_BV(CS_PIN); };
		__attribute__((always_inline)) void DeselectDevice() { _SFR_IO8(CS_PORT) |= _BV(CS_PIN); };
	};
}

#endif 