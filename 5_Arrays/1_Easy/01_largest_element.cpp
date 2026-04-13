#include<bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr) {
    int max = arr[0];
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > max){
            max = arr[i];
        }    
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n); 
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    cout << largest(arr);

    return 0;
}