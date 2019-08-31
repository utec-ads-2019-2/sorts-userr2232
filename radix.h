#ifndef RADIX_H
#define RADIX_H

#include "sort.h"
#include "counting.h"
#include <algorithm>

class RadixSort : public Sort {       
    public:
        CountingSort* countingSort;
        RadixSort(int *elements, size_t size) : Sort(elements, size) {
            countingSort = new CountingSort(elements, size);
        }

        void execute() {
            int maxelement = *max_element(elements, elements+size);
            for(int exp = 1; maxelement/exp; exp*=10)
                this->countingSort->countSortByExp(elements,size,exp);
        }

        inline string name() { return "RadixSort"; }
};

#endif