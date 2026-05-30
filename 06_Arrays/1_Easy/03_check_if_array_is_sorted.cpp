#include<bits/stdc++.h>
using namespace std;

//to check ascending order 

bool isSorted(vector<int>& arr) {   
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
        return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << isSorted(arr);

    return 0;
}