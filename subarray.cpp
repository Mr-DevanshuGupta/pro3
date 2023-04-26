#include <iostream>
using namespace std;

int max_cross_subarray(int arr[], int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left, max_right;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;

    for (int j = mid + 1; j <= high; j++)
    {
        sum = sum + arr[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }

    return (max_left, max_right, left_sum + right_sum);
}

int max_subarray(int arr[], int low, int high)
{
    int left_low, left_high, left_sum, right_low, right_high, right_sum;
    int cross_low, cross_high, cross_sum;
    if (high == low)
    {
        return (low, high, arr[low]);
    }

    else
    {
        int mid = (low + high) / 2;

        (left_low, left_high, left_sum) = max_subarray(arr, low, mid);

        (right_low, right_high, right_sum) = max_subarray(arr, mid + 1, high);

        (cross_low, cross_high, cross_sum) = max_cross_subarray(arr, low, mid, high);
    }

    if (left_sum >= right_sum && left_sum >= cross_sum)
    {
        return (left_low, left_high, left_sum);
    }
    else if (right_sum >= left_sum && right_sum >= cross_sum)
    {
        return (right_low, right_high, right_sum);
    }
    else
    {
        return (cross_low, cross_high, cross_sum);
    }
}

int main()
{
    int arr[5] = {1, 5, -2, -6, 8};
    int left, right, sum;
    (left, right, sum) = max_subarray(arr, 0, 4);
    cout << left << " " << right << "  " << sum << endl;
    return 0;
}