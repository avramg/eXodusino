#ifndef SSP_H_
#define SSP_H_


/**************************************************************************//**
 * @file     SPI.h
 * @brief    Arduino-like library for MARY
 * @version	V0.50
 * @date	1. August 2011.
 * @author	@@lynxeyed_atsu
 * @note	Copyright (c) 2011 Lynx-EyED's Klavier and Craft-works. <BR>
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions: <BR>
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.<BR>
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

#include <lpcdevice.h>
#include "gpio.h"
#include "spi_middle.h"
#ifdef __cplusplus
  extern "C" {
#endif

/*! @class SSP
	@brief SPIを制御するクラス
*/
class SSP {
private:
	SSP_PORT port;				/*!< 使用するポート　*/
	SSP_BIT_ORDER bitOrder;
	SSP_CLK_DIVIDER divider;
	SSP_DATA_MODE dataMode;
	int bitlength;

public:
	SSP();		// announce the constructor to initialize
	~SSP();
	void begin();
	void begin(SSP_PORT port);
	void end();
	void setBitLength(int bitLength);
	void setBitOrder(SSP_BIT_ORDER bitOrder) ;
	void setClockDivider(SSP_CLK_DIVIDER divider);
	void setDataMode(SSP_DATA_MODE mode);
	unsigned long transfer(unsigned long txdata) ;
};

extern SSP SPI;


#ifdef __cplusplus
  }
#endif


#endif /* SSP_H_ */
