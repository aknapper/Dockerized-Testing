#ifndef GPIODRIVER_H
#define GPIODRIVER_H

typedef enum{
    ALL_OFF,
    GPIO0_ON = 1,
    GPIO1_ON = 2,
    GPIO01_ON = 3,
    GPIO7_ON = 128,
    GPIO017_ON = 131,
    ALL_ON = ~0
} eGPIO_STATES;

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
} eGPIO_PINS;

void Gpio_Init(uint16_t * address);
void Gpio_TurnOn(eGPIO_PINS gpio_pin);
void Gpio_TurnOff(eGPIO_PINS gpio_pin);

#endif // GPIODRIVER_H