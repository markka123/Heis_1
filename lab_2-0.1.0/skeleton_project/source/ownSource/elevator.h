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
    Moving = 0,
    Stopped = 1,
    Idle = 2,
    EmergencyStop = 3,
} State;

typedef struct {
    int currentFloor;
    int lastFloor;
    State state;
    Door doors;
    time_t timeDoorsOpened;
} Elevator;

void handleOrder(Elevator* elevator, Order* order);
void setDirection(Elevator* elevator, int* current_floor);
void handleDoors(Elevator* elevator, Order* order);
void openDoor();
void closeDoor();
void idle();