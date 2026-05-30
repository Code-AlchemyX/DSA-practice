// A
// AB
// ABC
// ABCD
// ABCDE

#include<bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    void pattern14(int n){
        for(int i=0; i<n; i++){
            char letter = 'A';
            
            for(int j=0; j<i+1; j++){
                cout << letter;
                letter +=1;
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
    p.pattern14(n);

    return 0;
}