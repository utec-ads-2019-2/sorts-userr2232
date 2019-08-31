#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

        int partition(int *elements, int low, int high) {
            int pivot = elements[high];
            int i = low-1;
            for(int j = low; j <= high-1; ++j) {
                if(elements[j] < pivot) {
                    ++i;
                    swap(elements[i], elements[j]);
                }
            }
            swap(elements[++i],elements[high]);
            return i;
        }

        void quickSort(int *elements, int low, int high) {
            if(low < high) {
                int partition_index = this->partition(elements, low, high);
                this->quickSort(elements,low,partition_index-1);
                this->quickSort(elements,partition_index+1,high);
            }
        }

        void execute() {
            this->quickSort(elements,0,size);
        }

        inline string name() { return "QuickSort"; }
};

#endif