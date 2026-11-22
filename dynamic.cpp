#include "dynamic.hpp"
#include <algorithm>
#include <stdexcept>


Traditional::Traditional(const vector<int>& values, const vector<int>& weights, int capacity):
                        values_(values), weights_(weights), capacity_(capacity), 
                        itemCount_(static_cast<int>(values.size())), table_(itemcount_ + 1, vector<int>(capacity_ + 1, 0)), basicOperations_(0)
{

    if(values_.size() != weights_.size()) { 
        throw std::invalid_argument("values and weights must have same size");
    }
    if (capacity_ < 0) {
        throw std::invalid_argument("Capacity cant be negative");
    }

}

MemoryBased::MemoryBased(const vector<int>& values, const vector<int>& weights, int capacity):
                        values_(values), weights_(weights), capacity_(capacity), 
                        itemCount_(static_cast<int>(values.size())), table_(itemcount_ + 1, vector<int>(capacity_ + 1, -1)), basicOperations_(0)
{

    if(values_.size() != weights_.size()) { 
        throw std::invalid_argument("values and weights must have same size");
    }
    if (capacity_ < 0) {
        throw std::invalid_argument("Capacity cant be negative");
    }

    for(int j = 0; j <= capacity_; j++){
        table_[0][j] = 0;
    }
    for(int i =0; i <= itemCount_; i++){
        table_[i][0] = 0;
    }
}

HashEfficient::HashEfficient(const vector<int>& values, const vector<int>& weights, int capacity, int bucketCount):
                        values_(values), weights_(weights), capacity_(capacity), bucketCount_(bucketCount),
                        itemCount_(static_cast<int>(values.size())), table_(bucketCount_, nullptr), basicOperations_(0)
{

    if(values_.size() != weights_.size()) { 
        throw std::invalid_argument("values and weights must have same size");
    }
    if (capacity_ < 0) {
        throw std::invalid_argument("Capacity cant be negative");
    }

    if(bucketCount_ <= 0){
        throw std::invalid_argument("Bucket count must be positive");
    }
}

HashEfficient::~HashEfficient(){
    for (HashEntry* bucket : table_) {
        HashEntry* current = bucket;

        while (current != nullptr) {
            HashEntry* next = current->next;
            delete current;
            current = next;
        }
    }
}
