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
    
    // printf("=== Example Program ===\n");
    // printf("Press the stop button on the elevator panel to exit\n");

    OrderArray orders;
    initializeOrderArray(&orders);

    Elevator elevator = {0, 0, (State)Idle, (Door)Closed, time(NULL)};

    while(1){
        // int floor = elevio_floorSensor();
        // if (floor != -1) {
        //     elevator.currentFloor = floor;
        // }

        // Set the elevator direction up/down/stop

        // Update floor-indicator lamp
        elevio_floorIndicator(elevator.currentFloor);

        // // printf("Current Floor: %d, Last Order Floor: %d\n", currentFloor, lastOrder.floor);

        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                handleOrders(&elevator, &orders);
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
                if(btnPressed != 0) {
                    // printf("======\n");
                    createOrder(f, b, &orders); //returns an order
                    // for(int i = 0; i < orders.size; i++) {
                    //     // printf("Order floor: %d\n", orders.orderArr[i].floor);
                    //     // printf("Order btn: %d\n", orders.orderArr[i].btn);
                    // }
                    // printf("======\n");
                    // printf("Elevator current floor: %d\n", elevator.currentFloor);
                    // printf("Elevator last floor: %d\n", elevator.lastFloor);
                    // printf("Elevator state: %d\n", elevator.state);
                    // printf("Elevator doors: %d\n", elevator.doors);
                    // printf("NEW ORDER \n");
                }
            }
        }

        reorderQueue(&elevator, &orders);
        

        // // printf("Obstruction: %d\n", elevio_obstruction());
        
        checkForStop(&elevator, &orders);

    }

    return 0;
}
