
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
// Display - temporarily disabled
// ========================================

#define HAS_SCREEN 0

// ========================================
// I2C - reserved for future peripherals
// ========================================

#define I2C_SDA 17
#define I2C_SCL 18

// ========================================
// User button
// ========================================

#define BUTTON_PIN 14
#define BUTTON_NEED_PULLUP

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
