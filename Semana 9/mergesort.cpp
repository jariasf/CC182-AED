#include <iostream>
using namespace std;

void merge(int *L, int *R, int *A, int n){
    //TODO: Implementar el metodo merge
    int left_size = n/2;
    int right_size = n - left_size;
    int i = 0, j = 0, k = 0;
    
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

int main() {

    int n;
    cin>>n;
    int* A = new int[n];
    for( int i = 0 ; i < n; ++i ){
        cin>>A[i];
    }
    mergeSort(A, n);

    delete []A;
    return 0;
}