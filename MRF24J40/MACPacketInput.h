/*
 * MACPacketInput.h
 *
 * Created: 01/03/2015 21.27.49
 *  Author: xmas79
 */ 

#ifndef MACPACKETINPUT_H_
#define MACPACKETINPUT_H_

class MACPacketInput
{
public:
	uint8_t payloadLength;
	uint16_t destinationAddress;
	uint16_t sourceAddress;
	uint8_t lqi;
	uint8_t rssi;
	char *payload;
	
	__attribute__((always_inline)) MACPacketInput(uint8_t len) 
	{
		payload = new char[len];
		if (payload)
			payloadLength = len;
	}
	__attribute__((always_inline)) ~MACPacketInput() { delete[] payload; }

	__attribute__((always_inline)) uint8_t EvaluatePayloadChecksum()
	{
		char *p = payload;
		uint8_t chk = 0;
		uint8_t len = payloadLength;
		while (len--)
			chk ^= *p++;
		return chk;
	}
};

#endif /* PACKET_H_ */