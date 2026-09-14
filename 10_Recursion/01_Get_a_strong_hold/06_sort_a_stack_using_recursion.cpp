//! Recursive Approach

class Solution {
  public:
    void insertSorted(stack<int> &st , int val){
        if(st.empty() || st.top() <= val){
            st.push(val);
            return;
        }
        
        int insert = st.top();
        st.pop();
        
        insertSorted(st , val);
        
        st.push(insert);
    }
    
    void sortStack(stack<int> &st) {    
        int n = st.size();
        
        if(n <= 1){
            return;
        }
        
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