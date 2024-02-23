#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "ownSource/Order.h"
#include "ownSource/elevator.h"



int main(){
    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    // Order* lastOrder = (Order*)malloc(sizeof(Order));
    // lastOrder->btn = 2;
    // lastOrder->floor = 3;
    int currentFloor = 1;
    // int initialSize = 2;
    // Order** Orders = (Order**)malloc(initialSize * sizeof(Order*));
    // Orders[0] = lastOrder;
    //  //last element in Orders is always a zero pointer

    while(1){
        int _floor = elevio_floorSensor();
        if (_floor != -1) {
            currentFloor = _floor;
        }

        printf("%d", currentFloor);


        // handleOrder(*Orders[0], currentFloor);

        elevio_floorIndicator(currentFloor);

        // printf("Current Floor: %d, Last Order Floor: %d\n", currentFloor, lastOrder.floor);


            for(int f = 0; f < N_FLOORS; f++){
                for(int b = 0; b < N_BUTTONS; b++){
                    int btnPressed = elevio_callButton(f, b);
                    elevio_buttonLamp(f, b, btnPressed);
                    if(btnPressed != 0) {
                        // Order* orderToAdd = (Order*)malloc(sizeof(Order));
                        // *orderToAdd = createOrder(f, b);
                        // addOrder(&Orders, initialSize, orderToAdd);
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
