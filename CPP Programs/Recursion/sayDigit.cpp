#include<iostream>
using namespace std;
void Print(int n, string arr[]){
    //base case
    if(n <=  0){
        return ;
    }

    //processing

    int num = n % 10;
    n = n / 10;
    //recursive call
    Print(n,arr);
    cout << arr[num] << " ";
}
int main(){
    int n;
    cin >> n;
    string arr[10] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
    Print(n,arr);
    return 0;
}