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
    MovingUp = 0,
    MovingDown = 1,
    Stopped = 2,
    Idle = 3,
    EmergencyStop = 4,
} State;

typedef struct {
    int currentFloor;
    int lastFloor;
    State state;
    Door doors;
    time_t timeDoorsOpened;
} Elevator;

void handleOrders(Elevator* elevator, OrderArray* orders);
void setDirection(Elevator* elevator, int* current_floor);
void handleDoors(Elevator* elevator, OrderArray* orders);
void openDoor();
void closeDoor();
void idle();

void checkForStop(Elevator* elevator, OrderArray* orders);