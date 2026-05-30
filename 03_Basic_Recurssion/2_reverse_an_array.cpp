#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr) {
    int low=0 , high=arr.size()-1 ;
    while(low < high){
        swap(arr[low] , arr[high]);
        low++;
        high--;
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    reverseArray(arr);

    for(auto it : arr){
        cout << it <<" ";
    }

    return 0;
}