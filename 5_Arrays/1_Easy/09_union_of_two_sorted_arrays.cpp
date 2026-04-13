#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> merged;

    for (int i = 0; i < a.size(); i++)
        merged.push_back(a[i]);

    for (int i = 0; i < b.size(); i++)
        merged.push_back(b[i]);

    sort(merged.begin(), merged.end());

    vector<int> temp;

    for (int i = 0; i < merged.size()-1; i++) {
        if (merged[i] != merged[i+1])
            temp.push_back(merged[i]);
    }
    temp.push_back(merged[merged.size()-1]);

    return temp;
}

int main(){
    int n,m;
    cout << "Enter size of array 1 : ";
    cin >> n;
    vector<int> a(n);
    
    cout << "Enter elements of array 1 : ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << "Enter size of array 2 : ";
    cin >> m;
    vector<int> b(m);
    
    cout << "Enter elements of array 2 : ";
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    vector<int> result = findUnion(a , b);

    for(int i=0; i<result.size(); i++){
        cout << result[i]<<" ";
    }

    return 0;
}