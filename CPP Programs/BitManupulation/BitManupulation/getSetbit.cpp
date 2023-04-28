#include <iostream>
using namespace std;
int main()
{

    // Finding kth bit of a numsber

    int n;
    cin >> n;

    int k;
    cin >> k;

    int mask = (1 << k);
    int num = n & mask;
    if (num == 0)
    {
        cout << "kth Bit of " << n << " is 0" << endl;
    }

    else
        cout << "kth Bit of " << n << " is 1" << endl;

    cout << "-----------------------------" << endl;

    // Set kth bit of a number

    int n1;
    cin >> n1;
    int k1;
    cin >> k1;
    int mask1 = (1 << k);

    int num1 = n1 | mask1;

    cout << num1 << endl;

    cout << "----------------------------" << endl;

    // Clear kth bit of a number

    int n2;
    cin >> n2;
    int k2;
    cin >> k2;
    int mask2 = ~(1 << k2);
    int num2 = n2 & mask2;
    cout << num2 << endl;

    cout << " ------------------------------" << endl;

    // find how many bits we have to chage for changing a number to a to b

    int nn, nn1;
    cin >> nn >> nn1;
    int count = 0;
    int result = nn ^ nn1;
    while (result != 0)
    {
        if (result & 1 == 1)
        {
            count++;
        }
        result = (result >> 1);
    }
    cout << count << endl;

    cout << "--------------------------------" << endl;

    // frequency of bits == 1

    int result1;
    cin >> result1;
    int count1 = 0;
    while (result1 != 0)
    {
        result1 = result1 & (result1 - 1);
        count1++;
    }
    cout << count1 << endl;

    return 0;
}