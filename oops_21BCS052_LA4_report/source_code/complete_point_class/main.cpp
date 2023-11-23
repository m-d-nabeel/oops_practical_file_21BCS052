#include <bits/stdc++.h>

#include <chrono>

#include "points_header.h"
using namespace std;
#define PRIME 4354773

void insertionSort(vector<Point> &arr, int n) {
    int i, j;
    Point key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/**
 * Performs performance testing on the insertionSort function.
 * The function tests the sorting performance for different array sizes.
 * It measures the time taken to sort the array and prints the results.
 */
void checkPerformance() {
    cout << "checkPerformance function" << endl;
    int arraySize[] = {100, 200, 300,  400,  500,   600,  700,
                       800, 900, 1000, 5000, 10000, 50000};
    for (int i = 0; i < sizeof(arraySize) / sizeof(arraySize[0]); i++) {
        long long size = arraySize[i];
        vector<Point> v(size);
        for (int i = 0; i < size; i++) {
            v[i].setCoords(rand() % PRIME, rand() % PRIME);
        }
        cout << "Array Size = " << size << endl;
        auto start_time = chrono::high_resolution_clock::now();
        insertionSort(v, size);
        auto end_time = chrono::high_resolution_clock::now();
        auto duration =
            chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        cout << "Time = " << duration.count() << " \xC2\xB5s"
             << " ≡ "
             << static_cast<double>(duration.count() * 1000) / (size * size)
             << " K (constant)" << endl;
        for (int i = 0; i < v.size() && v.size() == 10; i++) {
            cout << v[i] << endl;
        }
    }
}

void checkPostfix(Point p) {
    cout << "checkPostfix function" << endl;
    cout << "Postfix = " << p++ << endl;
    cout << "After = " << p << endl;
}

void checkPrefix(Point p) {
    cout << "checkPrefix function" << endl;
    cout << "Prefix = " << ++p << endl;
    cout << "After = " << p << endl;
}

void checkIfPrivateCanBeAccessedDirectly() {
    cout << "checkIfPrivateCanBeAccessedDirectly function" << endl;
    Point p1(1, 1);
    cout << p1 << endl;

    double *ptr = (double *)((void *)&p1);
    cout << ptr << endl;

    (*ptr) = 1.6845;
    ptr++;
    (*ptr) = 2.6554;

    cout << p1 << endl;
}

int main() {
    cout << __FILE__ << endl;
    cout << "main function" << endl;
    Point p1(1, 1);
    Point p2(2.6, -2);
    Point p3;
    p3 = p2 = p1;
    cout << "lNorm P1 = " << p1.l2Norm() << endl;
    cout << "lNorm P2 = " << p2.l2Norm() << endl;
    cout << p2 << endl;
    cout << p2[X_VALUE] << endl;
    p2[Y_VALUE] = 7;
    p2.printCoords();

    // CHECKINGS ===>>>
    checkPerformance();
    checkPostfix(p1);
    checkPrefix(p1);
    checkIfPrivateCanBeAccessedDirectly();

    cout << endl;

    return 0;
}
