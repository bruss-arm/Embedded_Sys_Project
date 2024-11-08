#include "mbed.h"
#include "Keypad.h"
#include "Password.h"
#include <stdio.h>
#include <ctype.h>
#include "map"
#include "string"
#include "iostream"

char userInput[4];
string input;
char currentInput;
int correctDigits;

map <string, string> Personnel;
/*
 = {
    {"9679","Brandon"},
    {"1234","Dakota"},
    {"5678","Will"}
};
*/

static void InitializePersonnel() {
    Personnel["9679"] = "Brandon";
    Personnel["1234"] = "Dakota";
    Personnel["5678"] = "Will";
};



bool Password_Check() {
    /*
    correctDigits = 0;
    printf("\n\ruser input: ");
    */
    InitializePersonnel();
for (int i = 0; i < 4; i++) {

    currentInput = Keypad_Reading();
    while (currentInput == ' ') {
    currentInput = Keypad_Reading();
     }
     userInput[i] = currentInput;
     //printf ("%c",currentInput);
    }
    userInput[4] = '\0';
    input = userInput;
    //input += '/0';
    cout << "Keypad input:" << input << endl;

auto it = Personnel.find(input);
if (it != Personnel.end()){
    cout << "Hello " << Personnel.find(input)->second << "! \n\r";
    return true;
}
else {return false;}
/* for (int i = 0; i < 4; i++){
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
        */
    }


