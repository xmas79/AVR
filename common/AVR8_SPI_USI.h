/*
 * AVR8_SPI_USI.h
 *
 * Created: 25/02/2015 14.28.57
 *  Author: xmas79
 */ 

#ifndef AVR8_SPI_USI_H_
#define AVR8_SPI_USI_H_

namespace AVR8
{
	class AVR8_SPI_USI
	{
	public:
		inline void PrepareSPI(){};
	
		inline uint8_t SPISend(uint8_t cData)
		{
			USIDR = cData;
			USISR = (1 << USIOIF);
			do 
			{
				USICR = (1 << USIWM0) | (1 << USICS1) | (1 << USICLK) | (1 << USITC);
			}  while ((USISR & (1 << USIOIF)) == 0);
			
			return USIDR;
		};
	};
}

#endif