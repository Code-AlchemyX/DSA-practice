//  E 
//  D E 
//  C D E 
//  B C D E 
//  A B C D E

#include<bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    void pattern18(int n){
        for(int i=0; i<n; i++){
            for(int j=n-i-1; j<=n-1; j++){
                cout << (char)('A'+j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    Pattern p;
    p.pattern18(n);

    return 0;
}