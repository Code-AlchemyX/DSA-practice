class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string temp = "";
        int depth = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                if(depth > 0){
                    temp.push_back(s[i]);
                }
                depth++;
            }
            else {
                if(depth > 1){
                    temp.push_back(s[i]);
                }
                depth--;
            }
        }
        return temp;
    }
};