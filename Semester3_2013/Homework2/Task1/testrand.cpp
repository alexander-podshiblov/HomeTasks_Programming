#include "testrand.h"

int TestRand::numbers[9] = {8, 4, 1, 3, 9, 5, 6, 7, 0};
TestRand::TestRand()
{
    i = -1;
}
int TestRand::rand()
{
    i++;
    if (i >= 9)
        i = 0;
    return numbers[i];
}
