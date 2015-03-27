/*
* ADT7310.h
*
* Created: 24/02/2015 19.35.31
*  Author: xmas79
*/

#ifndef ADT7310_H_
#define ADT7310_H_

namespace ADT7310
{
	enum OperationMode
	{
		Continuous =	0x00,
		OneShot =		0x20,
		OneSPS =		0x40,
		Shutdown =		0x60
	};
	
	enum Resolution
	{
		Bits13 =		0x00,
		Bits16 =		0x80
	};
	
	const uint8_t statusRegister = 0x00;
	const uint8_t configurationRegister = 0x01;
	const uint8_t temperatureRegister = 0x02;

	template<typename T>
	class ADT7310Driver : public T
	{
		public:
		void SetMode(OperationMode mode, Resolution resolution)
		{
			uint8_t command = 0x00 + (configurationRegister << 3);
			uint8_t value = mode + resolution;
			
			this->PrepareSPI();
			this->SelectDevice();
			
			// Write command byte
			this->SPISend(command);
			
			// Write register value
			this->SPISend(value);

			this->DeselectDevice();
		}
		int16_t ReadTemperature()
		{
			uint8_t command = 0x40 + (temperatureRegister << 3);
			
			this->PrepareSPI();
			this->SelectDevice();
			
			// Write command byte
			this->SPISend(command);
			
			// Read register value
			int16_t value = (int16_t)((((uint16_t)this->SPISend(0xff)) << 8) | ((uint8_t)this->SPISend(0xff)));

			this->DeselectDevice();
			
			return value;
		}
		void Reset()
		{
			this->PrepareSPI(); 
 			this->SelectDevice();
			
			// Write 0xff to reset temp sensor
			for (uint8_t i = 0; i < 8; i++)
				this->SPISend(0xff);
			
			_delay_ms(1);

			this->DeselectDevice();
		}
	};
}

#endif