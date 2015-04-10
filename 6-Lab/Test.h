#ifndef TEST_H
#define TEST_H


class Test
{
    public:
        // Data points
        int* num_1;
        double* num_2;
        Test* next;
        Test* prev;
        // Constructors
        Test();
        Test(int num);
        Test(int num_1, double num_2);
        // Debug Print
        void print();

};

#endif // TEST_H
