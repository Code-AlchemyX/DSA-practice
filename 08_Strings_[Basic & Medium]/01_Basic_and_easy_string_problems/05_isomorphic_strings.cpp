//! Optimal 1

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        //Arrays of size 256 represent all possible ASCII characters.
        int mapS[256] = {0};
        int mapT[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            //int charS and charT converts characters to their numerical ASCII values
            int charS = s[i];  
            int charT = t[i];

            //*This if block checks whether the last seen position of s[i] matches the last seen position of t[i]:
            //If both are unseen, both arrays return 0 (Match!).
            //If both were last seen together at index k, both return k + 1 (Match!).
            //If one was seen before at a different index or one is new while the other is repeated, their values won't match (Mismatch --> return false).
            
            if (mapS[charS] != mapT[charT]) {
                return false;
            }

            mapS[charS] = i + 1;
            mapT[charT] = i + 1;
        }

        return true;
    }
};



//! Optimal 2

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapST;
        unordered_map<char,char> mapTS;

        if(s.size() != t.size()) return false;

        for(int i=0; i<s.size(); i++){
            if(mapST.find(s[i]) == mapST.end()){
                mapST[s[i]] = t[i];
            }
            else {
                if(mapST[s[i]] != t[i]){
                    return false;
                }
            }

            if(mapTS.find(t[i]) == mapTS.end()){
                mapTS[t[i]] = s[i];
            }
            else {
                if(mapTS[t[i]] != s[i]){
                    return false;
                }
            }
        }

        return true;;
    }
};