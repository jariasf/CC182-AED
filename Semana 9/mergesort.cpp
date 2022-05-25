#include <iostream>
using namespace std;

void merge(int *L, int *R, int *A, int n){
    int left_size = n/2;
    int right_size = n - left_size;
    int i = 0, j = 0, k = 0;
    while(i < left_size && j < right_size ){
        if( L[i] < R[j] ){
            A[k] = L[i];
            k++; i++;
        }else{
            A[k] = R[j];
            k++; j++;
        }
    }

    while(i < left_size){
        A[k] = L[i];
        k++; i++;
    }

    while(j < right_size){
        A[k] = R[j];
        k++; j++;
    }    
}

void mergeSort(int *A, int n){
    if( n > 1){
        // Divisiones
        int mid = n/2;  // n = 7, mid = 3, n - mid = 4
        int* L = new int[mid]; // mid = 3
        int* R = new int[n - mid]; // n - mid = 4
        //       0  1  2  3
        // A = [ 5, 4 ,2 ,1]
        // mid = 2
        // L = [5, 4]
        for( int i = 0 ; i < mid ; ++i ){
            L[i] = A[i];
        }
        // R = [2, 1]
        // i=2,3
        // idx = 0, 1
        for( int i = mid ; i < n ; ++i ){
            R[i - mid] = A[i];  // R[0] = A[mid], R[1] = A[mid+1]
        }

        mergeSort(L, mid);
        mergeSort(R, n - mid);
        
        // Combinacion o Mezcla entre L y R
        merge(L, R, A, n);
        
        delete[]L;
        delete[]R;
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
    mergeSort(A, n);
    printArray(A,n);
    delete []A;
    return 0;
}
