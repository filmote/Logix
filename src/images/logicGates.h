#pragma once

#include "../utils/Arduboy2Ext.h"

const uint8_t PROGMEM LED[] = {
    16, 20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x20, 0x40, 0x80, 0x20, 0x10, 0x04, 0x8c, 0x40, 0x10, 0x30, 
    0x08, 0x08, 0x08, 0x08, 0x08, 0xff, 0x00, 0x00, 0x80, 0x41, 0x22, 0x1c, 0x08, 0x08, 0x08, 0x08, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0x40, 0x10, 0x30, 
    0x08, 0x08, 0x08, 0x08, 0x08, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3e, 0x1c, 0x08, 0x08, 0x08, 0x08, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe0, 0xc0, 0x80, 0x20, 0x10, 0x04, 0x0c, 0x00, 0x00, 0x00, 
    0x08, 0x08, 0x08, 0x08, 0x08, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3e, 0x1c, 0x08, 0x08, 0x08, 0x08, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


const uint8_t PROGMEM logicGates[] = {
    16, 16,

    /* AND */
    0x08, 0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x18, 0xe0, 0x80, 0x80, 
    0x08, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x10, 0x0c, 0x03, 0x00, 0x00, 

    /* NAND */
    0x08, 0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x18, 0xe0, 0x40, 0xc0, 
    0x08, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x10, 0x0c, 0x03, 0x01, 0x01, 

    /* OR */
    0x08, 0x0b, 0x0d, 0xf1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x18, 0x60, 0x80, 
    0x08, 0x68, 0x58, 0x47, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x10, 0x0c, 0x03, 0x00, 

    /* NOR */
    0x08, 0x0b, 0x0d, 0xf1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x18, 0xe0, 0x40, 0xc0, 
    0x08, 0x68, 0x58, 0x47, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x10, 0x0c, 0x03, 0x01, 0x01, 

    /* XOR */
    0x08, 0x0b, 0x0c, 0xf0, 0x03, 0x0d, 0xf1, 0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x18, 0x60, 0x80, 
    0x08, 0x68, 0x18, 0x07, 0x60, 0x58, 0x47, 0x40, 0x40, 0x40, 0x20, 0x20, 0x10, 0x0c, 0x03, 0x00, 

    /* XNOR */
    0x08, 0x0b, 0x0c, 0xf0, 0x03, 0x0d, 0xf1, 0x01, 0x01, 0x02, 0x02, 0x04, 0x18, 0xe0, 0x40, 0xc0, 
    0x08, 0x68, 0x18, 0x07, 0x60, 0x58, 0x47, 0x40, 0x40, 0x20, 0x20, 0x10, 0x0c, 0x03, 0x01, 0x01, 

    /* NOT */
    0x80, 0x80, 0x80, 0xff, 0x02, 0x04, 0x08, 0x10, 0x20, 0xc0, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x80, 
    0x00, 0x00, 0x00, 0x7f, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 

    /* BLANK */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t PROGMEM logicGates_Masks[] = {

    /* AND */
    0x3e, 0xff, 0xab, 0x55, 0xab, 0x55, 0xab, 0x55, 0xab, 0x55, 0xab, 0x56, 0xac, 0xf8, 0xe0, 0xe0, 
    0x3e, 0x7f, 0x6a, 0x55, 0x6a, 0x55, 0x6a, 0x55, 0x6a, 0x55, 0x6a, 0x35, 0x1a, 0x0f, 0x03, 0x03, 

    /* NAND */
    0x3e, 0xff, 0xab, 0x55, 0xab, 0x55, 0xab, 0x55, 0xab, 0x55, 0xab, 0x56, 0xac, 0xf8, 0xe0, 0xe0, 
    0x3e, 0x7f, 0x6a, 0x55, 0x6a, 0x55, 0x6a, 0x55, 0x6a, 0x55, 0x6a, 0x35, 0x1a, 0x0f, 0x03, 0x03, 


    /* OR */
    0x3e, 0x3f, 0x0d, 0xfb, 0x55, 0xab, 0x55, 0xab, 0x55, 0xab, 0x55, 0xab, 0x56, 0xac, 0x78, 0xe0, 
    0x3e, 0x7e, 0x58, 0x6f, 0x55, 0x6a, 0x55, 0x6a, 0x55, 0x6a, 0x55, 0x6a, 0x35, 0x1a, 0x0f, 0x03, 

    /* NOR */
    0x3e, 0x3f, 0x1d, 0xfb, 0x55, 0xab, 0x55, 0xab, 0x55, 0xab, 0x55, 0xaa, 0x54, 0xb8, 0xe0, 0xe0, 
    0x3e, 0x7e, 0x5c, 0x6f, 0x55, 0x6a, 0x55, 0x6a, 0x55, 0x6a, 0x55, 0x2a, 0x15, 0x0e, 0x03, 0x03, 

    /* XOR */
    0x3c, 0x3f, 0x0c, 0xf0, 0x03, 0x0d, 0xfb, 0x55, 0xab, 0x55, 0xab, 0x55, 0xaa, 0x54, 0xf8, 0xe0, 
    0x1e, 0x7e, 0x18, 0x07, 0x60, 0x58, 0x6f, 0x55, 0x6a, 0x55, 0x6a, 0x55, 0x2a, 0x15, 0x0f, 0x03, 

    /* XNOR */
    0x3e, 0x3f, 0x0c, 0xf0, 0x03, 0x0d, 0xfb, 0x55, 0xab, 0x55, 0xab, 0x56, 0xac, 0xf8, 0xe0, 0xe0, 
    0x3e, 0x7e, 0x18, 0x07, 0x60, 0x58, 0x6f, 0x55, 0x6a, 0x55, 0x6a, 0x35, 0x1a, 0x0f, 0x03, 0x03, 

    /* NOT */
    0x80, 0xc0, 0xc0, 0xff, 0xab, 0x56, 0xac, 0x58, 0xb0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 
    0x00, 0x01, 0x01, 0x7f, 0x6a, 0x35, 0x1a, 0x0d, 0x06, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 

    /* BLANK */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

};


const uint8_t PROGMEM switches[] = {
    17, 9,
    
    0x82, 0x82, 0xc7, 0x45, 0xc7, 0x04, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x38, 0x28, 0x38, 0x10, 0x10, 
    0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

    0x82, 0x82, 0xc7, 0x45, 0xc7, 0x40, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x38, 0x28, 0x38, 0x10, 0x10, 
    0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};