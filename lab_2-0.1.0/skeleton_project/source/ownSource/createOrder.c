#include "createOrder.h"


Order createOrder(int floor, int btn) {
    Order o;
    o.floor = floor;
    o.btn = (whichButton)btn;
    return o;
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


