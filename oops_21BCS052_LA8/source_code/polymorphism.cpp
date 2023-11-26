#include <bits/stdc++.h>

#include "element_inherit_poly.h"
#include "sorting_algorithms.h"

using namespace std;

typedef void (*SortFunction)(Element *to_sort[], const int N);
double sortingExecutor(Element *to_sort[], const int N, SortFunction sortFunc,
                       bool toPrint = false) {
    auto start_time = chrono::high_resolution_clock::now();
    sortFunc(to_sort, N);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration =
        chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    if (toPrint) {
        for (int i = 0; i < N; i++) {
            to_sort[i]->print();
        }
    }
    return static_cast<double>(duration.count());
}

void performance_check(pair<int, pair<double, double>> size_time_relation[],
                       int size, bool toPrint = false) {
    pair<double, double> time_taken;
    for (int i = 0; i < size; i++) {
        const int N = size_time_relation[i].first;
        Element *to_sort1[N], *to_sort2[N];
        for (int i = 0; i < N; i++) {
            if (i % 3 == 0) {
                double x = rand_gen();
                double y = rand_gen();
                to_sort1[i] = new Point(x, y);
                to_sort2[i] = new Point(x, y);
            } else if (i % 3 == 1) {
                double x = rand_gen();
                double y = rand_gen();
                double z = rand_gen();
                to_sort1[i] = new Vector(x, y, z);
                to_sort2[i] = new Vector(x, y, z);
            } else {
                int dimension = rand() % 8 + 2;
                double *arr = new double[dimension];
                for (int i = 0; i < dimension; i++) {
                    arr[i] = rand_gen();
                }
                to_sort1[i] = new PointN(dimension, arr);
                to_sort2[i] = new PointN(dimension, arr);
            }
        }
        double slow_sort =
            sortingExecutor(to_sort1, size_time_relation[i].first,
                            SortFunctions::slow_sort, toPrint);
        double fast_memo =
            sortingExecutor(to_sort2, size_time_relation[i].first,
                            SortFunctions::fast_memo, toPrint);
        size_time_relation[i].second.first += slow_sort;
        size_time_relation[i].second.second += fast_memo;
    }
}

void test() {
    pair<int, pair<double, double>> size_time_relation_test[] = {{10, {0, 0}}};
    double slow_sort = 0, fast_memo = 0;
    performance_check(size_time_relation_test, 1, true);
}

int main() {
    cout << "\n Applying Memoization to the sorting algorithm\n";
    cout << __FILE__ << endl << endl;
    pair<int, pair<double, double>> size_time_relation[] = {
        {10, {0, 0}},   {100, {0, 0}},  {500, {0, 0}},
        {1000, {0, 0}}, {5000, {0, 0}}, {10000, {0, 0}}};
    int N = sizeof(size_time_relation) / sizeof(size_time_relation[0]);
    cout << "Average time taken running the executor 10 times\n";
    double slow_sort = 0, fast_memo = 0;
    int iterations = 10;
    while (iterations--) {
        performance_check(size_time_relation, N);
    }
    for (size_t i = 0; i < N; i++) {
        cout << "Size = " << size_time_relation[i].first << " | ";
        cout << "Average time taken by slow sort = "
             << size_time_relation[i].second.first / 10 << " µs | ";
        cout << "Average time taken by fast memoised sort = "
             << size_time_relation[i].second.second / 10 << " µs | ";
        cout << "Average speed ratio 1 / 2 = "
             << size_time_relation[i].second.first /
                    size_time_relation[i].second.second
             << endl;
        cout << endl;
        slow_sort += size_time_relation[i].second.first / 10;
        fast_memo += size_time_relation[i].second.second / 10;
    }
    cout << "Average time taken by slow sort = "
         << static_cast<long long>(slow_sort) << " µs | ";
    cout << "Average time taken by fast memoised sort = "
         << static_cast<long long>(fast_memo) << " µs | ";
    cout << endl;
    return 0;
}