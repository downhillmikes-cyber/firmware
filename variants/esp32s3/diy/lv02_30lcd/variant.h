
#pragma once

// LV02-30LCD NerdMiner
// Custom Meshtastic hardware variant
// ESP32-S3 / 16MB Flash / 8MB PSRAM

// ========================================
// GPS
// ========================================

#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// ========================================
// Display configuration
// ========================================

#define HAS_SCREEN 1
#define USE_TFTDISPLAY 1
#define VARIANT_DISPLAY_DRIVER 1
#define HAS_SPI_TFT 1

#define TFT_WIDTH 170
#define TFT_HEIGHT 320
#define SCREEN_ROTATE

#define BRIGHTNESS_DEFAULT 128

// ========================================
// LCD power and backlight
// ========================================

#define TFT_POWER_EN 15
#define TFT_BL 38
#define TFT_BACKLIGHT_ON HIGH

// ========================================
// LCD control pins
// ========================================

#define TFT_CS  6
#define TFT_DC  7
#define TFT_RST 5
#define TFT_WR  8
#define TFT_RD  9

// ========================================
// LCD 8-bit parallel data bus
// ========================================

#define TFT_D0 39
#define TFT_D1 40
#define TFT_D2 41
#define TFT_D3 42
#define TFT_D4 45
#define TFT_D5 46
#define TFT_D6 47
#define TFT_D7 48

// ========================================
// LCD bus frequencies
// ========================================

#define LCD_WRITE_FREQ 10000000
#define LCD_READ_FREQ   8000000

// ========================================
// I2C - reserved for future peripherals
// ========================================

#define I2C_SDA 17
#define I2C_SCL 18

// ==================================================
// Physical buttons
// ==================================================

// Primary user button
#define BUTTON_PIN 14
#define BUTTON_NEED_PULLUP
#define BUTTON_ACTIVE_LOW true
#define BUTTON_ACTIVE_PULLUP true

// Secondary user button (BOOT)
#define ALT_BUTTON_PIN 0
#define ALT_BUTTON_ACTIVE_LOW true
#define ALT_BUTTON_ACTIVE_PULLUP true

// ========================================
// LoRa SPI interface
// ========================================

#define LORA_SCK  12
#define LORA_MOSI 11
#define LORA_MISO 13
#define LORA_CS   10

#define LORA_RESET 1
#define LORA_DIO1  21

// ========================================
// SX1262 radio
// ========================================

#define USE_SX1262

#define SX126X_CS    LORA_CS
#define SX126X_DIO1  LORA_DIO1
#define SX126X_BUSY  2
#define SX126X_RESET LORA_RESET

// RF switch and TCXO configuration
// Pending confirmation of physical module.
