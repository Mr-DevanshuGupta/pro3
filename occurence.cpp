#include <iostream>
using namespace std;

int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }

    if (arr[i] == key)
    {
        return i;
    }
    return firstocc(arr, n, i + 1, key);
}

int lastocc(int arr[], int n, int i, int key)
{
    if (n < 0)
    {
        return -1;
    }
    if (arr[n] == key)
    {
        return n;
    }
    return lastocc(arr, n - 1, i, key);
}
int main()
{
    int arr[] = {1, 2, 5, 2, 5, 6, 4, 5};
    cout << firstocc(arr, 8, 0, 5) << endl;
    cout << lastocc(arr, 8, 0, 0) << endl;
    return 0;
}