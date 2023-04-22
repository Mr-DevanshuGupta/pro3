#include <iostream>
using namespace std;

int pow(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * pow(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << pow(n);
    return 0;
}