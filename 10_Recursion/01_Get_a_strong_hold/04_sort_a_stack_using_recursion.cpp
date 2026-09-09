//! Recursive Approach

class Solution {
  public:
    void insertSorted(stack<int> &st, int val){
        if(st.empty() || val >= st.top()){
            st.push(val);
            return;
        }        
        
        int currVal = st.top();
        st.pop();
        
        insertSorted(st, val);
    
        st.push(currVal);
    }
    
    void sortStack(stack<int> &st) {
        int n = st.size();
        stack<int> temp;
        
        if(n <= 1) return;
        
        int val = st.top();
        st.pop();
        
        sortStack(st);
        
        insertSorted(st , val);
    }
};



//! Iterative Approach 

class Solution {
  public:
    void sortStack(stack<int> &st) {
        int n = st.size();
        stack<int> temp;
        
        for(int i = 0; i < n - 1; i++) {
            temp.push(st.top());
            st.pop();
        }
        
        while(!temp.empty()) {
            int val = temp.top();
            temp.pop();
            
            while(!st.empty() && val < st.top()) {
                temp.push(st.top());
                st.pop();
            }
            
            st.push(val);
        }
    }
};