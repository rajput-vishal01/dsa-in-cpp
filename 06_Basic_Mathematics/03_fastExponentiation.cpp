#include <iostream>
using namespace std;


//Fast Exponential :
/*
 a^b :
 if b is even number: a^(b/2)^2
 else for odd b : a^(b/2)^2 * a
*/


int fastExponentiation(int x, int n)
{
    long long int ans = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            // n is odd.
            ans = (ans * x) ;
            // ans = (ans * x) % M; for large values
        }
        x = (x * x) ;
        n >>= 1;
    }
    return ans ;
    // return ans % M; for large values
}//T.C : o(log b)

int slowExponentiation(int a, int b)
{
    int ans = 1;
    while (b--)
    {
        ans *= a;
    }
    return ans;
} //T.C : o(b)

int main()
{
    int a = 5;
    int b = 4;

    cout << slowExponentiation(a, b) << endl;
    cout << fastExponentiation(a, b) << endl;
    return 0;
}