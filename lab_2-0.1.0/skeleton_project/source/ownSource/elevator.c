#include "elevator.h"
#include <time.h>

void handleOrder(Elevator* elevator, Order* order) {
    setDirection(&order->floor, &elevator->currentFloor);
    handleDoors(elevator, order);
}

void setDirection(int* orderedFloor, int* current_floor) {
    if(*current_floor == *orderedFloor) {
        elevio_motorDirection(DIRN_STOP);
    }

    else if (*current_floor > *orderedFloor) {
        elevio_motorDirection(DIRN_DOWN);
    }

    else if(*current_floor < *orderedFloor) {
        elevio_motorDirection(DIRN_UP);
    }
    else {
        printf("Could not handle order");
        elevio_motorDirection(DIRN_STOP);
    }
}

void openDoor() {
    elevio_doorOpenLamp(1);
}

void closeDoor() {
    elevio_doorOpenLamp(0);
}

void handleDoors(Elevator* elevator, Order* order) {
    if(order->floor == elevator->currentFloor) {
        if(elevator->doors == (Door)Closed) {
            openDoor();
            elevator->timeDoorsOpened = time(NULL);
            elevator->doors = (Door)Open;
        }
        else {
            time_t elapsed_time = time(NULL) - elevator->timeDoorsOpened;
            // printf(elapsed_time > 3 && !elevio_obstruction() && elevator->state != (State)Idle);
            if(elapsed_time > 3 && !elevio_obstruction() && elevator->state != (State)Idle) {
                closeDoor();
                elevator->state = (State)Idle;
            }
        }
    }
}