#pragma once
#include "../driver/elevio.h"
#include "createOrder.h"
#include "elevator.h"


void reorderQueue(Elevator* elevator, Order* orders[]);