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

#ifndef _BOARD_DRIVER_RAISE_SIDE_
#define _BOARD_DRIVER_RAISE_SIDE_

#include <sam.h>
#include <stdbool.h>
#include "board_definitions.h"

//Default PMIC (BQ24195) I2C address
#define LEFT_SIDE_ADDRESS                   0x59
#define RIGHT_SIDE_ADDRESS                   0x60

// Register address definitions
#define BOOTLOADER_REGISTER		 	0x0F

void configureRaiseSide();
bool readSideBootloaderKey();

#endif 
