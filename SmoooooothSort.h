//
// Created by polli on 11/9/21.
//

#ifndef LAB_1_SMOOOOOOTHSORT_H
#define LAB_1_SMOOOOOOTHSORT_H

#include <vector>
#include <string>

using namespace std;

//extern vector<int> L;

struct Heap {
    int root;
    int order;

public:
    Heap(int root, int order);

    static void heapify(vector<string>& data, int root, int order);
    static int getL(int root, int order);
    static int getR(int root);
};

class SmoooooothSort {
    vector<Heap*> heaps;
    void restore(vector<string>& data);
    void appendEl(vector<string>& data, int ind);
public:
    SmoooooothSort(int n);
    void sort(vector<string>& data);

    void insertEl(vector<string>& data, int ind);
    std::string popMaxElement(vector<string>& data);
};


#endif //LAB_1_SMOOOOOOTHSORT_H
