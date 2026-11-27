
#include "configuration.h"
#include <Arduino.h>
#include "variant_display.h"

LGFX::LGFX(void)
{
    // =================================================
    // Enable LCD power
    // =================================================

    pinMode(TFT_POWER_EN, OUTPUT);
    digitalWrite(TFT_POWER_EN, HIGH);

    delay(100);

    // =================================================
    // ESP32-S3 8-bit parallel LCD bus
    // =================================================

    {
        auto cfg = _bus_instance.config();

        cfg.port = 0;

        cfg.freq_write = LCD_WRITE_FREQ;
        cfg.freq_read = LCD_READ_FREQ;

        cfg.pin_wr = TFT_WR;
        cfg.pin_rd = TFT_RD;
        cfg.pin_rs = TFT_DC;

        cfg.pin_d0 = TFT_D0;
        cfg.pin_d1 = TFT_D1;
        cfg.pin_d2 = TFT_D2;
        cfg.pin_d3 = TFT_D3;
        cfg.pin_d4 = TFT_D4;
        cfg.pin_d5 = TFT_D5;
        cfg.pin_d6 = TFT_D6;
        cfg.pin_d7 = TFT_D7;

        _bus_instance.config(cfg);

        _panel_instance.setBus(&_bus_instance);
    }

    // =================================================
    // ST7789 LCD panel
    // =================================================

    {
        auto cfg = _panel_instance.config();

        cfg.pin_cs = TFT_CS;
        cfg.pin_rst = TFT_RST;
        cfg.pin_busy = -1;

        cfg.memory_width = 240;
        cfg.memory_height = 320;

        cfg.panel_width = TFT_WIDTH;
        cfg.panel_height = TFT_HEIGHT;

        cfg.offset_x = 35;
        cfg.offset_y = 0;
        cfg.offset_rotation = 0;

        cfg.readable = false;
        cfg.invert = true;
        cfg.rgb_order = false;

        cfg.dlen_16bit = false;
        cfg.bus_shared = false;

        _panel_instance.config(cfg);
    }

    // =================================================
    // PWM backlight
    // =================================================

    {
        auto cfg = _light_instance.config();

        cfg.pin_bl = TFT_BL;
        cfg.invert = false;
        cfg.freq = 44000;
        cfg.pwm_channel = 7;

        _light_instance.config(cfg);

        _panel_instance.setLight(&_light_instance);
    }

    // =================================================
    // Register the configured panel
    // =================================================

    setPanel(&_panel_instance);
}
