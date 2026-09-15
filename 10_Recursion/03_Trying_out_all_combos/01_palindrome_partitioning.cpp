class Solution {
public:
    bool palindromeCheck(string &s , int low , int high){
        if(low >= high){
            return true;
        }

        if(s[low] != s[high]){
            return false;
        }
        low++;
        high--;

        return palindromeCheck(s , low , high);
    }

    void generate(string &s , vector<string> &temp , vector<vector<string>> &result , int index){
        if(index == s.size()){
            result.push_back(temp);
            return;
        }

        for(int i=index ; i<s.size() ; i++){
            int low = index;
            int high = i;

            if( palindromeCheck(s , low , high) ){
                temp.push_back(s.substr(index, i - index + 1));
                generate(s , temp , result , i + 1);
                temp.pop_back();
            }
        }
        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        int index = 0;

        generate(s , temp , result , index);

        return result;
    }
};