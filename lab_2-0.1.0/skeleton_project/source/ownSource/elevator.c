#include "elevator.h"
#include <time.h>
#include "createOrder.h"

void handleOrders(Elevator* elevator, OrderArray* orders) {
    setDirection(elevator, &orders->orderArr[0].floor);
    handleDoors(elevator, orders);
}

void setDirection(Elevator* elevator, int* orderedFloor) {
    // Refresh currentFloor variable
    int floor = elevio_floorSensor();
    if (floor != -1) {
        elevator->currentFloor = floor;
    }
    // Check if the order is a real order
    if(*orderedFloor != -1) {
        // Set the direction of the elevator
        if(elevator->currentFloor == *orderedFloor) {
            elevio_motorDirection(DIRN_STOP);
            elevator->state = (State)Stopped;
        }
        // && elevator->doors == (Door)Closed
        else if (elevator->currentFloor > *orderedFloor) {
            elevio_motorDirection(DIRN_DOWN);
            elevator->state = (State)MovingDown;
        }

        else if(elevator->currentFloor < *orderedFloor ) {
            elevio_motorDirection(DIRN_UP);
            elevator->state = (State)MovingUp;
        }
    }
    else {
        elevator->state = (State)Idle;
    }
}

void openDoor() {
    elevio_doorOpenLamp(1);
}

void closeDoor() {
    elevio_doorOpenLamp(0);
}

void handleDoors(Elevator* elevator, OrderArray* orders) {
    // Handle doors if the elevator is in state 
    if(elevator->state == (State)Stopped) {
        if(elevator-> doors == (Door)Closed && elevator->state == (State)Stopped) {
            // printf("Opened door \n");
            openDoor();
            elevator->timeDoorsOpened = time(NULL);
            elevator->doors = (Door)Open;
        }
        else {
            time_t elapsed_time = time(NULL) - elevator->timeDoorsOpened;
            // // printf(elapsed_time > 3 && !elevio_obstruction() && elevator->state != (State)Idle);
            if(elapsed_time > 3 && !elevio_obstruction()) {
                closeDoor();
                elevator->doors = (Door)Closed;
                elevator->state = (State)Idle;
                orderFinished(orders);
            }
        }
    }
}