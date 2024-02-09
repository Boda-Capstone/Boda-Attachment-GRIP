#include <stdio.h>
#include "pico/stdlib.h"
#ifndef ATTACHMENT_H
#define ATTACHMENT_H

typedef void (*buttonFunction)(void);

typedef struct
{
    uint8_t *buttonStatus;
    buttonFunction buttonFunctions[8];
} Attachment;

void initAttachment(Attachment *a, uint8_t *statusByte);
void pollButtonFunctions(Attachment *a);

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