#include<bits/stdc++.h>
using namespace std;

// Search GCD EULCLIDEAN LOGIC on yt for better understanding. [ channel - Learn Math Tutorials ]
// a = bq + r   ---> q = quotient and r = remainder(a%b)
// so b shifts to a then r shifts to b. Therefore a = b and b = r ( temp = a%b ). And at last when the number gets completely divided r = 0 , b = gcd --> Then the final shift takes place where a = b(gcd) and b = r = 0. As b=0 the loop stops.
int gcd(int a, int b) {
    while(b!=0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b);
}
