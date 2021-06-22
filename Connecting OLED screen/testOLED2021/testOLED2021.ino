#include <U8g2lib.h>
#include <Wire.h>
#define time_delay 2000
//U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_FAST);  // Dev 0, Fast I2C / TWI


const char COPYRIGHT_SYMBOL[] = {0xa9, '\0'};
void u8g2_prepare() {
u8g2.setFont(u8g2_font_6x10_tf);
u8g2.setFontRefHeightExtendedText();
u8g2.setDrawColor(1);
u8g2.setFontPosTop();
u8g2.setFontDirection(0);
}
void u8g2_box_frame() {
u8g2.drawStr(0, 0, "drawBox");
u8g2.drawBox(5, 10, 20, 10);
u8g2.drawStr(60, 0, "drawFrame");
u8g2.drawFrame(65, 10, 20, 10);
}
void u8g2_r_frame_box() {
u8g2.drawStr(0, 0, "drawRFrame");
u8g2.drawRFrame(5, 10, 40, 15, 3);
u8g2.drawStr(70, 0, "drawRBox");
u8g2.drawRBox(70, 10, 25, 15, 3);
}
void u8g2_disc_circle() {
u8g2.drawStr(0, 0, "drawDisc");
u8g2.drawDisc(10, 18, 9);
u8g2.drawStr(60, 0, "drawCircle");
u8g2.drawCircle(70, 18, 9);
}
void u8g2_string_orientation() {
u8g2.setFontDirection(0);
u8g2.drawStr(5, 15, "0");
u8g2.setFontDirection(3);
u8g2.drawStr(40, 25, "90");
u8g2.setFontDirection(2);
u8g2.drawStr(75, 15, "180");
u8g2.setFontDirection(1);
u8g2.drawStr(100, 10, "270");
}
void u8g2_line() {
u8g2.drawStr(0, 0, "drawLine");
u8g2.drawLine(7, 20, 77, 32);
}
void u8g2_triangle() {
u8g2.drawStr(0, 0, "drawTriangle");
u8g2.drawTriangle(14, 20, 45, 30, 10, 32);
}
void u8g2_unicode() {
u8g2.drawStr(0, 0, "Unicode");
u8g2.setFont(u8g2_font_unifont_t_symbols);
u8g2.setFontPosTop();
u8g2.setFontDirection(0);
u8g2.drawUTF8(10, 20, "☀");
u8g2.drawUTF8(30, 20, "☁");
u8g2.drawUTF8(50, 20, "☂");
u8g2.drawUTF8(70, 20, "☔");
u8g2.drawUTF8(95, 20, COPYRIGHT_SYMBOL); //COPYRIGHT SIMBOL
u8g2.drawUTF8(115, 15, "\xb0"); // DEGREE SYMBOL
}
#define image_width 128
#define image_height 21
static const unsigned char image_bits[] U8X8_PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00,
0xfc, 0x1f, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xfe, 0x1f, 0x00, 0x00, 0xfc, 0x7f, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x07, 0x18, 0x00, 0x00, 0x0c, 0x60, 0x00, 0x00,
0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x18, 0x00, 0x00,
0x0c, 0xc0, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0x18, 0x00, 0x00, 0x0c, 0xc0, 0xf0, 0x1f, 0x06, 0x63, 0x80, 0xf1,
0x1f, 0xfc, 0x33, 0xc0, 0x03, 0x18, 0x00, 0x00, 0x0c, 0xc0, 0xf8, 0x3f,
0x06, 0x63, 0xc0, 0xf9, 0x3f, 0xfe, 0x33, 0xc0, 0x03, 0x18, 0x00, 0x00,
0x0c, 0xc0, 0x18, 0x30, 0x06, 0x63, 0xc0, 0x18, 0x30, 0x06, 0x30, 0xc0,
0xff, 0xff, 0xdf, 0xff, 0x0c, 0xc0, 0x18, 0x30, 0x06, 0x63, 0xe0, 0x18,
0x30, 0x06, 0x30, 0xc0, 0xff, 0xff, 0xdf, 0xff, 0x0c, 0xc0, 0x98, 0x3f,
0x06, 0x63, 0x60, 0x98, 0x3f, 0x06, 0x30, 0xc0, 0x03, 0x18, 0x0c, 0x00,
0x0c, 0xc0, 0x98, 0x1f, 0x06, 0x63, 0x70, 0x98, 0x1f, 0x06, 0x30, 0xc0,
0x03, 0x18, 0x06, 0x00, 0x0c, 0xc0, 0x18, 0x00, 0x06, 0x63, 0x38, 0x18,
0x00, 0x06, 0x30, 0xc0, 0x03, 0x18, 0x03, 0x00, 0x0c, 0xe0, 0x18, 0x00,
0x06, 0x63, 0x1c, 0x18, 0x00, 0x06, 0x30, 0xc0, 0x00, 0x80, 0x01, 0x00,
0xfc, 0x7f, 0xf8, 0x07, 0x1e, 0xe3, 0x0f, 0xf8, 0x07, 0x06, 0xf0, 0xcf,
0x00, 0xc0, 0x00, 0x00, 0xfc, 0x3f, 0xf0, 0x07, 0x1c, 0xe3, 0x07, 0xf0,
0x07, 0x06, 0xe0, 0xcf, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x30, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xe0, 0x00, 0xfc, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0xfc, 0x1f, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f };

void u8g2_bitmap() {
u8g2.drawXBMP(0, 5, image_width, image_height, image_bits);
}
void setup(void) {
u8g2.begin();
u8g2_prepare();
}
float i = 0.0;
void loop(void) {
u8g2.clearBuffer();
u8g2_prepare();
u8g2_box_frame();
u8g2.sendBuffer();
delay(time_delay);
u8g2.clearBuffer();
u8g2_disc_circle();
u8g2.sendBuffer();
delay(time_delay);
u8g2.clearBuffer();
u8g2_r_frame_box();
u8g2.sendBuffer();
delay(time_delay);
u8g2.clearBuffer();
u8g2_prepare();
u8g2_string_orientation();
u8g2.sendBuffer();
delay(time_delay);
u8g2.clearBuffer();
u8g2_line();
u8g2.sendBuffer();
delay(time_delay);
// one tab
u8g2.clearBuffer();
u8g2_triangle();
u8g2.sendBuffer();
delay(time_delay);
u8g2.clearBuffer();
u8g2_prepare();
u8g2_unicode();
u8g2.sendBuffer();
delay(time_delay);
u8g2.clearBuffer();
u8g2_bitmap();
u8g2.sendBuffer();
delay(time_delay);
u8g2.clearBuffer();
u8g2.setCursor(0, 0);
u8g2.print(i);
i = i + 1.5;
u8g2.sendBuffer();
delay(time_delay);
}
