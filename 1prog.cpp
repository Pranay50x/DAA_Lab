#include <iostream>
#include <set>
#include <vector>

using namespace std;

int intersection(vector<int> &a, vector<int> &b){
    set <int> s;
    vector<int> v;

    for(int i= 0;i<a.size();i++){
        s.insert(a[i]);
    }

    for(int x : b){
        if(s.find(x)!=s.end()){
            v.push_back(x);
            s.erase(x);
        }
    }
    for(int i =0;i<v.size();i++){
        return v[v.size()-1];
    }
    return -1;
}

int main(){
    vector<int> a = {1,2,3,6};
    vector<int> b = {1,3};
    int final = intersection(a, b);

    cout << final << " is HCF";
    cout << endl;
}
