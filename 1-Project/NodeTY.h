#ifndef NODETY_H_INCLUDED
#define NODETY_H_INCLUDED
#include <string>

using namespace std;

class NodeTY {

    friend class BSTY;

    NodeTY* left;
    NodeTY* right;

    string data;

    public:
        NodeTY();
        NodeTY(string str);

};

#endif // NODETY_H_INCLUDED
