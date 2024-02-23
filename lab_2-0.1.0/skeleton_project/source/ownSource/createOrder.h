#include "source/driver/elevio.h"
enum whichButton {
    Up = 0,
    Down = 1,
    Cab = 2,
};

typedef struct {
    int floor;
    whichButton btn;
} Order;

Order createOrder(int floor, int btn);
