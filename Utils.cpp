//
// Created by polli on 11/21/21.
//

#include "Utils.h"

#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include <stdio.h>
#include <chrono>

void Utils::generateInput(int n){
        ofstream inputFile("input.txt");
        srand (time(NULL));

        int r;
        inputFile << n << "\n";

        vector<string> sortedData;
        for(int i = 0; i < n; i++){
            r = rand() % 100000 + 1;
            string str = "";
            if(!(r%7)){
                str += alphabet[r%alphabet.size()];
                str += alphabet[(r*270)%alphabet.size()];
                str += alphabet[(r+348)%alphabet.size()];
            }
            str += to_string(r);
            sortedData.push_back(str);
        }
        // sort(sortedData.begin(), sortedData.end());
        for(auto v:sortedData){
            inputFile << v << " ";
        }
        inputFile.close();
}

void Utils::genAlphabet() {
    alphabet.clear();
    for(char c = 48; c < 58; c++){
        alphabet.push_back(c);
    }
    for(char c = 65; c < 91; c++){
        alphabet.push_back(c);
    }
    for(char c = 97; c < 123; c++){
        alphabet.push_back(c);
    }
}

double Utils::getTime(void(* f)()) {
    auto start = chrono::steady_clock::now();
    f();
    auto end = chrono::steady_clock::now();
    auto elapsed =  chrono::duration_cast< chrono::milliseconds>(end - start);
    return elapsed.count();
}