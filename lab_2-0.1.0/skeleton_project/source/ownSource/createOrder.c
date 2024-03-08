#include "createOrder.h"


void initializeOrderArray (OrderArray* orders) {
    orders->size = 0;
    for(int i = 0; i < 10; i++) {
        Order o = {-1, (ButtonType)0};
        orders->orderArr[i] = o;

    }
    for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                elevio_buttonLamp(f, b, 0);
            }
    }
}


void createOrder(int floor, int btn, OrderArray* orders) {
    Order o;
    o.floor = floor;
    o.btn = (ButtonType)btn;
    int found = 0;
        

    for(int i = 0; i < orders->size; i++) {
        if(o.btn == orders->orderArr[i].btn && o.floor == orders->orderArr[i].floor) {
            found = 1;
            break;
        }
    }
    if(!found) {
        elevio_buttonLamp(o.floor, o.btn, 1);
        orders->size++;
        
        orders->orderArr[orders->size-1] = o;

    }
}

void orderFinished(OrderArray* orders) {
    if(orders->orderArr[0].floor != -1) {
        elevio_buttonLamp(orders->orderArr[0].floor, orders->orderArr[0].btn, 0);
    }
    
    for(int i = 0; i < orders->size-1; i++) {
            orders->orderArr[i].btn = orders->orderArr[i+1].btn;
            orders->orderArr[i].floor = orders->orderArr[i+1].floor;
        }
    Order o = {-1, (ButtonType)0};

    orders->orderArr[orders->size - 1] = o;
    orders->size --;
}
