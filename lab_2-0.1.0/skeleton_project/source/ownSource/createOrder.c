#include "createOrder.h"


Order createOrder(int floor, int btn, OrderArray* orders) {
    Order o;
    o.floor = floor;
    o.btn = (ButtonType)btn;
    int found = 0;
    for(int i = 0; i < 10; i++) {
        if(o.btn == orders->orders[i].btn && o.floor == orders->orders[i].floor) {
            found = 1;
            break;
        }
    }
    if(!found) {
        if(orders->size < 10) {
            orders->size++;
        }
        for(int i = 8; i >= 0; i--) {
            orders->orders[i+1].btn = orders->orders[i].btn;
            orders->orders[i+1].floor = orders->orders[i].floor;
        }
        orders->orders[0] = o;
    }

    return o;
}


void initializeOrderArray (OrderArray* orders) {
    orders->size = 0;
    for(int i = 0; i < 10; i++) {
        orders->orders[i].floor = -1;
    }
}
//mulig å bruke
// Order orderCreated() {
//     for(int f = 0; f < N_FLOORS; f++){
//             for(int b = 0; b < N_BUTTONS; b++){
//                 int btnPressed = elevio_callButton(f, b);
//                 if(btnPressed != 0) {
//                     return createOrder(f, b); //returns an order
//                 }

//             }
//         }
// }


