#include<bits/stdc++.h>
using namespace std;

//! Pattern 1: Print All
void printS(int ind, vector<int>& ds, int s, int sum, int arr[], int n) {
    if (ind == n) {
        if (s == sum) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }
    
    ds.push_back(arr[ind]);
    s += arr[ind];
    printS(ind + 1, ds, s, sum, arr, n);
    
    s -= arr[ind];
    ds.pop_back();
    
    printS(ind + 1, ds, s, sum, arr, n);
}


//! Pattern 2: Print Only One
bool printS_one(int ind, vector<int>& ds, int s, int sum, int arr[], int n) {
    if (ind == n) {
        if (s == sum) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    
    ds.push_back(arr[ind]);
    s += arr[ind];
    if (printS_one(ind + 1, ds, s, sum, arr, n) == true) {
        return true;
    }
    
    s -= arr[ind];
    ds.pop_back();
    
    if (printS_one(ind + 1, ds, s, sum, arr, n) == true) {
        return true;
    }
    
    return false;
}


//! Pattern 3: Count
int printS_count(int ind, int s, int sum, int arr[], int n) {
    if (ind == n) {
        if (s == sum) return 1;
        return 0;
    }
    
    s += arr[ind];
    int l = printS_count(ind + 1, s, sum, arr, n);
    
    s -= arr[ind];
    
    int r = printS_count(ind + 1, s, sum, arr, n);
    
    return l + r;
}


int main() {
    int arr[] = {1 , 2 , 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    
    //! Pattern 1: Print All Subsequences 
    // printS(0, ds, 0, sum, arr, n);
    


    //! Pattern 2: Print Only One Subsequence 
    // printS_one(0, ds, 0, sum, arr, n);
    


    //! Pattern 3: Count Subsequences 
    // int totalCount = printS_count(0, 0, sum, arr, n);
    // cout << "Total Count: " << totalCount << endl;
    
    return 0;
}
