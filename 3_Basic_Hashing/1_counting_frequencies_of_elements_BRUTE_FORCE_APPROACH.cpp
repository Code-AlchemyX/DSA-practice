#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> countFreq(vector<int>& arr) {
    int n = arr.size();
    vector<bool> visited(n , false);
    vector<vector<int>> result;
    
    for(int i=0 ; i<n ; i++){
        if(visited[i] == true){
            continue;
        }
         
    int count = 1;
    for(int j=i+1 ; j<n ; j++){
        if(arr[i] == arr[j]){
            visited[j] = true;
            count++;
        }
    }    
        result.push_back({arr[i] , count});
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    
    vector<vector<int>> result = countFreq(arr);

    for (auto x : result) 
        cout << x[0] << " " << x[1] << endl;

    return 0;
}