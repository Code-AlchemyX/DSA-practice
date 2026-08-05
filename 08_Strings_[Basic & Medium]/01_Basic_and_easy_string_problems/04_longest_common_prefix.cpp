class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        int size_of_min_string = strs[0].size();
        for (int i=1; i<n; i++) {
            if (strs[i].size() < size_of_min_string) {
                size_of_min_string = strs[i].size();
            }
        }

        for(int j=0; j<size_of_min_string; j++){
            for(int i=0; i<n-1; i++){
                if(strs[i][j] != strs[i+1][j]){
                    return strs[0].substr(0,j);
                } 
            }
        }

        return strs[0].substr(0, size_of_min_string);
    }
};


// ========================================================================================


class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if (str.empty()) return "";

        sort(str.begin(), str.end());

        string first = str[0];
        string last = str[str.size() - 1];
        string ans = "";

        int minLength = min(first.size(), last.size());
        for (int i = 0; i < minLength; i++) {
            if (first[i] != last[i]) break;
            ans += first[i];
        }
        return ans;
    }
};