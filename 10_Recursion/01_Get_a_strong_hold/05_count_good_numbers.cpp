class Solution {
public:
    int helper(long long n , long long x , long long m){
        if(n == 0) return 1;

        long long half = helper(n/2 , x , m);

        if(n%2 == 0){
            return ( (half%m)*(half%m) ) % m;
        }
        else {
            return ( (half%m)*(half%m)*(x%m) ) % m;
        }
    }

    int countGoodNumbers(long long n) {
        long long m = 1e9 + 7;
        
        long long evenPower = (n+1)/2; 
        long long oddPower = n/2;

        long long even = helper(evenPower, 5 , m);
        long long odd = helper(oddPower , 4 , m);

        int ans = (even*odd)%m;

        return ans;
    }
};