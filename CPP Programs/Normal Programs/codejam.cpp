#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    long long int n,k,k1;
    cin>>n;
    vector<int>v;
    vector<int>v1;
    for(int i = 0; i < n; i++){
        cin>>k;
        v.push_back(k);
    }

    for(int i = 0; i < n; i++){
        cin>>k1;
        v1.push_back(k1);
    }

    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end(),greater<int>());
    
    long long int sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i] * v1[i];
    }

    cout << sum << endl;

    return 0;
}

