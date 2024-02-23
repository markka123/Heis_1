#include "Order.h"
#include <stdio.h>
#include <stdlib.h>


Order createOrder(int floor, int btn) {
    Order o;
    o.floor = floor;
    o.btn = (whichButton)btn;
    return o;
}

void removeOrder(Order** orders, int* size) {
    if(*size <= 1) {
        return;
    }
    free(orders[0]);
    for (int j = 0; j < *size - 1; j++) {
        orders[j] = orders[j + 1];
    }
    orders[*size-1] = NULL;
    (*size)--; // Update the array size
}

void addOrder(Order*** orders, int* size, Order* order) {
    (*size)++;
    *orders = realloc(*orders, (*size) * sizeof(Order*));
    if (*orders == NULL) {
        // Handle realloc failure
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    (*orders)[*size-2] = order;
}

void reorderOrder(Order** orders) {
    
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


