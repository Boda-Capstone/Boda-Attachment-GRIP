#include "Attachment.h"

void pollButtonFunctions(Attachment *a)
{
    for (int i = 0; i < 8; i++)
    {
        if (*(a->buttonStatus) & (1 << i))
        {
            (a->buttonFunctions[i])();
            uint8_t temp = 0b11111111;
            temp ^= (1 << i);
            *(a->buttonStatus) &= temp;
        }
    }
}

void initAttachment(Attachment *a, uint8_t *statusByte)
{
    a->buttonStatus = statusByte;

    a->buttonFunctions[0] = buttonOneFunction;
    a->buttonFunctions[1] = buttonTwoFunction;
    a->buttonFunctions[2] = buttonThreeFunction;
    a->buttonFunctions[3] = buttonFourFunction;
    a->buttonFunctions[4] = buttonFiveFunction;
    a->buttonFunctions[5] = buttonSixFunction;
    a->buttonFunctions[6] = buttonSevenFunction;
    a->buttonFunctions[7] = buttonEightFunction;
}