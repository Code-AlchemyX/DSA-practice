#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> &arr) {
    vector<int> temp;

    for (int i = 0; i < arr.size()-1; i++) {
        if (arr[i] != arr[i+1]) {
            temp.push_back(arr[i]);
        }
    }

    temp.push_back(arr[arr.size()-1]);

    return temp;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> result = removeDuplicates(arr);
    for(int i=0; i<result.size(); i++){
        cout << result[i]<<" ";
    }

    return 0;
}