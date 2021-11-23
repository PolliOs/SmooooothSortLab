#include "SmoooooothSort.h"
#include "Utils.h"
#include <iostream>
#include <vector>
#include <fstream>

void readData(std::vector<std::string>& data, int& n){
    std::ifstream inputFile("input.txt");

    inputFile >> n;
    data.resize(n);

    for (int i = 0; i < n; i++) {
        inputFile >> data[i];
    }

    inputFile.close();
}

void writeData(std::vector<std::string>& data){
    std::ofstream outputFile("output.txt");

    outputFile << data.size() << "\n";

    for (int i = 0; i < data.size(); i++) {
        outputFile << data[i] << " ";
    }

    outputFile.close();
}


void sort() {
    std::vector<std::string> data;
    int n;
    readData(data, n);
    SmoooooothSort sorter(n);
    sorter.sort(data);
    writeData(data);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    Utils utils;
    utils.genAlphabet();
    utils.generateInput(100000);
    int time = utils.getTime(sort);
    std::cout << time << " ";

    return 0;
}