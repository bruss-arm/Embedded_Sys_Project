#include "mbed.h"
#include "Keypad.h"


static DigitalOut rowOne(PA_10);
static DigitalOut rowTwo(PB_3);
static DigitalOut rowThree(PB_5);
static DigitalOut rowFour(PB_4);

static DigitalIn columnOne(PB_10,PullDown);
static DigitalIn columnTwo(PA_8,PullDown);
static DigitalIn columnThree(PA_9,PullDown);
static DigitalIn columnFour(PC_7,PullDown);

static int usPinSetDelay = 50;

void wait() {wait_us(200000);}

char Keypad_Reading(){
    rowOne.write(1), rowTwo.write(1), rowThree.write(1), rowFour.write(1);

if (columnOne.read() == 1 || columnTwo.read() == 1 || columnThree.read() == 1|| columnFour.read() == 1){
    rowOne.write(1), rowTwo.write(0), rowThree.write(0), rowFour.write(0);
   wait_us(usPinSetDelay);
    while (rowOne == 1){
        if (columnOne.read() == 0 && columnTwo.read() == 0 && columnThree.read() == 0 && columnFour.read() == 0){
            rowOne.write(0);
            break;
            }
        else if (columnOne.read() == 1){wait(); return '1';}
        else if (columnTwo.read() == 1) {wait(); return '2';}
        else if (columnThree.read() == 1){wait(); return '3';}
        else if (columnFour.read() == 1){wait(); return 'A';}
        else rowOne.write(0);
    }

    rowTwo.write(1);
   wait_us(usPinSetDelay);
    while (rowTwo == 1){
        if (columnOne.read() == 0 && columnTwo.read() == 0 && columnThree.read() == 0 && columnFour.read() == 0){
            rowTwo.write(0);
            break;
            }
        else if (columnOne.read() == 1){wait(); return '4';}
        else if (columnTwo.read() == 1){wait(); return '5';}
        else if (columnThree.read() == 1){wait(); return '6';}
        else if (columnFour.read() == 1){wait(); return 'B';}
        else rowTwo.write(0);
    }

    rowThree.write(1);
    wait_us(usPinSetDelay);
    while (rowThree == 1){
        if (columnOne.read() == 0 && columnTwo.read() == 0 && columnThree.read() == 0 && columnFour.read() == 0){
             rowThree.write(0);
             break;
             }
        else if (columnOne.read() == 1){wait(); return '7';}
        else if (columnTwo.read() == 1){wait(); return '8';}
        else if (columnThree.read() == 1){wait(); return '9';}
        else if (columnFour.read() == 1){wait(); return 'C';}
        else rowThree.write(0);
    }

    rowFour.write(1);
    wait_us(usPinSetDelay);
    while (rowFour == 1){ 
        if (columnOne.read() == 0 && columnTwo.read() == 0 && columnThree.read() == 0 && columnFour.read() == 0){
            rowFour.write(0);
            break;
            }
        else if (columnOne.read() == 1){wait(); return '*';}
        else if (columnTwo.read() == 1){wait(); return '0';}
        else if (columnThree.read() == 1){wait(); return '#';}
        else if (columnFour.read() == 1){wait(); return 'D';}
        
    }
return '?';
}
else{
     return ' ';
    }
}
