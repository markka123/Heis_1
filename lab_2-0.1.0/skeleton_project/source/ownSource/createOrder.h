#pragma once
#include "../driver/elevio.h"
typedef enum {
    Up = 0,
    Down = 1,
    Cab = 2,
} whichButton;

typedef struct {
    int floor;
    whichButton btn;
} Order;

Order createOrder(int floor, int btn);
