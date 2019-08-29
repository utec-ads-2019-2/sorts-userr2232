#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for(int i = 0; i < size; ++i) {
                int current = elements[i];
                for(int j = i; j < size; ++j) {
                    current = min(current,elements[j]);
                }
                elements[i] = current;
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif