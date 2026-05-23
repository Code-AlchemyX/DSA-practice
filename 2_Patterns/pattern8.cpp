#include <bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    void pattern8(int n)
    {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i ; j++){
                cout << " ";
            }

            for (int j = 0; j < 2*n - 2*i - 1; j++){
                cout << "*";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    Pattern p;
    p.pattern8(n);

    return 0;
}