#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include <stdio.h>
#include<set>
#include <algorithm>
#include "SmoooooothSort.h"
#include "Utils.h"

const int CHUNK_SIZE = 1000000;


void readChunk(int& unprocessed, vector<string>& data) {
    int currChunkSize = min(CHUNK_SIZE, unprocessed);
    data.resize(currChunkSize);

    for (int i = 0; i < currChunkSize; i++) {
        cin >> data[i];
    }

    unprocessed -= currChunkSize;
}


string getChunkFilename(int index) {
    return "sortedData/" + to_string(index) + ".txt";
}

void writeChunk(int index, vector<string>& data) {
    ofstream outputFile(getChunkFilename(index));

    for (int i = 0; i < data.size(); i++) {
        outputFile << data[i] << " ";
    }
    outputFile << "\n";
    outputFile.close();
}

void insertNext(ifstream& file, int index, set<pair<string, int>>& smallest) {
    string x;
    if (file >> x) {
        smallest.insert(make_pair(x, index));
    }
}

void writeOutput(ofstream& outputFile, vector<string>& data) {
    for (int i = 0; i < data.size(); i++) {
        outputFile << data[i] << " ";
    }
    outputFile << "\n";
}

void mergeChunks(int n) {
    ifstream files[n];
    set<pair<string, int>> smallest;
    vector<string> data;

    ofstream outputFile("sortedData/output.txt");

    for (int i = 0; i < n; i++) {
        files[i] = ifstream(getChunkFilename(i));
        insertNext(files[i], i, smallest);
    }

    while (smallest.size() > 0) {
        pair<string, int> next = *smallest.begin();
        smallest.erase(smallest.begin());

        data.push_back(next.first);

        if (data.size() % CHUNK_SIZE == 0) {
            writeOutput(outputFile, data);
            data.clear();
        }

        insertNext(files[next.second], next.second, smallest);
    }

    writeOutput(outputFile, data);
    data.clear();

    for (int i = 0; i < n; i++) {
        files[i].close();
    }
}


void runSort(){
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    int unprocessed = n, nChunks = 0;
    vector<string> data;
    SmoooooothSort Ssort(n);

    while (unprocessed > 0) {
        readChunk(unprocessed, data);
        Ssort.sort(data);
        writeChunk(nChunks, data);
        data.clear();
        nChunks++;
    }

    mergeChunks(nChunks);

//    for(int i = 0; i < n; i++){
//        cout << data[i] << " ";
//    }
//    cout << "\n";

}


int main() {

    ios_base::sync_with_stdio(false);
    Utils utils;
    utils.genAlphabet();
    vector<int> times;
    for(int i = 0; i < 1; i++) {
        utils.generateInput(100000);
        int time = utils.getTime(runSort);
        times.push_back(time);
       // cout << time << "\n";
    }
   // sort(times.begin(), times.end());
    cout << times[0] << " " << times.back();
    return 0;
}
