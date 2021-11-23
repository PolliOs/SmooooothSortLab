//
// Created by polli on 11/21/21.
//

#ifndef LAB_1_UTILS_H
#define LAB_1_UTILS_H

#include <vector>

using namespace std;

class Utils {
    vector<char> alphabet;
public:
    void generateInput(int n);
    void genAlphabet();
    double getTime(void(* f)());

};


#endif //LAB_1_UTILS_H
