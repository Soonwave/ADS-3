// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int collatzLen(uint64_t num) {
    int len = 1;
    while (num != 1) {
        if (num % 2 == 0) num /= 2;
        else num = 3 * num + 1;
        len++;
    }
    return len;
}
uint64_t collatzMaxValue(uint64_t num) {
    int max = num;
    while (num != 1) {
        if (num % 2 == 0) num /= 2;
        else num = 3 * num + 1;
        if (num > max) max = num;
    }
    return max;
}

unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int bestlen = 1;
    unsigned int bestnum = 1;
    for (uint64_t i = lbound; i <= rbound; i++) {
        unsigned int currentlen = collatzLen(i);
        if (currentlen > bestlen) {
            bestlen = currentlen;
            bestnum = i;
        }
     }
    *maxlen = bestlen;
    return bestnum;
}
