//! Iterative approach

class Solution {
public:
    double myPow(double base, int exponent) {
        double result = 1.0;
        long long power = exponent;
        
        if (power < 0) {
            power = -1 * power;
        }
        
        while (power > 0) {
            if (power % 2 == 1) {
                result = result * base;
                power = power - 1;
            } else {
                base = base * base;
                power = power / 2;
            }
        }
        
        if (exponent < 0) {
            return 1.0 / result;
        }
        
        return result;
    }
};

//! Recursive approach

class Solution {
public:
    double helper(double x, long long n) {
        if (n == 0) return 1.0;
        
        double half = helper(x, n / 2);
    
        if (n % 2 == 0) {
            return half * half;
        } 
        else {
            return half * half * x;
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        return helper(x, N);
    }
};