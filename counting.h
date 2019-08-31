#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>
#include <cstring>
#include <vector>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void countSortByExp(int *elements, int size, int exp) {
            vector<int> tmp(size,0);
            int count[10] = {};
            for(int i = 0; i < size; ++i)
                ++count[elements[i]/exp%10];
            for(int i = 1; i < 10; ++i)
                count[i] += count[i-1];
            for(int i = size-1; i >= 0; --i) {
                tmp[count[elements[i]/exp%10]-1] = elements[i];
                --count[elements[i]/exp%10];
            }
            for(int i = 0; i < size; ++i)
                elements[i] = tmp[i];
        }

        void execute() {
            const int RANGE = 200; 
            int count[RANGE+1] = {};
            vector<int> tmp(size,0);
            
            memset(count, 0, sizeof(count));
            for(int i = 0; i < size; ++i)
                ++count[elements[i]];
            for(int i = 1; i <= RANGE; ++i)
                count[i] += count[i-1];
            for(int i = 0; i < size; ++i) {
                tmp[count[elements[i]]-1] = elements[i];
                --count[elements[i]];
            }
            for(int i = 0; i < size; ++i)
                elements[i] = tmp[i];
        }

        inline string name() { return "CountingSort"; }
};

#endif