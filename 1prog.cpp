#include <iostream>
#include <ctime>
#include <unordered_set>
#include <iomanip>

using namespace std;

int gcd(int x, int y) {
    int rem = x % y;
    if (rem == 0) return y;
    while (rem != 0) {
        return gcd(y, rem);
    }
    return -1;
}

void middle_school(int x, int y){
    unordered_set<int>  s;

    if(x>y){
        swap(x,y); 
    }
    for(int i =1;i<=x;i++){
        if(x%i==0)
            s.insert(i); 
    }

    int temp = 1; 
    for(int i =1;i<=y;i++){
        if(y%i==0 && s.find(i) != s.end()){
            temp =i; 
        }
    }

    cout << "GCD is " << temp << " \n"; 
}

int gcd2(int x, int y) {
    int gcd = 0;
    if (x < y) {
        gcd = x;
    } else {
        gcd = y;
    }

    while (gcd > 0) {
        if (x % gcd == 0 && y % gcd == 0) {
            return gcd;
        } else {
            gcd--;
        }
    }
    return 1;
}

int main() {
    clock_t st, st2, et, st1, et1, et3;

    cout << std::fixed << std::setprecision(6);

    st = clock();
    int res = gcd(3000000, 6900);
    et = clock();
    double time_used = ((double)(et - st)) / CLOCKS_PER_SEC;
    cout << "GCD is " << res << "\nTime Used for Euclidean: " << time_used << " s\n";

    st1 = clock();
    int res1 = gcd2(3000000, 6900);
    et1 = clock();
    double time_used1 = ((double)(et1 - st1)) / CLOCKS_PER_SEC;
    cout << "GCD is " << res1 << "\nTime Used for Consecutive: " <<fixed << setprecision(6) <<time_used1 << " s\n";

    st2 = clock();
    middle_school(3000000, 6900);
    et3 = clock();
    double time_used2 = ((double)(et3 - st2)) / CLOCKS_PER_SEC;
    cout << "Time Used for Middle School: " << time_used2 << " s\n";

    return 0;
}
