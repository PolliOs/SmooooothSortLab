//
// Created by polli on 11/9/21.
//

#include "SmoooooothSort.h"


Heap::Heap(int root, int order): root(root), order(order) {}

vector<int> L;

void initLeonardoNumbers(int max_sum) {
    long long sum = 2;
    L.push_back(1);
    L.push_back(1);
    int pr1 = 1, pr2 = 1, next;
    while (sum < max_sum) {
        next = pr1 + pr2 + 1;
        L.push_back(next);
        sum += next;
        pr2 = pr1;
        pr1 = next;
    }
    //cout << "l.size = " << L.size() << "\n";
}

string maxStr(string a, string b){
    if(a.compare(b) < 0){
        return b;
    }
    return  a;
}

int Heap::getR(int root) {{
        return root-1;
}}

int Heap::getL(int root, int order) {
    return root - L[order - 2] - 1;
}

void Heap::heapify(vector<string> &data, int root, int order) {
    if(order < 2) return;

    int r = Heap::getR(root);
    int l = Heap::getL(root, order);

    string _max = maxStr(maxStr(data[r], data[l]), data[root]);

    if(_max == data[root]){
        // don't need to reorder
        return;
    }

    if(_max == data[r]){
        swap(data[r], data[root]);
        // check the heap with new swapped root
        heapify(data, r, order - 2);
        return;
    }

    // last case
    swap(data[l], data[root]);
    heapify(data, l, order - 1);
}


void SmoooooothSort::appendEl(vector<string> &data, int ind) {
    int n = heaps.size() - 1;

    if(n > 0 && heaps[n]->order + 1 == heaps[n-1] -> order){
        int newOrder = heaps[n]->order+2;

        heaps.pop_back();
        heaps.pop_back();

        heaps.push_back(new Heap(ind, newOrder));
        return;
    }

    if(n >= 0 && heaps[n]->order == 1){
        heaps.push_back(new Heap(ind, 0));
        return;
    }

    heaps.push_back(new Heap(ind, 1));
}


void SmoooooothSort::restore(vector<string> &data) {
    int curr = heaps.size() - 1;

    while(curr > 0){
        int root = heaps[curr]->root;
        int order = heaps[curr]->order;

        int prev = heaps[curr-1]->root;

        string _max = maxStr(data[root], data[prev]);

        if(heaps[curr]->order > 1) {
            int l = Heap::getL(root, order);
            int r = Heap::getR(root);
            _max = maxStr(_max, maxStr(data[l], data[r]));
        }

        if(_max != data[prev]){
            break;
        }

        swap(data[prev], data[root]);
        curr--;
    }

    Heap::heapify(data, heaps[curr]->root, heaps[curr]->order);
}

void SmoooooothSort::insertEl(vector<string> &data, int ind) {
    this->appendEl(data, ind);
    this->restore(data);
}

string SmoooooothSort::popMaxElement(vector<string> &data) {
    int curr = heaps.size() - 1;
    int root = heaps[curr]->root;
    string res = data[root];

    if(heaps[curr]->order < 2) {
        heaps.pop_back();
        return res;
    }

    int order = heaps[curr]->order;
    int  l = Heap::getL(root, order);
    int r = Heap::getR(root);

    heaps.pop_back();

    heaps.push_back(new Heap(l, order - 1));
    this->restore(data);

    heaps.push_back(new Heap(r, order-2));
    this->restore(data);
    res = data[root];
    return res;
}

SmoooooothSort::SmoooooothSort(int n) {
    initLeonardoNumbers(n);
}

void SmoooooothSort::sort(vector<string> &data) {
    for(int i = 0; i < data.size(); i++){
        insertEl(data,i);
    }

    for(int i = 0; i < data.size(); i++){
        popMaxElement(data);
    }



}