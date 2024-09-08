#include "Random.h"

int random(int min, int max)
{
    int r = floor(((double)rand() / RAND_MAX) * (max - min + 1) + min);
    return r;
}