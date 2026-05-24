// A
// BB
// CCC
// DDDD
// EEEEE

#include<bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    void pattern16(int n){
        char letter = 'A';
        for(int i=0; i<n; i++){
            for(int j=0; j<i+1; j++){
                cout << letter;
            }
            letter += 1;
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
    p.pattern16(n);

    return 0;
}