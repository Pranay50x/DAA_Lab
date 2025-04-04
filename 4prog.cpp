#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;


int findPivot(int arr[], int low, int high){
    int pivot = arr[low];
    int i =low;
    int j =high;

    while(i < j){
        while(arr[i]<=pivot && i<=high){
            i++;
        }

        while(arr[j]>pivot && j>=low){
            j--;
        }

        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high){
    if(low==high) return ;

    if(low<high){
        int pivotIndex = findPivot(arr, low, high);
        quicksort(arr, low, pivotIndex-1);
        quicksort(arr, pivotIndex+1, high);
    }
}

void printarray(int arr[], int n ){
    for(int i =0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    clock_t st,et;
    st = clock();
    int arr[] = {4,1,7,9,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    cout << "Array after sorting: ";
    printarray(arr, n);
    et = clock();
    double time_used = ((double)(et-st))/CLOCKS_PER_SEC;
    cout << "Time used is: "<<fixed << setprecision(6) <<time_used << " s\n";
}
