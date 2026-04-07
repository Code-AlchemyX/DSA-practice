#include<bits/stdc++.h>
using namespace  std;

vector<vector<int>> countFreq(vector<int>& arr) {
    unordered_map<int,int> map;
    vector<vector<int>> result;
        
    for(int i=0 ; i<arr.size() ; i++){
        map[arr[i]]++;
    }
        
    for(auto it : map){    
        result.push_back({it.first , it.second});
    }
    return result;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> result = countFreq(arr);
    for(auto it : result){
        cout << it[0] << " " << it[1] <<endl;
    }

    return 0;
}