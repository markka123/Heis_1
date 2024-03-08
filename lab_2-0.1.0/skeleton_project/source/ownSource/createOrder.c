#include "createOrder.h"


void initializeOrderArray (OrderArray* orders) {
    orders->size = 0;
    for(int i = 0; i < 10; i++) {
        Order o = {-1, (ButtonType)0};
        orders->orderArr[i] = o;
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
        
        orders->size++;
        
        orders->orderArr[orders->size-1] = o;

       
        // for(int i = 8; i >= 0; i--) {
        //     orders->orderArr[i+1].btn = orders->orderArr[i].btn;
        //     orders->orderArr[i+1].floor = orders->orderArr[i].floor;
        // }
        // orders->orderArr[0] = o;
    }

}




void orderFinished(OrderArray* orders) {
    for(int i = 0; i < 9; i++) {
            orders->orderArr[i].btn = orders->orderArr[i+1].btn;
            orders->orderArr[i].floor = orders->orderArr[i+1].floor;
        }
    Order o = {-1, (ButtonType)0};
    orders->orderArr[9] = o;
    orders->size --;
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


