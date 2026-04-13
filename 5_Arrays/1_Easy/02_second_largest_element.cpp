#include<bits/stdc++.h>
using namespace std;

int SecondLargest(vector<int> &arr) {
    int max = arr[0], smax = -1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max) {
            smax = max;
            max = arr[i];
        }
        else if (arr[i] > smax && arr[i] != max) {
            smax = arr[i];
        }
    }
    return smax;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << SecondLargest(arr);

    return 0;
}