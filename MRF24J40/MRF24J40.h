/*
* MRF24J40.h
*
* Created: 25/02/2015 18.22.54
*  Author: xmas79
*
* Based on "lib_mrf24j.h" by Karl Palsson, false.ekta.is
*
*/

#ifndef MRF24J40_H_
#define MRF24J40_H_

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "MACPacket.h"

namespace MRF24J40
{
	const int TX_RETRIES = 0;
	const int TX_OK = 2;
	const int CHANNEL_BUSY = 3;
	const int TX = 4;
	const int RX = 5;

	const int MRF_RXMCR = 0x00;
	const int PROMI = 0;
	const int ERRPKT = 1;
	const int COORD = 2;
	const int PANCOORD = 3;
	//const int Reserved = 4;
	const int NOACKRSP = 5;
	//const int Reserved = 6;
	//const int Reserved = 7;

	const int MRF_PANIDL = 0x01;
	const int MRF_PANIDH = 0x02;
	const int MRF_SADRL = 0x03;
	const int MRF_SADRH = 0x04;
	const int MRF_EADR0 = 0x05;
	const int MRF_EADR1 = 0x06;
	const int MRF_EADR2 = 0x07;
	const int MRF_EADR3 = 0x08;
	const int MRF_EADR4 = 0x09;
	const int MRF_EADR5 = 0x0A;
	const int MRF_EADR6 = 0x0B;
	const int MRF_EADR7 = 0x0C;

	const int MRF_RXFLUSH = 0x0D;
	const int RXFLUSH = 0;
	const int BCNONLY = 1;
	const int DATAONLY = 2;
	const int CMDONLY = 3;
	//const int Reserved = 4;
	const int WAKEPAD = 5;
	const int WAKEPOL = 6;
	//const int Reserved = 7;

	//const int MRF_Reserved = 0x0E;
	//const int MRF_Reserved = 0x0F;
	const int MRF_ORDER = 0x10;
	const int MRF_TXMCR = 0x11;
	const int MRF_ACKTMOUT = 0x12;
	const int MRF_ESLOTG1 = 0x13;
	const int MRF_SYMTICKL = 0x14;
	const int MRF_SYMTICKH = 0x15;
	const int MRF_PACON0 = 0x16;
	const int MRF_PACON1 = 0x17;
	const int MRF_PACON2 = 0x18;
	//const int MRF_Reserved = 0x19;
	const int MRF_TXBCON0 = 0x1A;

	// TXNCON: TRANSMIT NORMAL FIFO CONTROL REGISTER (ADDRESS: 0x1B)
	const int MRF_TXNCON =      0x1B;
	const int MRF_TXNTRIG =     0;
	const int MRF_TXNSECEN =    1;
	const int MRF_TXNACKREQ =   2;
	const int MRF_INDIRECT =    3;
	const int MRF_FPSTAT =      4;

	const int MRF_TXG1CON = 0x1C;
	const int MRF_TXG2CON = 0x1D;
	const int MRF_ESLOTG23 = 0x1E;
	const int MRF_ESLOTG45 = 0x1F;
	const int MRF_ESLOTG67 = 0x20;
	const int MRF_TXPEND = 0x21;
	const int MRF_WAKECON = 0x22;
	const int IMMWAKE = 7;
	const int REGWAKE = 6;

	const int MRF_FRMOFFSET = 0x23;
	// TXSTAT: TX MAC STATUS REGISTER (ADDRESS: 0x24)
	const int MRF_TXSTAT = 0x24;
	const int TXNRETRY1 =       7;
	const int TXNRETRY0 =       6;
	const int CCAFAIL =         5;
	const int TXG2FNT =         4;
	const int TXG1FNT =         3;
	const int TXG2STAT =        2;
	const int TXG1STAT =        1;
	const int TXNSTAT =         0;

	const int MRF_TXBCON1 = 0x25;
	const int MRF_GATECLK = 0x26;
	const int MRF_TXTIME = 0x27;
	const int MRF_HSYMTMRL = 0x28;
	const int MRF_HSYMTMRH = 0x29;
	const int MRF_SOFTRST = 0x2A;
	const int RSTPWR = 2;

	//const int MRF_Reserved = 0x2B;
	const int MRF_SECCON0 = 0x2C;
	const int MRF_SECCON1 = 0x2D;
	const int MRF_TXSTBL = 0x2E;
	//const int MRF_Reserved = 0x2F;
	const int MRF_RXSR = 0x30;
	const int MRF_INTSTAT = 0x31;
	const int MRF_INTCON = 0x32;
	const int MRF_GPIO = 0x33;
	const int MRF_TRISGPIO = 0x34;
	const int MRF_SLPACK = 0x35;
	const int SLPACK = 7;

	const int MRF_RFCTL = 0x36;
	const int MRF_SECCR2 = 0x37;
	const int MRF_BBREG0 = 0x38;
	const int MRF_BBREG1 = 0x39;
	const int MRF_BBREG2 = 0x3A;
	const int MRF_BBREG3 = 0x3B;
	const int MRF_BBREG4 = 0x3C;
	//const int MRF_Reserved = 0x3D;
	const int MRF_BBREG6 = 0x3E;
	const int MRF_CCAEDTH = 0x3F;


	const int MRF_RFCON0 = 0x200;
	const int MRF_RFCON1 = 0x201;
	const int MRF_RFCON2 = 0x202;
	const int MRF_RFCON3 = 0x203;
	const int MRF_RFCON5 = 0x205;
	const int MRF_RFCON6 = 0x206;
	const int MRF_RFCON7 = 0x207;
	const int MRF_RFCON8 = 0x208;
	const int MRF_SLPCAL0 = 0x209;
	const int MRF_SLPCAL1 = 0x20A;
	const int MRF_SLPCAL2 = 0x20B;
	const int MRF_RSSI = 0x210;
	const int MRF_SLPCON0 = 0x211;
	const int _SLPCLKEN = 0;
	const int INTEDGE = 1;

	const int MRF_SLPCON1 = 0x220;
	const int MRF_WAKETIMEL = 0x222;
	const int MRF_WAKETIMEH = 0x223;
	const int MRF_REMCNTL = 0x224;
	const int MRF_REMCNTH = 0x225;
	const int MRF_MAINCNT0 = 0x226;
	const int MRF_MAINCNT1 = 0x227;
	const int MRF_MAINCNT2 = 0x228;
	const int MRF_MAINCNT3 = 0x229;
	const int MRF_TESTMODE = 0x22F;
	const int MRF_ASSOEADR1 = 0x231;
	const int MRF_ASSOEADR2 = 0x232;
	const int MRF_ASSOEADR3 = 0x233;
	const int MRF_ASSOEADR4 = 0x234;
	const int MRF_ASSOEADR5 = 0x235;
	const int MRF_ASSOEADR6 = 0x236;
	const int MRF_ASSOEADR7 = 0x237;
	const int MRF_ASSOSADR0 = 0x238;
	const int MRF_ASSOSADR1 = 0x239;
	const int MRF_UPNONCE0 = 0x240;
	const int MRF_UPNONCE1 = 0x241;
	const int MRF_UPNONCE2 = 0x242;
	const int MRF_UPNONCE3 = 0x243;
	const int MRF_UPNONCE4 = 0x244;
	const int MRF_UPNONCE5 = 0x245;
	const int MRF_UPNONCE6 = 0x246;
	const int MRF_UPNONCE7 = 0x247;
	const int MRF_UPNONCE8 = 0x248;
	const int MRF_UPNONCE9 = 0x249;
	const int MRF_UPNONCE10 = 0x24A;
	const int MRF_UPNONCE11 = 0x24B;
	const int MRF_UPNONCE12 = 0x24C;

	const int MRF_I_RXIF  = 0x08;
	const int MRF_I_TXNIF = 0x01;

	const int MRF_FLAG_RX = 0x01;
	const int MRF_FLAG_TX = 0x02;
	const int MRF_FLAG_TX_OK = 0x04;


	template<typename T>
	class MRF24J40Driver : public T
	{
		protected:
		uint8_t sequence_number;
		uint16_t panid;
		uint16_t address;
		//uint8_t rx_buffer[127];

		//volatile uint8_t flags_rx_tx;

		//mrf_rx_info_t mrf_rx_info;
		//mrf_tx_info_t mrf_tx_info;

		public:
		uint8_t ReadRegisterShort(uint8_t address) {
			this->PrepareSPI();
			this->SelectDevice();
			// 0 top for short addressing, 0 bottom for read
			this->SPISend((address << 1) & 0x7e);
			uint8_t res = this->SPISend(0xff);
			this->DeselectDevice();
			return res;
		}

		uint8_t ReadRegisterLong(uint16_t address) {
			this->PrepareSPI();
			this->SelectDevice();
			uint8_t ahigh = address >> 3;
			uint8_t alow = address << 5;
			this->SPISend(0x80 | ahigh);  // high bit for long
			this->SPISend(alow);
			uint8_t res = this->SPISend(0xff);
			this->DeselectDevice();
			return res;
		}


		void WriteRegisterShort(uint8_t address, uint8_t data) {
			this->PrepareSPI();
			this->SelectDevice();
			// 0 for top address, 1 bottom for write
			this->SPISend(((address << 1) & 0x7e) | 0x01);
			this->SPISend(data);
			this->DeselectDevice();
		}

		void WriteRegisterLong(uint16_t address, uint8_t data) {
			this->PrepareSPI();
			this->SelectDevice();
			uint8_t ahigh = address >> 3;
			uint8_t alow = address << 5;
			this->SPISend(0x80 | ahigh);  // high bit for long
			this->SPISend(alow | 0x10);  // last bit for write
			this->SPISend(data);
			this->DeselectDevice();
		}

		void SetPANId(uint16_t panid) {
			WriteRegisterShort(MRF_PANIDH, panid >> 8);
			WriteRegisterShort(MRF_PANIDL, panid & 0xff);
			this->panid = panid;
		}

		void SetAddress(uint16_t address16) {
			WriteRegisterShort(MRF_SADRH, address16 >> 8);
			WriteRegisterShort(MRF_SADRL, address16 & 0xff);
			this->address = address16;
		}


		void UploadDataPacket(char *data, uint8_t len)
		{
			uint8_t i = 0;
			while (len--)
				WriteRegisterLong(i++, *data++);
		}
		
		/**
		* Simple send 16, with acks, not much of anything.. assumes src16 and local pan only.
		* @param data
		*/
		void SendData(uint16_t dest16, char *data, uint8_t len) {

			uint8_t i = 0;
			WriteRegisterLong(i++, 9);  // header length
			WriteRegisterLong(i++, 9 + len); //+2 is because module seems to ignore 2 bytes after the header?!

			// 0 | pan compression | ack | no security | no data pending | data frame[3 bits]
			WriteRegisterLong(i++, 0x61); // first byte of Frame Control
			// 16 bit source, 802.15.4 (2003), 16 bit dest,
			WriteRegisterLong(i++, 0x88); // second byte of frame control
			WriteRegisterLong(i++, sequence_number++);  // sequence number

			WriteRegisterLong(i++, panid & 0xff);  // dest panid
			WriteRegisterLong(i++, panid >> 8);
			WriteRegisterLong(i++, dest16 & 0xff);  // dest16 low
			WriteRegisterLong(i++, dest16 >> 8); // dest16 high

			WriteRegisterLong(i++, address & 0xff); // src16 low
			WriteRegisterLong(i++, address >> 8); // src16 high

			// Copy data
			for (int q = 0; q < len; q++)
				WriteRegisterLong(i++, data[q]);
			
			// Send message
			WriteRegisterShort(MRF_TXNCON, (1<<MRF_TXNACKREQ | 1<<MRF_TXNTRIG));
		}

		void EnableInterrupts(uint8_t risingEdge) {
			WriteRegisterShort(MRF_INTCON, 0xf6);

			uint8_t v = ReadRegisterLong(MRF_SLPCON0);
			if (risingEdge)
				v |= (1 << INTEDGE);
			else
				v &= (1 << INTEDGE);
			WriteRegisterLong(MRF_SLPCON0, v);
		}

		void SetChannel(uint8_t channel) {
			WriteRegisterLong(MRF_RFCON0, ((channel - 11) << 4) + 0x03);
			_delay_us(192); // Wait for RF stabilization
		}

		void SoftwareReset()
		{
			WriteRegisterShort(MRF_SOFTRST, 0x7);
			while (ReadRegisterShort(MRF_SOFTRST) & 0x7)
				;
		}

		void Initialize(uint16_t panid, uint16_t address, uint8_t channel)
		{
			// Initialize basic stuff
			sequence_number = 1;
			this->panid = 0;
			this->address = 0;
			
			// Now initialize the radio
			SoftwareReset();
			
			WriteRegisterShort(MRF_PACON2, 0x98); // – Initialize FIFOEN = 1 and TXONTS = 0x6.
			WriteRegisterShort(MRF_TXSTBL, 0x95); // – Initialize RFSTBL = 0x9.

			WriteRegisterLong(MRF_RFCON0, 0x03); // – Initialize RFOPT = 0x03.
			WriteRegisterLong(MRF_RFCON1, 0x01); // – Initialize VCOOPT = 0x02.
			WriteRegisterLong(MRF_RFCON2, 0x80); // – Enable PLL (PLLEN = 1).
			SetTransmissionPower(0); // RFCON3
			WriteRegisterLong(MRF_RFCON6, 0x90); // – Initialize TXFIL = 1 and 20MRECVR = 1.
			WriteRegisterLong(MRF_RFCON7, 0x80); // – Initialize SLPCLKSEL = 0x2 (100 kHz Internal oscillator).
			WriteRegisterLong(MRF_RFCON8, 0x10); // – Initialize RFVCO = 1.
			WriteRegisterLong(MRF_SLPCON1, 0x21); // – Initialize CLKOUTEN = 1 and SLPCLKDIV = 0x01.

			//  Configuration for nonbeacon-enabled devices (see Section 3.8 “Beacon-Enabled and Nonbeacon-Enabled Networks”):
			WriteRegisterShort(MRF_BBREG2, 0x80); // Set CCA mode to ED
			WriteRegisterShort(MRF_CCAEDTH, 0x60); // – Set CCA ED threshold.
			WriteRegisterShort(MRF_BBREG6, 0x40); // – Set appended RSSI value to RXFIFO.
			EnableInterrupts(1);
			SetPANId(panid);
			SetAddress(address);
			SetChannel(channel);
			// max power is by default.. just leave it...
			//Set transmitter power - See “REGISTER 2-62: RF CONTROL 3 REGISTER (ADDRESS: 0x203)”.
			FlushRXFIFO();
			RFStateMachineReset();

			//SetCoordinator();
			//SetDataOnlyMode();
		}

		void SetCoordinator()
		{
			WriteRegisterShort(MRF_RXMCR, 1 << COORD);
		}

		void FlushRXFIFO()
		{
			WriteRegisterShort(MRF_RXFLUSH, 1 << RXFLUSH);
		}

		void SetDataOnlyMode()
		{
			WriteRegisterShort(MRF_RXFLUSH, 1 << DATAONLY);
		}

		void SetTransmissionPower(uint8_t power)
		{
			char p;

			if(power > (-10))
				p = 0;
			else if(power > (-20))
			{
				p = (1<<6);
				power += 10;
			}
			else if(power > (-30))
			{
				p = (1<<7);
				power += 20;
			}
			else
			{
				p = (1<<7) | (1<<6);
				power += 30;
			}

			if(power <= (-6))
				p |= (1<<5) | (1<<4) | (1<<3);
			else if(power == (-5))
				p |= (1<<5) | (1<<4);
			else if(power == (-4))
				p |= (1<<5) | (1<<3);
			else if(power == (-3))
				p |= (1<<5);
			else if(power == (-2))
				p |= (1<<4) | (1<<3);
			else if(power == (-1))
				p |= (1<<4);

			WriteRegisterLong(MRF_RFCON3, p);
		}

		void RFStateMachineReset()
		{
			WriteRegisterShort(MRF_RFCTL, 0x04); //  Reset RF state machine.
			WriteRegisterShort(MRF_RFCTL, 0x00); // part 2
			_delay_us(192); // delay at least 192usec
		}

		MACPacketInput *ReadPacket()
		{
			// read out the packet data...
			uint8_t payloadLength = ReadRegisterLong(0x300) - 9 - 2; // 9 is the header length, 2 is lqi+rssi at the end
			MACPacketInput *p = new MACPacketInput(payloadLength);
			if (p)
			{
				p->destinationAddress = (((uint16_t)ReadRegisterLong(0x300 + 6)) << 8) | ReadRegisterLong(0x300 + 7);
				p->sourceAddress = (((uint16_t)ReadRegisterLong(0x300 + 8)) << 8) | ReadRegisterLong(0x300 + 9);
			
				// Read payload
				uint16_t idx = 0x300 + 1 + 9; // 1 is frame length, 9 is MAC header length
				for (int i = 0; i < p->payloadLength; i++, idx++)
					p->payload[i] = ReadRegisterLong(idx);
			
				// Read lqi and RSSI
				p->lqi = ReadRegisterLong(idx++);
				p->rssi = ReadRegisterLong(idx);
			}

			WriteRegisterShort(MRF_BBREG1, 0x00);  // RXDECINV - enable receiver

			return p;
		}
		/**
		* Call this from within an interrupt handler connected to the MRFs output
		* interrupt pin.  It handles reading in any data from the module, and letting it
		* continue working.
		* Only the most recent data is ever kept.
		*/
		uint8_t InterruptHandler(void) {
			uint8_t last_interrupt = ReadRegisterShort(MRF_INTSTAT);
			uint8_t rx_tx_status = 0;
			
			if (last_interrupt & MRF_I_RXIF) {
				rx_tx_status |= 1 << RX;
				
				WriteRegisterShort(MRF_BBREG1, 0x04);  // RXDECINV - disable receiver
			}
			
			if (last_interrupt & MRF_I_TXNIF) {
				rx_tx_status |= 1 << TX;
				
				uint8_t tmp = ReadRegisterShort(MRF_TXSTAT);
				
				// 1 means it failed, we want 1 to mean it worked.
				rx_tx_status |= ~(tmp & (1 << TXNSTAT)) ? (1 << TX_OK) : 0x00;
				rx_tx_status |= tmp >> 6;
				rx_tx_status |= (tmp & (1 << CCAFAIL)) ? (1 << CHANNEL_BUSY) : 0x00;
			}
			
			return rx_tx_status;
		}


		/**
		* Call this function periodically, it will invoke your nominated handlers
		*/
		//void CheckTxRxFlags
		//(
		//void (*rx_handler) (mrf_rx_info_t *rxinfo, uint8_t *rxbuffer),
		//void (*tx_handler) (mrf_tx_info_t *txinfo)
		//)
		//{
			//if (flags_rx_tx & MRF_FLAG_RX) {
				//flags_rx_tx &= ~MRF_FLAG_RX;
				//rx_handler(&mrf_rx_info, rx_buffer);
			//}
			//
			//if (flags_rx_tx & MRF_FLAG_TX ) {
				//flags_rx_tx &= ~MRF_FLAG_TX;
				//tx_handler(&mrf_tx_info);
			//}
		//}

		void ImmediateSleep()
		{
			// Ensure immediate wake & sleep mode bit is set
			uint8_t wakecon = ReadRegisterShort(MRF_WAKECON);
			wakecon |= (1 << IMMWAKE);
			WriteRegisterShort(MRF_WAKECON, wakecon);

			// Go to sleep
			WriteRegisterShort(MRF_SOFTRST, (1 << RSTPWR));
			WriteRegisterShort(MRF_SLPACK, (1 << SLPACK));
		}

		void ImmediateWakeSPI(bool wait2ms)
		{
			// Wake up with registers
			uint8_t wakecon = ReadRegisterShort(MRF_WAKECON);
			WriteRegisterShort(MRF_WAKECON, wakecon | (1 << REGWAKE));
			WriteRegisterShort(MRF_WAKECON, wakecon);
			RFStateMachineReset();
			if (wait2ms)
				_delay_ms(2);
		}
	};
}

#endif /* MRF24J40_H_ */