#pragma once
#include "../driver/elevio.h"

typedef struct {
    int floor;
    ButtonType btn;
} Order;

typedef struct {
    int size;
    Order orderArr[10];
} OrderArray;


//Functions
void initializeOrderArray (OrderArray* orders);
void createOrder(int floor, int btn, OrderArray* orders);
void orderFinished(OrderArray* orders);
