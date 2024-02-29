#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "../driver/elevio.h"
#include "createOrder.h"

typedef enum {
    Closed = 1,
    Open = 0
} Door;

typedef enum {
    Running = 0,
    Idle = 1,
    Stopped = 2,
} State;

typedef struct {
    int currentFloor;
    int lastFloor;
    State state;
    Door doors;
    time_t timeDoorsOpened;
} Elevator;

void handleOrder(Elevator* elevator, Order* order);
void setDirection(int* ordered_floor, int* current_floor);
void handleDoors(Elevator* elevator, Order* order);
void openDoor();
void closeDoor();
void idle();