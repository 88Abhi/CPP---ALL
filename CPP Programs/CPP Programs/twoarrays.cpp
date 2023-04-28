#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void print (vector<int>v, vector<int>v1){
    stack<int>s;
    stack<int>s1;

    for(int i = 0; i < v.size(); i++)
    {
        s.push(v[i]);
    }

    for(int i = 0; i < v1.size(); i++)
    {
        s1.push(v1[i]);
    }
    vector<int>vec;

    while(s.size() != 0 && s1.size() != 0){
        int element = s.top();
        int element1 = s1.top();
        
        if(s.top()==s1.top()){
            vec.push_back(s.top());
            s.pop();
            s1.pop();
        }
        else if(element > element1){
            s.pop();
        }
        else {
            s1.pop();
        }
    }

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}

int main(){

    int n, n1, k, k1;
    cin >> n >> n1;
    vector<int>v;
    vector<int>v1;
    for ( int i = 0; i < n; i++){
        cin >> k;
        v.push_back(k);
    }
    for ( int i = 0; i < n1; i++){
        cin >> k1;
        v1.push_back(k1);
    }

    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    
    print ( v, v1);

      return 0;
}