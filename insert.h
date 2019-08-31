#ifndef INSERT_H
#define INSERT_H

#include "sort.h"
#include <vector>

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int i, valueToInsert, j;
            for(int i = 0; i < size; ++i) {
                valueToInsert = elements[i];
                j = i-1;
                while(j >= 0 && elements[j] > valueToInsert) {
                    elements[j+1] = elements[j];
                    j--;
                }
                elements[j+1] = valueToInsert;
            }
        }

        inline string name() { return "InsertSort"; }
};

#endif