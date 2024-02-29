#pragma once
#include "../driver/elevio.h"

typedef struct {
    int floor;
    ButtonType btn;
} Order;

typedef struct {
    int size;
    Order orders[10];
} OrderArray;


//Functions
void initializeOrderArray (OrderArray* orders);
Order createOrder(int floor, int btn, OrderArray* orders);
void orderFinished(OrderArray* orders);
