#ifndef SHELL_H
#define SHELL_H

#include "sort.h"
#include <algorithm>

class ShellSort : public Sort {       
    public:
        ShellSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for(int h = size/2; h > 0; h/=2)
                for(int i = h; i < size; ++i) {
                    int tmp = elements[i];
                    int j;
                    for(j = i; j >= h && elements[j-h] > tmp; j -= h)
                        elements[j] = elements[j-h];
                    elements[j] = tmp;
                }
        }

        inline string name() { return "ShellSort"; }
};

#endif