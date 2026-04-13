#include<bits/stdc++.h>
using namespace std;

void pushZerosToEnd(vector<int>& arr) {
    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            arr[j] = arr[i];
            j++;
        }
    }

    for (int i = j; i < arr.size(); i++)
        arr[i] = 0;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    pushZerosToEnd(arr);
    for(int i=0; i<n; i++){
        cout << arr[i]<<" ";
    }

    return 0;
}