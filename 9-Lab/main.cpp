#include <cmath>
#include <iostream>

using namespace std;

void print_array(int* arr, int len);

int main() {

    //a
    // The array should be of size twitce the amount of elements
    // and a prime number
    // For our 20 items, we should chose 41


    // b
    // Could use the "golden" ratio
    // [(1+sqrt(5))/2*number] % array_length
    // Could also use a natural log to degrees super large numbers
    // ln(number) % array_length

    // c
    int nums[] = {3413, 3869, 1897, 3346, 4325, 1657, 1, 2199, 1411, 874, 4323, 2759, 2457, 4071, 1236, 2156, 1610, 4538, 2161, 4632};

    // My golden
    int collisions = 0;
    int hashed_0[41] = {0};
    for(int i=0; i<20; i++) {
        // Calculate
        int d = floor((1+sqrt(5))/2*nums[i]);
        // Add collision
        if(hashed_0[d % 41] != 0) {
            collisions++;
        }
        // Insert
        hashed_0[d % 41] = nums[i];
    }
    // Print
    print_array(hashed_0, 41);
    cout << "Collisions: " << collisions << endl << endl;

    // My log
    collisions = 0;
    int hashed_1[41] = {0};
    for(int i=0; i<20; i++) {
        // Calculate
        int d = floor(log(nums[i]));
        // Add collision
        if(hashed_1[d % 41] != 0) {
            collisions++;
        }
        // Insert
        hashed_1[d % 41] = nums[i];
    }
    // Print
    print_array(hashed_1, 41);
    cout << "Collisions: " << collisions << endl << endl;

    // In class
    collisions = 0;
    int hashed_2[41] = {0};
    for(int i=0; i<20; i++) {
        // Calculate
        double c = (sqrt(5) - 1)/2;
        int d = floor(41 * ((nums[i]*c) - floor(nums[i]*c)));
        // Add collision
        if(hashed_2[d % 41] != 0) {
            collisions++;
        }
        // Insert
        hashed_2[d % 41] = nums[i];
    }
    // Print
    print_array(hashed_2, 41);
    cout << "Collisions: " << collisions << endl << endl;


    // Linear probing
    int nums2[] = {560,671,353,502,490,757,38,410,904,93,818,577,3,671};
    collisions = 0;
    int hashed_3[29] = {0};
    for(int i=0; i<20; i++) {
        // Calculate
        int d = floor(nums[i]/29);
        // Add collision
        while(hashed_3[d % 29] != 0) {
            collisions++;
            cout << "Probing from " << d << " to ";
            d++;
            cout << d << endl;
        }
        // Insert
        hashed_3[d % 29] = nums[i];
    }
    // Print
    print_array(hashed_3, 29);
    cout << "Collisions: " << collisions << endl << endl;

    // Double hashing with probing
    collisions = 0;
    int hashed_4[29] = {0};
    for(int i=0; i<20; i++) {
        // Calculate
        int d = floor(nums[i]/29);
        // Add collision
        int prob_count = 1;
        while(hashed_4[d % 29] != 0) {
            collisions++;
            cout << "Probing from " << d << " to ";
            d = floor(nums[i]/29) + prob_count*(1+nums[i]%7);
            cout << d << endl;
            prob_count++;
        }
        // Insert
        hashed_4[d % 29] = nums[i];
    }
    // Print
    print_array(hashed_3, 29);
    cout << "Collisions: " << collisions << endl << endl;

}


void print_array(int* arr, int len) {
    for(int i=0; i<len; i++) {
        cout << arr[i] << " | ";
    }
    cout << endl;
}
