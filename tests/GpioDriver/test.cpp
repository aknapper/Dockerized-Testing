#include "CppUTest/TestHarness.h"

extern "C" {
    #include "GpioDriver.h"
}

// Create a test group
TEST_GROUP(GpioDriver)
{
    uint16_t fakeGpios;
    void setup()
    {
        // Initialize before each test
        Gpio_Init(&fakeGpios);
    }
    
    void teardown()
    {
        // Deinitialize after each test
    }
};

TEST(GpioDriver, Gpios_Off_When_Initialized){
    fakeGpios = 0xFFFF;
    Gpio_Init(&fakeGpios);
    LONGS_EQUAL(ALL_OFF, fakeGpios);
}

TEST(GpioDriver, TurnOnFirstGpio){
    Gpio_TurnOn(PIN0);
    LONGS_EQUAL(GPIO0_ON,fakeGpios);
}

TEST(GpioDriver, TurnOnSecondGpio){
    Gpio_TurnOn(PIN1);
    LONGS_EQUAL(GPIO1_ON,fakeGpios);
}

TEST(GpioDriver, TurnOnEigthGpio){
    Gpio_TurnOn(PIN7);
    LONGS_EQUAL(GPIO7_ON,fakeGpios);
}

TEST(GpioDriver, TurnOn_EigthGpio){
    Gpio_TurnOn(PIN7);
    Gpio_TurnOff(PIN7);
    LONGS_EQUAL(ALL_OFF,fakeGpios);
}

TEST(GpioDriver, TurnOn_1_2_8_TurnOff_8_Gpio){
    Gpio_TurnOn(PIN0);
    Gpio_TurnOn(PIN1);
    Gpio_TurnOn(PIN7);
    LONGS_EQUAL(GPIO017_ON, fakeGpios);
    Gpio_TurnOff(PIN7);
    LONGS_EQUAL(GPIO01_ON, fakeGpios);
}