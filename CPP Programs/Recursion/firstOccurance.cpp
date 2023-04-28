#include<iostream>
using namespace std; 

int firstOccurance(int arr[], int start,int end,int target,int ans){
  
    if(start > end){
        return ans;
    }
   int mid = start + (end - start)/2;
    if(arr[mid] == target){
      ans = mid;
      return firstOccurance(arr,start,mid - 1,target,ans);
    } 
    if(arr[mid] > target){
        return firstOccurance(arr,start,mid - 1,target,ans);
    }
    else if (arr[mid] < target){
       return  firstOccurance(arr,mid + 1,end,target,ans);
    }
}


int lastOccurance(int arr[], int start,int end,int target,int ans){
  
    if(start > end){
        return ans;
    }
   int mid = start + (end - start)/2;
    if(arr[mid] == target){
      ans = mid;
      return lastOccurance(arr,mid + 1,end,target,ans);
    } 
    if(arr[mid] > target){
        return lastOccurance(arr,start,mid - 1,target,ans);
    }
    else if (arr[mid] < target){
       return  lastOccurance(arr,mid + 1,end,target,ans);
    }
}


int main(){
    // int n;
    // cin >> n;
    // int target;
    // cin >> target;
    // int *arr= new int [n];
    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
    int n = 10;
    int arr[10] = {3,4,5,5,5,5,5,5,7,9};
    int target = 5;
    int ans = -1;
    
    int left = firstOccurance(arr,0,n-1,target,ans);
    int right = lastOccurance(arr,0,n - 1,target,ans);
   
    cout << left << " " << right << endl;

    //delete[]arr;

    return 0;
} 