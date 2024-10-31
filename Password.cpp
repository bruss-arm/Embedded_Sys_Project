#include "mbed.h"
#include "Keypad.h"
#include "Password.h"
#include <stdio.h>
#include <ctype.h>

char userInput[4];
char currentInput;
int correctDigits;

bool Password_Check(char expectedInput[4]) {
    correctDigits = 0;
printf("\n\ruser input: ");
for (int i = 0; i < 4; i++) {

    currentInput = Keypad_Reading();
    while (currentInput == ' ') {
    currentInput = Keypad_Reading();
     }
     userInput[i] = currentInput;
     printf ("%c",currentInput);
    }
printf("\n\r");

for (int i = 0; i < 4; i++){
    //printf("%d",i);

    if (userInput[i] != expectedInput[i]) {

        return false;
        printf("Case 1");
    }
 
    else correctDigits += 1; //numeric input
}

    if (correctDigits == 4) return true;
    else {
    printf("Case 2");
        return false;
        }
    }


