#include "mbed.h"

PwmOut buzzer(PA_15);

void Tone(float period, int duration_ms){
    buzzer.period(period);
    buzzer = 0.5f;
    wait_us(duration_ms * 1000);
    buzzer = 0; 
}