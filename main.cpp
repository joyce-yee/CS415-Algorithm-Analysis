#include <iostream>
#include "dynamic.hpp"
#include "greed.hpp"
#include <vector>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char *argv[]){

    if(argc != 2){
        cerr << "Usage: " << argv[0] << " <filename> \n";
        return -1;
    }
    const string filenum = argv[1];

    string capacity = "KnapsackTestData/p0" + filenum + "_c.txt";
    string weight = "KnapsackTestData/p0" + filenum + "_w.txt";
    string values = "KnapsackTestData/p0" + filenum + "_v.txt";

    ifstream cap;
    ifstream wei;
    ifstream val;

    cap.open(capacity);
    if (!cap.is_open()) {
        cerr << "Could not open file " << capacity << endl;
        return -1;
    }
    wei.open(weight);
    if (!wei.is_open()) {
        cerr << "Could not open file " << weight << endl;
        return -1;
    }
    val.open(values);
    if (!val.is_open()) {
        cerr << "Could not open file " << values << endl;
        return -1;
    }
    int capNum;
    cap >> capNum;
    int numVals;
    int value;
    while(val >> value){
        numVals++;
    }

    cout << "Knapsack capacity = "       << capNum
         << ". Total number of items = " << numVals << "\n";


    wei.close();
    cap.close();
    val.close();



    return 0;
}