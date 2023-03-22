#include "CppUTest/TestHarness.h"

extern "C" {
    #include "swap.h"
}

// Create a test group
TEST_GROUP(Swap)
{
    void setup()
    {
        // Initialize before each test
    }
    
    void teardown()
    {
        // Deinitialize after each test
    }
};

TEST(Swap, Swap_correctly){
    int int1 = 0;
    int int2 = 10;
    int intial_first_arg = int1;
    int intial_second_arg = int2;
    swap(&int1, &int2);
    CHECK_EQUAL(intial_second_arg, int1);
    CHECK_EQUAL(intial_first_arg, int2);
}
