#include <bits/stdc++.h>

#include "element_inherit_poly.h"

using namespace std;

class SortFunctions {
   public:
    static void slow_sort(Element *to_sort[], const int N);
    static void fast_memo(Element *to_sort[], const int N);
};

void SortFunctions::slow_sort(Element *to_sort[], const int N) {
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

void SortFunctions::fast_memo(Element *to_sort[], const int N) {
    int i, j;
    double memo[N];
    for (size_t i = 0; i < N; i++) {
        memo[i] = to_sort[i]->norm();
    }

    for (i = 1; i < N; i++) {
        Element *key = to_sort[i];
        double memo_norm = memo[i];
        j = i - 1;
        while (j >= 0 && memo[j] > memo[i]) {
            to_sort[j + 1] = to_sort[j];
            memo[j] = memo[j + 1];
            j -= 1;
        }
        to_sort[j + 1] = key;
        memo[j + 1] = memo_norm;
    }
}