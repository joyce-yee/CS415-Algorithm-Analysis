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
    
    string filenum = argv[1];
    if(filenum.length() == 1) {
        filenum = "0" + filenum;
    }

    // Note that if the prefix is 10, 
    // your code should be reading files p10*.txt and not p010*.txt
    string capacity = "KnapsackTestData/p" + filenum + "_c.txt";
    string weight = "KnapsackTestData/p" + filenum + "_w.txt";
    string values = "KnapsackTestData/p" + filenum + "_v.txt";

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
    cout << "File containing the capacity, weights, and values are: " 
         << capacity << " " << weight << " " << values << endl;
    cout << "Knapsack capacity = "       << capNum
         << ". Total number of items = " << numVals << endl;


    wei.close();
    cap.close();
    val.close();



    return 0;
}