//! ============================================= Brute Force =============================================

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


//! OR ------------> 

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> st;
        vector<int> result;
        
        for(auto it : a){
            st.insert(it);
        }
        
        for(auto it : b){
            st.insert(it);
        }
        
        for(auto it : st){
            result.push_back(it);
        }
        
        
        return result;
    }
};


//! ============================================ Optimal Approach ============================================

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        
        int i = 0;
        int j = 0;
        
        vector<int> Union;
        
        while( i < n && j < m ){
            if( a[i] <= b[j] ){
                if( Union.size() == 0 || Union.back() != a[i] ){
                    Union.push_back(a[i]);
                }
                i++;
            } else if( a[i] >= b[j] ){
                if( Union.size() == 0 || Union.back() != b[j] ){
                    Union.push_back(b[j]);
                }
                j++;
            }
        }
        
        while(i<n){
            if( Union.size() == 0 || Union.back() != a[i] ){
                Union.push_back(a[i]);
            }
            i++;
        }
        
        while(j<m){
            if( Union.size() == 0 || Union.back() != b[j] ){
                Union.push_back(b[j]);
            }
            j++;
        }
        
        return Union;
    }
};