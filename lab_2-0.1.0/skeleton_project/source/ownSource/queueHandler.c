#include "queueHandler.h"

void reorderQueue(Elevator* elevator, OrderArray* orderArray) {

    Order* currentOrder = &orderArray->orderArr[0]; 
    for(int i = 1; i < orderArray->size; i++) {
        Order o = orderArray->orderArr[i];
        // If elevator is moving up, check for people between 
        // current floor and ordered floor that are also going up
        
        if(elevator->state == (State)MovingUp && (o.btn == (ButtonType)BUTTON_HALL_UP || o.btn == (ButtonType)BUTTON_CAB)) {
            if(elevator->currentFloor < o.floor && o.floor < currentOrder->floor) {
                if(orderArray->size == 2) {
                    orderArray->orderArr[1].btn = orderArray->orderArr[0].btn;
                    orderArray->orderArr[1].floor = orderArray->orderArr[0].floor;
                }
                else {
                    for(int i = orderArray->size - 2; i >= 0; i--) {
                        orderArray->orderArr[i+1].btn = orderArray->orderArr[i].btn;
                        orderArray->orderArr[i+1].floor = orderArray->orderArr[i].floor;
                    }
                }
                orderArray->orderArr[0] = o;
            }
        }
        //If elevator is moving down, check for people between 
        //current floor and ordered floor that are also going down
        else if(elevator->state == (State)MovingDown && (o.btn == (ButtonType)BUTTON_HALL_DOWN || o.btn == (ButtonType)BUTTON_CAB)) {
            if(elevator->currentFloor > o.floor && o.floor > currentOrder->floor) {
                if(orderArray->size == 2) {
                    orderArray->orderArr[1].btn = orderArray->orderArr[0].btn;
                    orderArray->orderArr[1].floor = orderArray->orderArr[0].floor;
                }
                else {
                    for(int i = orderArray->size - 2; i >= 0; i--) {
                        orderArray->orderArr[i+1].btn = orderArray->orderArr[i].btn;
                        orderArray->orderArr[i+1].floor = orderArray->orderArr[i].floor;
                    }
                }
                orderArray->orderArr[0] = o;
            }
        }   
    }

}