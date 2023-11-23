#include <bits/stdc++.h>

#include "element_inherit_poly.h"

using namespace std;

class SortFunctions {
   public:
    static void sort_algo_1(Element *to_sort[], const int N);
    static void sort_algo_2(Element *to_sort[], const int N);
    static void sort_algo_3(Element *to_sort[], const int N);
};

void SortFunctions::sort_algo_1(Element *to_sort[], const int N) {
    int i, j;
    Element *key = nullptr;
    for (i = 1; i < N; i++) {
        key = to_sort[i];
        j = i - 1;
        while (j >= 0 && to_sort[j]->norm() > key->norm()) {
            to_sort[j + 1] = to_sort[j];
            j -= 1;
        }
        to_sort[j + 1] = key;
    }
}

void SortFunctions::sort_algo_2(Element *to_sort[], const int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (to_sort[j]->norm() > to_sort[j + 1]->norm()) {
                Element *temp = to_sort[j];
                to_sort[j] = to_sort[j + 1];
                to_sort[j + 1] = temp;
            }
        }
    }
}