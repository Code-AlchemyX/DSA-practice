class Solution {
  public:
    void generate(vector<int> &arr , int sum , int index , int n , vector<int> &result){
        if(index == n){
            result.push_back(sum);
            return;
        }    
        
        sum += arr[index];
        generate(arr , sum , index + 1 , n , result);
        
        sum -= arr[index];
        generate(arr , sum , index + 1 , n , result);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        int index = 0;
        int sum = 0;
        
        generate(arr , sum , index , n , result);
        
        return result;
    }
};