#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>


using namespace std;

void LinearSearch(vector<int> &nums){
	int n = nums.size();
	int ele;
       	cout << "Enter element: ";
	cin >> ele;
	for(int i =0;i<n;i++){
		if(nums[i]==ele){
			cout <<ele<<" is found in position: "<< i+1 ;
		}
	}
}

int recursiveBinarySearch(vector <int> &nums, int ele, int low, int end){

	int mid = (low+end)/2;

	if(nums[mid] == ele){
		return mid;
	}

	if(nums[mid]>ele){
		return recursiveBinarySearch(nums, ele,low ,mid -1);
	}

	if(nums[mid]<ele){
		return recursiveBinarySearch(nums, ele, mid+1,end);
	}
	return -1;

}

int binarySearch(vector <int> &arr, int n, int ele){
	int beg =0;
	int end = n-1;

	while(beg<=end){
	   int mid = (beg+end)/2;

		if(arr[mid]==ele){
			return mid;
		}

		if(arr[mid]>ele){
			end = mid-1;
		}

		if(arr[mid]<ele){
			beg = mid +1;

		}
	}
	return -1;
}

int main() {
	clock_t st,et;
	vector <int> arr(10000);
	for(int i =0; i<10000 ;i++){
	       arr[i] = i+1;
	}
       	st = clock();
	LinearSearch(arr);
	et = clock();
	double time_used = ((double)(et-st))/CLOCKS_PER_SEC;

	cout <<  endl;

	cout  <<"Time for linear Search: "<< fixed << setprecision(6) <<time_used << " s"<<endl;

	clock_t st1 ,et2;
	st1 = clock();
	int res = recursiveBinarySearch(arr,9992 ,0, arr.size());
	cout << "Found in position recursive: " <<res <<endl;
       	et2 = clock();
	double time_used1 = ((double)(et2-st1))/CLOCKS_PER_SEC;
	cout  <<"Time for recursive binary  Search: "<< fixed << setprecision(6) <<time_used1 << " s"<<endl;

	clock_t st2,et3;
	st2 = clock();
	int res1 = binarySearch(arr, arr.size(),9992);
	cout <<"Position for iterative " << res1 <<endl;
       	et3 = clock();
	double time_used2 = ((double)(et3-st2))/CLOCKS_PER_SEC;
	cout  <<"Time for iterative binary Search: "<< fixed << setprecision(6) <<time_used2 << " s"<<endl;


}
