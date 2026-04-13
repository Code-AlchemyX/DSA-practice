#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main(){
    int n,x;
    cout << "Enter size of array : "<<endl;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    cout << "Enter number to find : "<<endl;
    cin >> x;
 
    cout << search(arr , x);

    return 0;
}