#ifndef MERGE_H
#define MERGE_H

#include "sort.h"
#include <vector>
#include <climits>

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}
        
        void mergeSort(int *A, int p, int r) {
            if(p < r) {
                int q = (p+r)/2;
                this->mergeSort(A,p,q);
                this->mergeSort(A,q+1,r);
                this->merge(A,p,q,r);
            }
        }

        void merge(int *A, int p, int q, int r) {
            int n1 = q-p+1;
            int n2 = r-q;
            vector<int> v1(n1+1,0), v2(n2+1,0);
            for(int i = 0; i < n1; ++i)
                v1[i] = A[p+i];
            for(int i = 0; i < n2; ++i)
                v2[i] = A[q+i+1];
            v1[n1] = INT_MAX;
            v2[n2] = INT_MAX;
            int i(0), j(0);
            for(int k = p; k <= r; ++k) {
                if(v1[i] > v2[j]) {
                    A[k] = v2[j]; ++j;
                }
                else {
                    A[k] = v1[i]; ++i;
                }
            }
        }

        void execute() {
            this->mergeSort(elements,0,size);
        }

        inline string name() { return "MergeSort"; }
};

#endif