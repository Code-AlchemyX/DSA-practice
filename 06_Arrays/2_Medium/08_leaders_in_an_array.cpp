#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        int max = arr[n-1];
        vector<int> leaders;
        
        for(int i=n-2; i>=0; i--){
            if(arr[i] >= max){
                max = arr[i];
                leaders.push_back(arr[i]);
            }    
        }
        
        reverse(leaders.begin(), leaders.end());
        leaders.push_back(arr[n-1]);
        
        
        return leaders;
    }
};

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    Solution s;
    vector<int> result = s.leaders(arr);

    cout << "Leaders: ";
    for(auto it : result)
        cout << it << " ";
    cout << endl;

    return 0;
}
