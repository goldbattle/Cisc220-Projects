#include <iostream>
#include "NodeTY.h"

NodeTY::NodeTY() {
    NodeTY("Empty");
}

NodeTY::NodeTY(string str) {
    data = str;
    bal = 0;
    left = NULL;
    right = NULL;
}
