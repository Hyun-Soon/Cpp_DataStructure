#include <iostream>

using namespace std;

//최대공약수
int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main()
{
    cout << gcd(8, 12) << '\n';
    return 0;
}