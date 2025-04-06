#include <iostream>
#include <ctime>
#include <ratio>
#include <vector>
#include <iomanip>

using namespace std;

void merge(vector<int> &a, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }

    for(int i = low;i<=high; i++){
        a[i] = temp[i-low];
    }
}

void mergeSort(vector<int> &v, int low, int high){
    int mid  = (low+high)/2;
    if(low>=high) return;
    mergeSort(v, low, mid);
    mergeSort(v, mid+1, high);
    merge(v,low,mid,high);
}


int main(){
    clock_t st,et;
    st = clock();
    vector<int> a = {1,0,0,0,1,1,0,0,1};
    cout << "before sorting: \n";
    for(int i :a){
        cout << i << " ";
    }
    cout << endl;
    mergeSort(a, 0, a.size()-1);
    cout << "After soring: \n";
    for(int i : a){
        cout << i <<" ";
    }
    cout<<endl;
    et = clock();
    double time = ((double)(et-st))/CLOCKS_PER_SEC;
    cout << "Time used is: "<<fixed << setprecision(6)<<time <<" s\n";
}
