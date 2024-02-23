#include "elevator.h"
#include <time.h>

void handleOrder(Order order, int current_floor) {
    if(current_floor == order.floor) {
        elevio_motorDirection(DIRN_STOP);
        elevio_doorOpenLamp(1);
        nanosleep(&(struct timespec){3, 0}, NULL);
        elevio_doorOpenLamp(0);
    }

    else if (current_floor > order.floor) {
        elevio_motorDirection(DIRN_DOWN);
    }

    else if(current_floor < order.floor) {
        elevio_motorDirection(DIRN_UP);
    }
    else {
        printf("Could not handle order");
        elevio_motorDirection(DIRN_STOP);
    }
}