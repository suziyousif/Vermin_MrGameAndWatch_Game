#ifndef FIGURAS_H_
#define FIGURAS_H_


//504 bytes por figura - 48x84 pixels
const unsigned char GameAndWatch_start[] = {
	0xfc, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x81, 0xc1, 0xe1, 0xe1, 0x71, 0x31, 0x31, 0x31, 0x31,
	0x31, 0x31, 0x31, 0x71, 0x71, 0xe1, 0xe1, 0xc1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x81,
	0xc1, 0xe1, 0xf1, 0xf1, 0xf1, 0xf1, 0x81, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x81,
	0xc1, 0xe1, 0xf1, 0xf1, 0xf1, 0xf1, 0x01, 0x01, 0x01, 0x01, 0x81, 0xc1, 0xe1, 0xf1, 0xf1, 0xf1,
	0xf1, 0x01, 0x01, 0x01, 0xf1, 0xf1, 0xf1, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x06, 0xfc, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3f, 0x79, 0xe0, 0xe0,
	0xc0, 0xc0, 0xc0, 0xc0, 0xcc, 0xcc, 0xcc, 0xcc, 0xec, 0x7c, 0x7c, 0x3c, 0xdc, 0xc0, 0xf0, 0x78,
	0x3c, 0x1e, 0x1f, 0x1f, 0x1b, 0x19, 0x18, 0xff, 0xff, 0xff, 0x08, 0x80, 0xc0, 0xe0, 0xf0, 0x78,
	0x3c, 0x1e, 0x0f, 0x07, 0x03, 0x01, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x7c, 0x3c, 0x1f, 0x0f, 0x03,
	0x03, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6,
	0xc6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xf8, 0xfc, 0xec,
	0xcc, 0xec, 0xfc, 0x78, 0x30, 0x00, 0xc0, 0xc0, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e,
	0x1f, 0x3f, 0x33, 0x31, 0x31, 0x31, 0x33, 0x3f, 0x1f, 0x1f, 0x0f, 0x1f, 0x38, 0x38, 0x30, 0x00,
	0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x80, 0xc0, 0xe0, 0xf0, 0x78, 0x3c,
	0x1e, 0x0f, 0xff, 0xff, 0xff, 0x80, 0xc0, 0xe0, 0xf0, 0x78, 0x3c, 0x9e, 0xcf, 0xe7, 0xf3, 0xf9,
	0xbc, 0x9e, 0xef, 0xff, 0xff, 0xff, 0x00, 0x03, 0x03, 0x03, 0xff, 0xff, 0xff, 0x7f, 0x03, 0x03,
	0xf3, 0xfc, 0xfe, 0x9e, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x06,
	0x06, 0x00, 0x00, 0xff, 0xff, 0xff, 0x60, 0x60, 0x60, 0x60, 0x60, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xff, 0x3f, 0x40, 0x80, 0x80, 0x80, 0x80, 0x8f, 0x8f, 0x8f, 0x8f, 0x87, 0x83,
	0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x8f, 0x8f, 0x8f, 0x8f, 0x87, 0x89, 0x8c, 0x8e, 0x8f, 0x87,
	0x83, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x8f, 0x8f, 0x8f, 0x80, 0x80, 0x80, 0x80, 0x8f, 0x8f,
	0x8f, 0x8f, 0x80, 0x80, 0x80, 0x81, 0x83, 0x87, 0x87, 0x8e, 0x8e, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c,
	0x8c, 0x8e, 0x86, 0x87, 0x82, 0x80, 0x80, 0x8f, 0x8f, 0x8f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x8f,
	0x8f, 0x8f, 0x80, 0x80, 0x80, 0x80, 0x60, 0x3f};

const unsigned char start_icon[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00,
0x00, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0x1f, 0x1f, 0x5f, 0x5f, 0xdf, 0x9f, 0x9f, 0x9f, 0xbf, 0xff, 0xff, 0x9f, 0xdf, 0x9f, 0xdf, 0x1f, 0x1f, 0x1f, 0x1f, 0xdf, 0x9f, 0xdf, 0x9f, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0x1f, 0x9f, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0x1f, 0x1f, 0xdf, 0xdf, 0xdf, 0xdf, 0x1f, 0x1f, 0x1f, 0x3f, 0xff, 0xdf, 0xdf, 0x9f, 0xdf, 0xdf, 0x1f, 0x1f, 0x1f, 0x1f, 0xdf, 0xdf, 0x9f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0,
0x01, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xf3, 0xf2, 0xf2, 0xf6, 0xf6, 0xf6, 0xf0, 0xf0, 0xf0, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf1, 0xf0, 0xf0, 0xf8, 0xfb, 0xfb, 0xfb, 0xf8, 0xf0, 0xf0, 0xe1, 0xf7, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0xf0, 0xf3, 0xf7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0f,
0x00, 0x00, 0x00, 0x01, 0x03, 0x0f, 0x0f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const unsigned char MrGameAndWatch_1[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x2C, 0x1E, 0x3F, 0x3F, 0x1E, 0x0C, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC3, 0x07, 0xEF, 0xF5, 0xF7, 0xF5, 0xEF,
0x07, 0x23, 0x20, 0x30, 0x10, 0x10, 0x0C, 0x06, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0xF8, 0xF8,
0xF8, 0xF8, 0xF8, 0x00, 0xA0, 0xA0, 0xA0, 0x20, 0x20, 0x18, 0x1C, 0x06, 0x01, 0x04, 0x04, 0x06,
0x01, 0x01, 0x01, 0x06, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char romexterminator_all [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1E, 0x3F, 0x3F, 0x1E, 0x2C, 0x40, 0x80, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x2C, 0x1E, 0x3F, 0x3F, 0x1E, 0x0C, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x01, 0x03, 0x06, 0x08, 0x08, 0x18, 0x10, 0x30, 0xA3, 0x07, 0xEF, 0xF5, 0xF7, 0xF5, 0xEF,
	0x07, 0xA3, 0x30, 0x10, 0x18, 0x08, 0x08, 0x06, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0xF8, 0xF8,
	0xF8, 0xF8, 0xF8, 0x20, 0xA0, 0xA0, 0x80, 0x30, 0x30, 0x18, 0x0C, 0x02, 0x83, 0x85, 0x04, 0x06,
	0x01, 0x01, 0x01, 0x06, 0x04, 0x85, 0x83, 0x02, 0x0C, 0x18, 0x30, 0x30, 0x80, 0xA0, 0xA0, 0x20,
	0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x10, 0x12, 0x42, 0x3B,
	0x3D, 0x3E, 0x7E, 0x3A, 0x5E, 0x6C, 0x6D, 0x6C, 0x06, 0x10, 0x10, 0x10, 0x10, 0x10, 0x12, 0x42,
	0x3B, 0x3D, 0x3E, 0x7E, 0x3A, 0x5E, 0x6C, 0x6D, 0x6C, 0x06, 0x10, 0x10, 0x10, 0x10, 0x10, 0x12,
	0x62, 0x63, 0x59, 0x3C, 0x7A, 0x56, 0x7A, 0x3C, 0x59, 0x63, 0x62, 0x12, 0x10, 0x10, 0x10, 0x10,
	0x10, 0x06, 0x6C, 0x6D, 0x6C, 0x5E, 0x3A, 0x7E, 0x3E, 0x3D, 0x3B, 0x42, 0x12, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x06, 0x6C, 0x6D, 0x6C, 0x5E, 0x3A, 0x7E, 0x3E, 0x3D, 0x3B, 0x42, 0x12, 0x10, 0x10,
	0x00, 0x90, 0x90, 0x4A, 0x4A, 0x49, 0x51, 0x92, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
	0x50, 0x50, 0x48, 0x4A, 0x8A, 0x91, 0x11, 0x02, 0x02, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x40,
	0x40, 0x90, 0x90, 0x08, 0x08, 0x0A, 0x12, 0x11, 0x01, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x11, 0x91, 0x8A, 0x4A,
	0x48, 0x50, 0x50, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x92, 0x52, 0x49, 0x49, 0x4A, 0x92,
	0x90, 0x00, 0x00, 0x00, 0x02, 0x62, 0xF2, 0xC2, 0xF2, 0xBA, 0xF2, 0xC2, 0xF2, 0x62, 0x02, 0x02,
	0x62, 0xF2, 0xC2, 0xF2, 0xBA, 0xF2, 0xC2, 0xF2, 0x62, 0x02, 0x02, 0x62, 0xF2, 0xC2, 0xF2, 0xBA,
	0xF2, 0xC2, 0xF2, 0x62, 0x06, 0xFC, 0x00, 0xFE, 0x92, 0x92, 0x92, 0xFE, 0x00, 0xFE, 0x92, 0x92,
	0x92, 0xFE, 0x00, 0xFE, 0x92, 0x92, 0x92, 0xFE, 0x00, 0xFE, 0x92, 0x92, 0x92, 0xFE, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};



// ---------------------------------------------------------------------------------------
// Os pixeis n�o empregados na definic�o dos bytes DEVEM ser ZERO, ou seja, os pixeis que n�o devem ser impressos
// A figura � desenhada conforme trabalho do LCD, do LSB to MSB (bytes alinhados verticalmente, ver manual do LCD5110)
//-----------------------------------------------------------------------------------------------------------------
const figura_t fig1 =
{
	4,							// largura em pixels = numero de colunas da matriz
	24,							// altura em pixels = cada 8 pixels corresponte a uma linha da matriz
	{0b11111111, 0b10000011, 0b10000011, 0b11111111,
	 0b11111110, 0b11000001, 0b11000001, 0b11111110,
	 0b11111110, 0b11000001, 0b11000001, 0b11111110,}
};


const figura_t MrGameAndWatch_left =
{
	29,
	19,
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xfc, 0xb4, 0xbf, 0xbe, 0xb7, 0xfd,
	 0x70, 0x00, 0x80, 0x00, 0x58, 0x3c, 0x7e, 0x7e, 0x7e, 0x3c, 0x18, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0xa0,
	 0x08, 0x1c, 0x0c, 0x06, 0x06, 0xfe, 0xfe, 0xff, 0xff, 0xfe, 0xfe, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x07, 0x07, 0x06, 0x07, 0x07,
	 0x00, 0x00, 0x07, 0x07, 0x06, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};

const figura_t MrGameAndWatch_right =
{
	29,
	19,
	{0x18, 0x3c, 0x7e, 0x7e, 0x7e, 0x3c, 0x58, 0x00, 0x80, 0x00, 0x00, 0x70, 0xfc, 0xb4, 0xbf, 0xbe, 0xb7, 0xfd,
	 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x01, 0x03, 0x03, 0x06, 0x06, 0xfe, 0xfe, 0xff, 0xff, 0xfe, 0xfe, 0x06, 0x0e, 0x1c, 0x08, 0xa0, 0xc0, 0xe0,
	 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x06, 0x07, 0x07,
	 0x00, 0x00, 0x07, 0x07, 0x06, 0x07, 0x07, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x03, 0x01}
};

const figura_t MrGameAndWatch =
{
	29,
	19,
	{0x18, 0x3c, 0x7e, 0x7e, 0x7e, 0x3c, 0x58, 0x00, 0x80, 0x00, 0x00, 0x70, 0xfc, 0xb4, 0xbf, 0xbe, 0xb7, 0xfd,
	 0x70, 0x00, 0x80, 0x00, 0x58, 0x3c, 0x7e, 0x7e, 0x7e, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x01, 0x03, 0x03, 0x06, 0x06, 0xfe, 0xfe, 0xff, 0xff, 0xfe, 0xfe, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x06, 0x07, 0x07,
	 0x00, 0x00, 0x07, 0x07, 0x06, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};
const figura_t delete_MrGameAndWatch =
{
	29,
	19,
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};

const figura_t line =
{
	7,
	2,
	{0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03}
};

const figura_t Mole =
{
	10,
	7,
	{0x3c, 0x7c, 0x60, 0x78, 0x5f, 0x5f, 0x78, 0x60, 0x7c, 0x3c}
};

const figura_t OneMole =
{
	39,
	9,
	{0xf1, 0xf1, 0x81, 0xe5, 0x7d, 0x79, 0xe9, 0x81, 0xf1, 0xf1, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xff, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x01}
};

const figura_t TwoMole =
{
	36,
	9,
	{0xf1, 0xf1, 0x81, 0xe5, 0x7d, 0x7d, 0xe1, 0x81, 0xf1, 0xf1, 0x01, 0x01, 0xf1, 0xf1,
	 0x81, 0xe5, 0x7d, 0x79, 0xe9, 0x81, 0xf1, 0xf1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xff, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x01}
};

const figura_t ThreeMole =
{
	36,
	9,
	{0xf1, 0xf1, 0x81, 0xe1, 0x79, 0x7d, 0xe1, 0x81, 0xf1, 0xf1, 0x01, 0x01, 0xf1, 0xf1,
	 0x81, 0xe1, 0x79, 0x7d, 0xe1, 0x81, 0xf1, 0xf1, 0x01, 0x01, 0xf1, 0xf1, 0x81, 0xe1,
	 0x79, 0x7d, 0xe1, 0x81, 0xf1, 0xf1, 0x01, 0xff, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
	 0x00, 0x01}
};

const figura_t ZeroMole =
{
	36,
	9,
	{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x01}
};

typedef struct Missings{
	figura_t *missingsSquare;
}Missings_t;

void set_missingFigures(Missings_t *missing,const figura_t *figure, uint8_t i){
	missing->missingsSquare[i]=*figure;
}

figura_t* get_missingFigures(Missings_t *missing, uint8_t i){
	return (&missing->missingsSquare[i]);
}
#endif /* FIGURAS_H_ */
