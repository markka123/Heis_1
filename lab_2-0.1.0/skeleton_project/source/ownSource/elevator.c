#include "elevator.h"
#include <time.h>

void handleOrder(Elevator* elevator, Order* order) {
    setDirection(elevator, &order->floor);
    handleDoors(elevator, order);
}

void setDirection(Elevator* elevator, int* orderedFloor) {
    if(orderedFloor = -1) {
        if(elevator->currentFloor == *orderedFloor) {
            elevio_motorDirection(DIRN_STOP);
            elevator->state = (State)Stopped;
        }

        else if (elevator->currentFloor > *orderedFloor && elevator->doors == (Door)Closed) {
            elevio_motorDirection(DIRN_DOWN);
            elevator->state = (State)Moving;
        }

        else if(elevator->currentFloor < *orderedFloor && elevator->doors == (Door)Closed) {
            elevio_motorDirection(DIRN_UP);
            elevator->state = (State)Moving;
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

void handleDoors(Elevator* elevator, Order* order) {
    if(order->floor == elevator->currentFloor && elevator->state == (State)Stopped) {
        if(elevator->doors == (Door)Closed) {
            openDoor();
            elevator->timeDoorsOpened = time(NULL);
            elevator->doors = (Door)Open;
        }
        else {
            time_t elapsed_time = time(NULL) - elevator->timeDoorsOpened;
            // printf(elapsed_time > 3 && !elevio_obstruction() && elevator->state != (State)Idle);
            if(elapsed_time > 3 && !elevio_obstruction()) {
                closeDoor();
                elevator->doors = (Door)Closed;
                // Delete order
                // or set to idle
            }
        }
    }
}