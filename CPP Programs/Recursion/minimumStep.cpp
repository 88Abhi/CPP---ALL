#include <iostream>
using namespace std;

int solve(int x, int y, int cnt, bool check)
{
    if (x == y)
        return cnt;
    if (check == false && x <= y || check == true && y <= x)
        return -1;

    //return (x > y) ? solve(x / 2, y, cnt + 1, check) : solve(x * 2, y, cnt + 1, check);
    if(x > y) 
    {
        return solve(x / 2, y, cnt + 1, check);
    }
    else
    {
        return solve(x * 2, y, cnt + 1, check);
    }
}

int main()
{
    int x, y;
    cin >> x >> y;

    bool check = true;

    if (x > y)
    {
        check = false;
    }

    int ans = solve(x, y, 0, check);
    cout << ans << endl;
    return 0;
}