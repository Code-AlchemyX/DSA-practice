#include<bits/stdc++.h>
using namespace std;

// Search GCD EULCLIDEAN LOGIC on yt for better understanding. [ channel - Learn Math Tutorials ]
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
