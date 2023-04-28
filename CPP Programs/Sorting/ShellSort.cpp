#include <iostream>
#include <vector>
using namespace std;
void Shellsort(vector<int> v1)
{
    int size = v1.size();
 
    for (int Gap = size / 2; Gap >= 1; Gap = Gap / 2)
    {
        for (int j = Gap; j < size; j++)
        {
            for (int i = j - Gap; i >= 0; i = i - Gap)
            {
                if (v1[i + Gap] > v1[i])
                {
                    break;
                }
                else
                {
                    swap(v1[i + Gap], v1[i]);
                }
            }
        }
    }

    for(int i=0;i<v1.size();i++)
    cout << v1[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    int arr[n];

    vector<int> v1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v1.push_back(arr[i]);
    }

    Shellsort(v1);
    return 0;
}