#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/spi.h"
#ifndef ATTACHMENT_H
#define ATTACHMENT_H

extern uint16_t att_input;

extern uint16_t att_output;

extern uint16_t WHO_AM_I;

extern uint8_t buttons[8];

#define X 0xBF
#define CIRCLE 0xDF
#define TRIANGLE 0xEF
#define SQUARE 0x7F

#define R1 0xF7
#define R2 0xFD
#define L1 0xFB
#define L2 0xFE

#define DRIGHT 0xDF
#define DUP 0xEF
#define DDOWN 0xBF
#define DLEFT 0x7F

#define START 0xF7
#define SELECT 0xFE
#define L3 0xFD
#define R3 0xFB

typedef void (*buttonFunction)(void);

typedef struct
{
    uint8_t *buttonStatus;
    buttonFunction buttonFunctions[8];
} Attachment;

void initAttachment(Attachment *a);
void pollButtonFunctions(Attachment *a);
void buttonTimeout(Attachment *a);
void spi_irq_init();
void spi_irq();

//----------Button Function Declarations for User to Define----------//
void buttonOneFunction();
void buttonTwoFunction();
void buttonThreeFunction();
void buttonFourFunction();
void buttonFiveFunction();
void buttonSixFunction();
void buttonSevenFunction();
void buttonEightFunction();

#endif