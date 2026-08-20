#include <stdio.h>
#include <stdlib.h>

// Always initialize the entire fenwick tree array with 0 before calling 'initFenwickTree'
// Fenwick tree array is 1-based indexed. Therefore, create array of size 'number of total elements + 1'
// delta = change to be made based on the current value and the resultant value. delta = resultant_value - current_value

struct FenwickTree{
    int *ptr; // pointer pointing to the fenwick tree array
    int size; // number of elements in the fenwick tree
};

void initFenwickTree(struct FenwickTree *ft, int array[], int size){
    ft->ptr = array;
    ft->size = size;
}

void update(struct FenwickTree *ft, int index, int delta){
    while(index <= ft->size){
        ft->ptr[index] += delta;
        index += index & (-index);
    }
}

int query(struct FenwickTree *ft, int index){
    int sum = 0;

    while(index > 0){
        sum += ft->ptr[index];
        index -= index & (-index);
    }

    return sum;
}

int rangeQuery(struct FenwickTree *ft, int left, int right){
    return query(ft, right) - query(ft, left - 1);
}

void createFenwickTree(struct FenwickTree *ft, int array[]){
    for(int i=0; i<ft->size; i++)
        update(ft, i+1, array[i]);
}

void printFenwickTree(struct FenwickTree *ft){
    if(ft->size == 0){
        printf("Fenwick Tree is empty.\n");
        return;
    }

    for(int i=1; i<=ft->size; i++)
        printf("%d ", ft->ptr[i]);
}