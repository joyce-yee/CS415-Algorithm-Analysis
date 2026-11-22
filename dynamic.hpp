#ifndef DYNAMIC_H
#define DYNAMIC_H
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <tuple>
using namespace std;


//2D array of tupples with all values added and inserted 

struct KnapsackResult { 
    int optimalVal;
    vector<int> selectedItems;
    int basicOperations;
}



struct HashEntry{
    int item;
    int remainingCapacity;
    int value;

    //use to point to next entry in same bucket
    //used when mult keys hash to same bucket
    HashEntry * next;
}

class Traditional{
public: 
    Traditional(const vector<int>& values, const vector<int>& weights, int capacity);
    //fill tabnle and returns final result
    KnapsackResult solve();

private:
    vector<int> values_;
    vector<int> weights_;
    int capacity_;
    int itemCount_; //number of available items

    vector<vector<int>> table_; //table_[i][j]best valuable possible using first i items, with capacity j 
    int basicOperations_;
    vector<int> reconstructItems() const; //uses complete table to determin the selected items
    

};

//2D array with only the necessary values added 
class MemoryBased {
public: 
    MemoryBased(const vector<int>& values, const vector<int>& weights, int capacity);
    //fill tabnle and returns final result
    KnapsackResult solve();


private:
    vector<int> values_;
    vector<int> weights_;
    int capacity_;
    int itemCount_; //number of available items

    vector<vector<int>> table_; //table_[i][j]best valuable possible using first i items, with capacity j 
    int basicOperations_;

    //item -> num items currently being considered, remainingcap -> remaining available capacity
    int calculate( int item, int remaningCapacity); //recursively calculate best val for particular state


    vector<int> reconstructItems();

};
//use hash table to only add and allocate space for the necessary values
class HashEfficient {
public:

    HashEfficient(
        const vector<int>& values;
        const vector<int>& weights;
        int capacity;
        int bucket;
    );

    ~HashEfficient();

    KnapsackResult solve();
private:

    vector<int> values_;
    vector<int> weights_;
    int capacity_;
    int bucketCount_;
    int itemCount_;

    vector<HashEntry*> table_;
    int basicOperations_;

    int hashFunction(int item, int remainingCapacity) const;

    HashEntry* find(int item, int remainingCapacity) const;

    void insert(int item, int remainingCapacity. int value);

    int calculate(int item, int remainingCapacity);

    vector<int> reconstructItems();

};

#endif


