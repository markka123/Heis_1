#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "ownSource/createOrder.h"
#include "ownSource/elevator.h"



int main(){
    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    int idleFloor = 1;
    OrderArray orders;
    initializeOrderArray(&orders);

    Order lastOrder = {idleFloor, 1};
    Elevator elevator = {0, 0, (State)Idle, (Door)Closed, time(NULL)};

    while(1){
        int floor = elevio_floorSensor();
        if (floor != -1) {
            elevator.currentFloor = floor;
        }

        // Set the elevator direction up/down/stop

        handleOrder(&elevator, &lastOrder);

        // Update floor-indicator lamp
        elevio_floorIndicator(elevator.currentFloor);

        // printf("Current Floor: %d, Last Order Floor: %d\n", currentFloor, lastOrder.floor);

        if (elevator.currentFloor == lastOrder.floor) {

            for(int f = 0; f < N_FLOORS; f++){
                for(int b = 0; b < N_BUTTONS; b++){
                    int btnPressed = elevio_callButton(f, b);
                    elevio_buttonLamp(f, b, btnPressed);
                    if(btnPressed != 0) {
                        lastOrder = createOrder(f, b, &orders); //returns an order
                        for(int i = 0; i < orders.size; i++) {
                            printf("Order floor: %d\n", orders.orders[i].floor);
                            printf("Order btn: %d\n", orders.orders[i].btn);
                        }
                        printf("NEW ORDER %d\n");
                    }

                }
            }
        }

        // printf("Obstruction: %d\n", elevio_obstruction());

        

        if(elevio_obstruction()){
            elevio_stopLamp(1);
            
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }

    }

    return 0;
}
