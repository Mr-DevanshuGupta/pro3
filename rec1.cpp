#include <iostream>
using namespace std;

int pow(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    return n * pow(n, p - 1);
}

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n, p;
    cin >> n;
    // cin >> p;
    // cout << pow(n, p);
    // cout << fact(n);
    cout << fib(n);
    return 0;
}