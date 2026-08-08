//! Optimal 1 --> but SC = O()

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mapS;
        unordered_map<char,int> mapT;

        if(s.size() != t.size()) return false;
        
        for(int i=0; i<s.size(); i++){
            mapS[s[i]]++;
            mapT[t[i]]++;
        }

        if(mapS != mapT) return false;

        return true;
    }
};

//! Optimal 2 



