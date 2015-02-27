/*
 * SPI_Bitbang.h
 *
 * Created: 24/02/2015 19.37.32
 *  Author: xmas79
 */ 

#ifndef SPI_BITBANG_H_
#define SPI_BITBANG_H_

#include <avr/io.h>

namespace AVR8
{
	enum SPI_MODE
	{
		SPI_MODE_0 = 0,
		SPI_MODE_1 = 1,
		SPI_MODE_2 = 2,
		SPI_MODE_3 = 3
	};
	
	template<uint8_t OUT_PORT, uint8_t OUT_PIN, uint8_t IN_PORT, uint8_t IN_PIN, uint8_t CLOCK_PORT, uint8_t CLOCK_PIN, enum SPI_MODE SPI_mode>
	class AVR8_SPI_BITBANG
	{
		public:
		__attribute__((always_inline)) void SetClockLineHigh() { _SFR_IO8(CLOCK_PORT) |= _BV(CLOCK_PIN); }
		__attribute__((always_inline)) void SetClockLineLow() { _SFR_IO8(CLOCK_PORT) &= ~_BV(CLOCK_PIN); }
		__attribute__((always_inline)) void SetOutputLine(bool high) { _SFR_IO8(OUT_PORT) &= ~(_BV(OUT_PIN)); if (high) _SFR_IO8(OUT_PORT) |= _BV(OUT_PIN);};
		__attribute__((always_inline)) uint8_t GetInputLine() { return (_SFR_IO8(IN_PORT) & _BV(IN_PIN)) ? 0x01 : 0x00; }
		__attribute__((always_inline)) void PrepareSPI() 
		{  
			switch (SPI_mode)
			{
				case SPI_MODE_0:
				case SPI_MODE_1:
					_SFR_IO8(CLOCK_PORT) &= ~_BV(CLOCK_PIN);
					break;
				case SPI_MODE_2:
				case SPI_MODE_3:
					_SFR_IO8(CLOCK_PORT) |= _BV(CLOCK_PIN);
					break;
			}
		};

		inline uint8_t SPISend(uint8_t cData)
		{
			switch (SPI_mode)
			{
				case 0:
					// Loop through all 8 bits
					for (uint8_t i = 0; i < 8; i++)
					{
						// Data change phase

						// Set output
						this->SetOutputLine(cData & 0x80);
				
						// Sampling phase
						this->SetClockLineHigh();

						// Read input bit, prepare next output bit
						cData = (cData << 1) | this->GetInputLine();
				
						// Data change phase
						this->SetClockLineLow();
					}
					return cData;
					
				case 3:
					// Loop through all 8 bits
					for (uint8_t i = 0; i < 8; i++)
					{
						// Data change phase
						this->SetClockLineLow();
				
						// Set output
						this->SetOutputLine(cData & 0x80);
				
						// Data sampling phase
						this->SetClockLineHigh();
				
						// Read input bit, prepare next output bit
						cData = (cData << 1) | this->GetInputLine();
					}
			
					return cData;
			}
		}
	};
}

#endif