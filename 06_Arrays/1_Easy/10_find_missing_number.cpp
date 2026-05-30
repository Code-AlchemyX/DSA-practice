//! This code is written according to the GFG qs not the striver sheet. [Qs are same but limits differ]

#include<bits/stdc++.h>
using namespace std;

//understand why long long is used instead of int.

int missingNum(vector<int>& arr) {
    long long n = arr.size()+1;
    long long total_sum = n*(n+1)/2;
        
    long long array_sum = 0;
    for(int i=0; i<arr.size(); i++){
        array_sum += arr[i];
    }
        
    long long missing_element = total_sum - array_sum;
        
    return (int)missing_element;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << missingNum(arr);
    
    return 0;
}