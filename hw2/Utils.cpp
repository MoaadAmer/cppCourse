//
// Created by moaad on 4/20/2021.
//

#include "Utils.h"


int Utils::findMax(int arr[], int start, int end) {
    int max = arr[start];

    for (int i = start; i < end; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int Utils::max(int a, int b) {
    return a > b ? a : b;
}


