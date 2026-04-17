// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin

#define TAPPING_TERM 150

// Mouse speed settings - slower default, faster with modifier
#define MOUSEKEY_DELAY 20           // Delay before mouse starts moving (lower = faster start)
#define MOUSEKEY_INTERVAL 20        // Time between mouse movements (lower = faster)
#define MOUSEKEY_MAX_SPEED 5        // Max speed (default is 10, we're using 5 for slower)
#define MOUSEKEY_ACCEL_ENABLE       // Enable acceleration
#define MOUSEKEY_ACCELERATED_MAX 10 // Max speed when accelerated (faster option)

