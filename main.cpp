/*
 * Copyright (c) 2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Keypad.cpp"

// Specify different pins to test printing on UART other than the console UART.
#define TARGET_TX_PIN                                                     USBTX
#define TARGET_RX_PIN                                                     USBRX

// Create a BufferedSerial object to be used by the system I/O retarget code.
static BufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN, 9600);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &serial_port;
}




int main(void)
{
    char keypadInput;
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

            keypadInput = Keypad_Reading();
            serial_port.write(&keypadInput,sizeof(keypadInput)); // serial output for keypad
            wait_us(192500); // button press wait (maybe needs tuning)
        }
        return 0;
}