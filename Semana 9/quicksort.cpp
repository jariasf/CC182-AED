#include <iostream>
using namespace std;

int partition(int *A, int left, int right){
    int pivot = A[right];
    int i = left;
    for(int j = left ; j < right ; ++j ){
        if( A[j] <= pivot ){
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[right]);
    return i;
}

/*
int randomizedPartition(int *A, int left, int right){
    int rand_pos = ...;
    swap(A[rand_pos], A[right]);
    return partition();
}*/

void quickSort(int *A, int left, int right){
    if(left < right){
        //int pivot_index = randomizedPartition(A, left, right);
        int pivot_index = partition(A, left, right);
        quickSort(A, left, pivot_index - 1);
        quickSort(A, pivot_index + 1, right);
    }
}

void printArray(int *A, int n){
    for(int i = 0 ; i < n ; ++i ){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {

    int n;
    cin>>n;
    int* A = new int[n];
    for( int i = 0 ; i < n; ++i ){
        cin>>A[i];
    }
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A,n);
    delete []A;
    return 0;
}