#include <iostream>
using namespace std;

bool isSorted(int arr[], int n, int index)
{
    if (index == n - 1)
    {
        return true;
    }
    bool check = isSorted(arr, n, index + 1);
    return check & arr[index] < arr[index + 1];
}

int main()
{
    //int n;
    //cin >> n;
    // int *arr = new int[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    int n = 5;
    int arr[5] = {5,3,2,5,6};
    if (isSorted(arr, n, 0))
    {
        cout << "Given Array is Sorted" << endl;
    }
    else
    {
        cout << "Given Array is not Sorted" << endl;
    }
    //delete[] arr;
}