#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>
#include <cstring>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            const int RANGE = 200; 
            int *count = new int[RANGE+1], *tmp = new int[size];
            
            memset(count, 0, sizeof(count));
            memset(tmp, 0, sizeof(tmp));
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
            count = nullptr;
            delete[] count;
            tmp = nullptr;
            delete[] tmp;
        }

        inline string name() { return "CountingSort"; }
};

#endif