#include <stdint.h>
#include "GpioDriver.h"

static uint16_t* gpioAddress;
static uint16_t gpioStatus;

void Gpio_Init(uint16_t * address){
    gpioAddress = address;
    gpioStatus = ALL_OFF;
    *gpioAddress = gpioStatus;
}

void Gpio_TurnOn(eGPIO_PINS gpio_pin){
    gpioStatus |= (1<<gpio_pin);
    *gpioAddress = gpioStatus;
}

void Gpio_TurnOff(eGPIO_PINS gpio_pin){
    gpioStatus &= ~(1<<gpio_pin);
    *gpioAddress = gpioStatus;
}