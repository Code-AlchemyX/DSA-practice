#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr) {
    int temp = arr[arr.size() - 1];
    
    for(int i = arr.size()-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    
    arr[0] = temp;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    rotate(arr);

    for(int i=0; i<n; i++){
        cout << arr[i]<<" ";
    }

    return 0;
}