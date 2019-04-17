/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.
  Copyright (c) 2015 Atmel Corporation/Thibaut VIARD.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "board_driver_i2c.h"
#include "raise_side_i2c.h"

#ifdef CONFIGURE_RAISE_SIDE

extern uint8_t rxBuffer[1];

uint8_t readRegister(uint8_t addr, uint8_t reg) {
  i2c_beginTransmission(addr);
  i2c_write(reg);
  i2c_endTransmission(true);

  i2c_requestFrom(LEFT_SIDE_ADDRESS, 1, true);
  return rxBuffer[0];
}

bool readSideBootloaderKey()
{
	if(readRegister(LEFT_SIDE_ADDRESS, BOOTLOADER_REGISTER))
		return true;
	if(readRegister(RIGHT_SIDE_ADDRESS, BOOTLOADER_REGISTER))
		return true;

    return false;
}
void configureRaiseSide()
{
  i2c_init(100000);
}

#endif
