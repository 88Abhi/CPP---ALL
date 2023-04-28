#include<iostream>
using namespace std;

int getSum(int *arr, int n,int sum){
    if(n < 0){
        return 0;
    }
    
    sum = sum +arr[n] + getSum(arr , n--,sum);
    return sum;
}

int main(){
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
     int arr[5] = {1,2,3,4,5};
    int n = 5;
    int sum = 0;
    int ans = getSum(arr,n,sum);
   
    cout << ans << endl;

    //delete []arr;
    
    return 0;
}