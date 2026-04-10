#include<bits/stdc++.h>
using namespace std;

int mostFreqEle(vector<int>& arr) {
    unordered_map<int,int> map;
        
    for(int i=0; i<arr.size(); i++){
        map[arr[i]]++;    
    }
        
    int maxfreq= 0;
    int value = -1;
        
    for(auto it : map){
        if(it.second > maxfreq){
            maxfreq = it.second;
            value = it.first;
        }
        // Check the if loop below. This condition changes acc to the qs.
        // ( if two numbers occur with same freq then which to be given output as ? larger or smaller ? )
        else if(it.second == maxfreq && it.first > value){ 
            value = it.first;
        }
    }
    return value;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }

    cout << mostFreqEle(arr);
}