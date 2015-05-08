#ifndef HEAPA_H
#define HEAPA_H

class HeapA {

    int* data;
    int length;
    int cur_pos;

    public:
        HeapA(int len);
        void insert(int num);
        int pop_heap();
        void print_heap();
    private:
        void bubble_up(int num);
        void bubble_down(int num);
};

#endif // HEAPA_H
