#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "./driver/elevio.h"

typedef struct {
    int floor;
    ButtonType btn;
} Order;

void handleOrder(Order order, int current_floor);


