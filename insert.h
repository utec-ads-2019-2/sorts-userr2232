#ifndef INSERT_H
#define INSERT_H

#include "sort.h"
#include <vector>

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            std::vector<int> v;
            if(size > 0) v.push_back(elements[0]);
            for(int i = 1; i < size; ++i){
                int current = elements[i];
                vector<int>::iterator it = v.begin();
                bool inserted = false;
                for(int j = 0; j < v.size(); ++j) {
                    if(v[j] >= current) {
                        v.insert(it,current);
                        inserted = true;
                        break;
                    }
                    it++;
                }
                if(!inserted) v.insert(it,current);
            }
            for(int i = 0; i < size; ++i)
                elements[i] = v[i];
        }

        inline string name() { return "InsertSort"; }
};

#endif