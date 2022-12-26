#include <iostream>
using namespace std;

int leftoccurance(int arr[], int n, int target)
{
    int s = 0;
    int end = n - 1;
    int mid = s + (end - s) / 2;
    while (s <= end)
    {
        if (arr[mid] == target)
        {
            end = mid - 1;
            if (arr[mid] < target)
                break;
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
    if (arr[mid] == target)
        return mid;

    return -1;
}

int rightoccurance(int arr[], int n, int target)
{
    int s = 0;
    int end = n - 1;
    int mid = s + (end - s) / 2;
    while (s <= end)
    {
        if (arr[mid] == target)
        {
            s = mid + 1;
            if (arr[mid] > target)
                break;
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
    if (arr[mid - 1] == target)
        return mid - 1;

    return -1;
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

    cout << leftoccurance(arr, n, target) << "  ";
    cout << rightoccurance(arr, n, target);

    return 0;
}