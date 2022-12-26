#include <iostream>
using namespace std;

int ceilelement(int arr[], int n, int target)
{
    int s = 0;
    int end = n - 1;
    int mid = s + (end - s) / 2;
    while (s <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            s = mid + 1;
        }
        mid = s + (end - s) / 2;
    }

    return mid;
}

int main()
{

    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << ceilelement(arr, n, target);

    return 0;
}