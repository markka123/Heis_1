#include "elevator.h"

void handleOrder(Order order, int current_floor) {
    if(current_floor == order.floor) {
        elevio_motorDirection(DIRN_STOP);
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