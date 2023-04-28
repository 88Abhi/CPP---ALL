#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{

    vector<int> v;
    int n;
    cin >> n;
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }

    // Sort algo For Vectors ->

    cout << "Original Vector -> ";

    for (auto i : v)
    {
        cout << i << " ";
    }

    sort(v.begin(), v.end());

    cout << endl;

    cout << "After sorting in ascending order -> ";

    for (auto i : v)
    {
        cout << i << " ";
    }

    cout << endl;

    sort(v.begin(), v.end(), greater<int>());

    cout << "After sorting in descending order -> ";

    for (auto i : v)
    {
        cout << i << " ";
    }

    cout << endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Reverse a vector ->

    reverse(v.begin(), v.end());

    cout << "After reversing a Vector -> ";

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //Maximum element in vector ->

    cout<<"Maximum element is -> "<<*max_element(v.begin(),v.end())<<endl;

    //Minimum element in vector ->

    cout<<"Minimum element is -> "<<*min_element(v.begin(),v.end())<<endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    
 
    return 0;
}