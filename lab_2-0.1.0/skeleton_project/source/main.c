#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "ownSource/createOrder.h"
#include "ownSource/elevator.h"
#include "ownSource/queueHandler.h"


int main(){
    elevio_init();
    
    // printf("=== The real shit ===\n");

    OrderArray orders;
    initializeOrderArray(&orders);
    Elevator elevator = {0, (State)Idle, (Door)Closed, time(NULL)};

    createOrder(0, 0, &orders);
    while(orders.size > 0) {
        handleOrders(&elevator, &orders);
    }
    while(1){

        // Update floor-indicator lamp
        elevio_floorIndicator(elevator.currentFloor);
        if( elevator.state != (State)EmergencyStop) {
            for(int f = 0; f < N_FLOORS; f++){
                for(int b = 0; b < N_BUTTONS; b++){
                    handleOrders(&elevator, &orders);
                    
                    int btnPressed = elevio_callButton(f, b);
                    
                    if(btnPressed != 0) {
                        
                        createOrder(f, b, &orders); //returns an order
                        
                    }
                }
            }
            reorderQueue(&elevator, &orders);
        }

        checkForStop(&elevator, &orders);

    }

    return 0;
}
