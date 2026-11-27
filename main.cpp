#include <iostream>
#include "dynamic.hpp"
#include "greed.hpp"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

bool readCapacity(const string& filename, int& capacity);
bool readValues(const string& filename, vector<int> &values);
int main(int argc, char *argv[]){

    if(argc != 2){
        cerr << "Usage: " << argv[0] << " <test number>\n";
        return -1;
    }
    
    string fileNum = argv[1];
    if(fileNum.length() == 1) {
        fileNum = "0" + fileNum;
    }

    string filePrefix = "KnapsackTestData/p" + fileNum;
    int capacity;
    vector<int> weights, values;
    if (!readCapacity(filePrefix + "_c.txt", capacity)) {
        return 1;
    }

    if (!readValues(filePrefix + "_w.txt", weights)) {
        return 1;
    }
    if (!readValues(filePrefix + "_v.txt", values)) {
        return 1;
    }
    if (weights.size() != values.size()) {
        return 2;
    }

    cout << "File containing the capacity, weights, and values are: " 
         << filePrefix << "_c.txt, " 
         << filePrefix << "_w.txt, and " 
         << filePrefix << "_v.txt\n";
    cout << "Knapsack capacity = " << capacity
         << ". Total number of items = " << values.size() << endl;

    return 0;
}

bool readCapacity(const string &filename, int &capacity) {
    ifstream cap;
    cap.open(filename);
    // Opened properly
    if (!cap.is_open()) {
        cerr << "Could not open file " << filename << endl;
        return false;
    }

    cap >> capacity;

    // Read properly
    if(!cap) {
        cerr << "Could not read capacity from file " << filename << endl;
        return false;
    }
    return true;
}

bool readValues(const string &filename, vector<int> &values) {
    values.clear();

    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cerr << "Could not open file " << filename << endl;
        return false;
    }

    int temp;
    while (file >> temp) {
        values.push_back(temp);
    }
    return file.eof();
}
