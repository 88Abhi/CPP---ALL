#include <iostream>
using namespace std;

double tossStrangeCoins(double prob[], int& target, int &n)
{
	double ans = 1;
	int val = target - n;
	for(int i = 0; i <n; i++){
          ans = ans * (1 - prob[i]);
	}
	return ans/val;
}

int main()
{

    int n;
    cin >> n;
    int target;
    cin >> target;
    double *prob = new double [n];
    for(int i = 0; i < n; i++){
        cin >> prob[i];
    }
    cout << tossStrangeCoins(prob,target,n);

    
}