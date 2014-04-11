/*****************************
Newhaven 1.8 Inch TFT Display Library

author: Ryan Sailor
date: 2/25/2014

An Arduino library for communicating
with a Newhaven Display 1.8 inch TFT
display.

******************************/

#ifndef _NH18DISPLAY_H
#define _NH18DISPLAY_H

#include <Arduino.h>
#include <pgmspace.h>

// Pin Definitions
// PORTB
#define nhRST 0x10 // D8
#define nhDC  0x20 // D9
#define nhWR  0x40 // D10
// PORTC
#define nhRD  0x40 // D5

// PORTD
#define nhDB0 0x01 // D3
#define nhDB1 0x02 // D2

// PORTF
#define nhDB2 0x10 // A3
#define nhDB3 0x20 // A2
#define nhDB4 0x40 // A1
#define nhDB5 0x80 // A0

// PORTD
#define nhDB6 0x10 // D4
#define nhDB7 0x80 // D6


// COLORS
#define NH18_RED   	0xF800
#define NH18_GREEN 	0x03C0
#define NH18_BLUE  	0x001F
#define NH18_WHITE 	0xFFFF
#define NH18_BLACK 	0x0000
#define NH18_TEAL  	0x3FFF
#define NH18_PURPLE	0xF83C
#define NH18_YELLOW 0xFFC0

extern uint8_t NH18_FONT_CONSOLAS_12[];
extern uint8_t NH18_FONT_CONSOLAS_16[];

class NH18Display {
public:
    static void begin();
    
    static void drawPixel(uint8_t x, uint8_t y, uint16_t color);
	static void drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint16_t color);
	static void drawHLine(uint8_t x, uint8_t y, uint8_t len, uint16_t color);
	static void drawVLine(uint8_t x, uint8_t y, uint8_t len, uint16_t color);
	static void drawTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);
	static void drawTriangleSolid(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);
	static void drawRect(uint8_t x,uint8_t y,uint8_t w,uint8_t h,uint16_t color);
	static void drawRectSolid(uint8_t x,uint8_t y,uint8_t w,uint8_t h,uint16_t color);
	static void drawCircle(uint8_t x, uint8_t y, uint8_t rad, uint16_t color);
	static void drawCircleSolid(uint8_t x, uint8_t y, uint8_t rad, uint16_t color);
	static void drawEllipse(uint8_t x0, uint8_t y0, uint8_t radx, uint8_t rady, uint16_t color);
	static void drawEllipseSolid(uint8_t x0, uint8_t y0, uint8_t radx, uint8_t rady, uint16_t color);

private:
	static void extractFont(uint8_t* font, int index);
	static void drawChar(uint8_t x, uint8_t y, uint8_t* font, int charIndex, uint8_t size, uint8_t charWidth, uint8_t charHeight, uint16_t color);

public:
	static void drawText(uint8_t x, uint8_t y, const char* text, int len, uint8_t* fontface, uint16_t color);
	
	static void fill(uint16_t color);
	
    static void writeCommand(uint8_t);
    static void writeData(uint8_t);
    
private:
	static void beginMemWrite();
    static void endMemWrite();
    static void setMemAccess(uint8_t x0,uint8_t y0,uint8_t x1,uint8_t y1);

    static void setCommand();
    static void setData();
    static void setWrite();
    static void setRead();	
};


#endif