#include "queueHandler.h"

void reorderQueue(Elevator* elevator, OrderArray* orderArray) {
    int found = 0;
    Order* currentOrder = &orderArray->orderArr[0]; 
    for(int i = 1; i < orderArray->size; i++) {
        Order* o = &orderArray->orderArr[i];
        // If elevator is moving up, check for people between 
        // current floor and ordered floor  that are also going up
        if(elevator->state == (State)MovingUp && o->btn == (ButtonType)BUTTON_HALL_UP) {
            if(elevator->currentFloor < o->floor && o->floor < currentOrder->floor) {
                for(int i = orderArray->size - 2; i >= 0; i--) {
                    orderArray->orderArr[i+1].btn = orderArray->orderArr[i].btn;
                    orderArray->orderArr[i+1].floor = orderArray->orderArr[i].floor;
                }
            }
        }
        // If elevator is moving down, check for people between 
        // current floor and ordered floor that are also going down
        else if(elevator->state == (State)MovingUp && o->btn == (ButtonType)BUTTON_HALL_DOWN) {
            if(elevator->currentFloor > o->floor && o->floor > currentOrder->floor) {
                for(int i = orderArray->size - 2; i >= 0; i--) {
                    orderArray->orderArr[i+1].btn = orderArray->orderArr[i].btn;
                    orderArray->orderArr[i+1].floor = orderArray->orderArr[i].floor;
                }
            }
        }   
        orderArray->orderArr[0] = *o;
    }

}