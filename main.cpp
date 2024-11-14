/*
 * Copyright (c) 2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Keypad.h"
#include "Password.h"
#include "Buzzer.h"

// Specify different pins to test printing on UART other than the console UART.
#define TARGET_TX_PIN                                                     USBTX
#define TARGET_RX_PIN                                                     USBRX

InterruptIn ExitButton(PC_13);
DigitalOut redLED(PA_13);
DigitalOut greenLED(PA_14);



// char testArray[4] = {'1','2','3','4'};
char expectedVal;
int attemptCounter = 1;
const int unlockTimeS = 5;
const int unlockTimemS = unlockTimeS *1000;
const int incorrectBlinkmS = 500;
const int incorrectBlinkuS = incorrectBlinkmS * 1000;
const int overBlinkmS = 500;
const int timeOutS = 5;
const int timeOutuS = timeOutS *1000000;
const int lockBuzzerTimemS= 250;
const float unlockBuzzer = 1.0/1000.0;
const float lockBuzzer = 1.0/200.0;
const float incorrectBuzzer = 1.0/440.0;

// Create a BufferedSerial object to be used by the system I/O retarget code.
static BufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN, 9600);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &serial_port;
}

void Lock(){
    greenLED = 0;
    redLED = 1;
    Tone(lockBuzzer, lockBuzzerTimemS);
}

void Unlock(){
    redLED = 0;
    greenLED = 1;
    Tone(unlockBuzzer, unlockTimemS);
    wait_us(1000);
    Lock();
}

void CorrectPasscode() {
    //printf("Correct!\n\r");
    attemptCounter = 1;
    Unlock();
}

void IncorrectPasscode() {
    printf("Wrong!\n\r");
    for (int i = 0; i < attemptCounter; i++){
        redLED = 0;
        Tone(incorrectBuzzer, incorrectBlinkmS);
        redLED = 1;
        wait_us(incorrectBlinkuS);
    }
    attemptCounter += 1;
}

void OverAttemptLimit(){
    printf("Too many attempts!");
    for (int i = 0; i < 20; i++){
    redLED = 0;
    //wait_us(20);
    greenLED = 1;
    Tone(unlockBuzzer, overBlinkmS);
    greenLED = 0;
    redLED = 1;
    Tone(lockBuzzer, overBlinkmS);
    }
    attemptCounter = 1;
}

int main(void)
{
    char keypadInput;
    ExitButton.rise(&Unlock); //interrupt to let people exit from inside
    // print to the console using the `serial_port` object.
    /*
    printf(
        "Mbed OS version %d.%d.%d\n",
        MBED_MAJOR_VERSION,
        MBED_MINOR_VERSION,
        MBED_PATCH_VERSION
    );
    */
        while(1){
            redLED = 1;
            
            /*
            Tone(highPitch,1000);
            Tone(C_Period,1000);
            */

           /* if (led1 == 1){
                printf("LED is on  :)\n\r");
                led1 = 0;
            }
            else if (led1 == 0){
                printf("LED is off :( \n\r");
                led1 = 1;
            }
            wait_us(500000);
            */

            /*
            keypadInput = Keypad_Reading();
            serial_port.write(&keypadInput,sizeof(keypadInput)); // serial output for keypad
            wait_us(200000); // button press wait (maybe needs tuning)
            */

            if (Password_Check() == true) {
                CorrectPasscode();
                }
            else if (attemptCounter == 3){
                OverAttemptLimit();
                }    
            else {
                IncorrectPasscode();
                }
            /*
            printf("expected value: ");

            for (int i = 0; i < 4; i++) {
                printf ("%c",testArray[i]);
            }
            printf("\n\r");
            */
        }
        return 0;
}
