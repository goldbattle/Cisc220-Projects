#include <iostream>
#include "NodeTY.h"

NodeTY::NodeTY() {
    NodeTY("Empty");
}

NodeTY::NodeTY(string str) {
    data = str;
    left = NULL;
    right = NULL;
}
