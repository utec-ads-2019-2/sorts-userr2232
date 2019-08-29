#ifndef BUBBLE_H
#define BUBBLE_H

#include "sort.h"
#include <algorithm>

class BubbleSort : public Sort {       
    public:
        BubbleSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for(int i = 0; i < size; ++i){
                for(int j = 0; j < size-i-1; ++j) {
                    if(elements[j]>elements[j+1]) {
                        int tmp;
                        tmp = elements[j];
                        elements[j] = elements[j+1];
                        elements[j+1] = tmp;
                    }
                }
            }
        }

        inline string name() { return "BubbleSort"; }
};

#endif