#define radio0_width 17
#define radio0_height 9
const unsigned char radio0_bits[] PROGMEM = {
   0x11, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x15, 0x00, 0x00, 0x04, 0x00, 0x00,
   0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0x01 };

#define radio1_width 17
#define radio1_height 9
const unsigned char radio1_bits[] PROGMEM = {
   0x11, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x15, 0x00, 0x00, 0x04, 0x00, 0x00,
   0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0x01 };

#define radio2_width 17
#define radio2_height 9
const unsigned char radio2_bits[] PROGMEM = {
   0x11, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x15, 0x00, 0x00, 0x04, 0x00, 0x00,
   0x04, 0x00, 0x00, 0x44, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0x01 };

#define radio3_width 17
#define radio3_height 9
const unsigned char radio3_bits[] PROGMEM = {
   0x11, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x15, 0x00, 0x00, 0x04, 0x00, 0x00,
   0x04, 0x01, 0x00, 0x44, 0x01, 0x00, 0x54, 0x01, 0x00, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0x01 };

#define radio4_width 17
#define radio4_height 9
const unsigned char radio4_bits[] PROGMEM = {
   0x11, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x15, 0x00, 0x00, 0x04, 0x04, 0x00,
   0x04, 0x05, 0x00, 0x44, 0x05, 0x00, 0x54, 0x05, 0x00, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0x01 };

#define radio5_width 17
#define radio5_height 9
const unsigned char radio5_bits[] PROGMEM = {
   0x11, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x15, 0x10, 0x00, 0x04, 0x14, 0x00,
   0x04, 0x15, 0x00, 0x44, 0x15, 0x00, 0x54, 0x15, 0x00, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0x01 };

#define radio6_width 17
#define radio6_height 9
const unsigned char radio6_bits[] PROGMEM = {
   0x11, 0x00, 0x00, 0x1f, 0x40, 0x00, 0x15, 0x50, 0x00, 0x04, 0x54, 0x00,
   0x04, 0x55, 0x00, 0x44, 0x55, 0x00, 0x54, 0x55, 0x00, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0x01 };

#define radio7_width 17
#define radio7_height 9
const unsigned char radio7_bits[] PROGMEM = {
   0x11, 0x00, 0x01, 0x1f, 0x40, 0x01, 0x15, 0x50, 0x01, 0x04, 0x54, 0x01,
   0x04, 0x55, 0x01, 0x44, 0x55, 0x01, 0x54, 0x55, 0x01, 0x00, 0x00, 0x00,
   0xfc, 0xff, 0x01 };

#define fb_width 128
#define fb_height 64
const unsigned char fb_bits[] PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xe0, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c,
   0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x18, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xc0, 0x03, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
   0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x78, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x80, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78,
   0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x78, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xc0, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c,
   0xc0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x3c, 0xc0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0xe0, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e,
   0xe0, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x3f, 0xf0, 0xc7, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x87, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f,
   0xf0, 0x87, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0x0f, 0xf8, 0x83, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0f, 0xfc, 0x83, 0x07, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07,
   0xfc, 0x83, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xe0, 0x07, 0xfe, 0x81, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x07, 0xff, 0x81, 0x07, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x03,
   0xff, 0xc1, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf0, 0x83, 0xff, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x81, 0xff, 0xc0, 0x03, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xc1,
   0x7f, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf0, 0xc0, 0x3f, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xc0, 0x3f, 0xf0, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xe0,
   0x1f, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0xe0, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xf0, 0x0f, 0xfc, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf0,
   0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x70, 0xf0, 0x0f, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf0, 0x07, 0x7e, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8,
   0x07, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xe0, 0xf8, 0x03, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0x03, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf8,
   0x03, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0xf9, 0x01, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x01, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0x81, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf8, 0x81, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x81, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0xf8,
   0x01, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x06, 0x00, 0xf0, 0x01, 0x07, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00,
   0xe0, 0x0f, 0x00, 0x00, 0x00, 0x03, 0x00, 0xf0, 0x01, 0x07, 0xfc, 0x31,
   0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
   0x01, 0x07, 0x0c, 0x33, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x98, 0xdd,
   0x83, 0x07, 0x1e, 0xe0, 0x01, 0x0e, 0x0c, 0x33, 0x3c, 0x0c, 0xc3, 0x03,
   0x60, 0x60, 0x98, 0x73, 0xc6, 0x0c, 0x33, 0xe0, 0x03, 0x0e, 0x0c, 0x33,
   0x66, 0x0c, 0x63, 0x06, 0xe0, 0x6f, 0x98, 0x31, 0x66, 0x98, 0x61, 0xc0,
   0x03, 0x0c, 0xfc, 0x31, 0xc3, 0x0c, 0x33, 0x0c, 0x60, 0x60, 0x98, 0x31,
   0xe6, 0x9f, 0x7f, 0xc0, 0x03, 0x0c, 0x0c, 0x33, 0xff, 0x0c, 0xf3, 0x0f,
   0x60, 0x60, 0x98, 0x31, 0x66, 0x80, 0x01, 0x80, 0x03, 0x08, 0x0c, 0x33,
   0x03, 0x0c, 0x33, 0x00, 0x60, 0x60, 0x98, 0x31, 0x66, 0x80, 0x01, 0x00,
   0x07, 0x00, 0x0c, 0x33, 0x03, 0x0c, 0x33, 0x00, 0x60, 0x60, 0x9c, 0x31,
   0xc6, 0x10, 0x43, 0x00, 0x06, 0x00, 0x0c, 0x33, 0x86, 0x8c, 0x63, 0x08,
   0x60, 0xc0, 0x9b, 0x31, 0x86, 0x0f, 0x3e, 0x00, 0x04, 0x00, 0xfc, 0x31,
   0x7c, 0x78, 0xc3, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00 };

