#include<bits/stdc++.h>
using namespace std;

void merge ( int arr[], int &s, int &e, int &mid, int &size)
{
     int temp [size];
     int low = s;
     int high = mid + 1;
     int k = 0;
     
     while(low <= mid and high <= e){
        if(arr[low] <= arr[high])
        {
            temp [k] = arr[low];
            k++;
            low++;
        }
        else
        //if(arr[low] > arr[high])
        {
            temp [k] = arr[high];
            high++;
            k++;
        } 
     }
     while(low <= mid){
         temp [k] = arr[low];
            low++;
            k++;
     }

     while(high <= e){
        temp [k] = arr[high];
            high++;
            k++;
     } 

     for (int x = s,i = 0; i < k; i++,x++){
        arr [x] = temp[i];
        
     }
}

void mergeSort(int arr[], int s, int e,int &size){
    if ( s >= e){
        return;
    }

    int mid = s + (e - s) / 2;

    mergeSort ( arr, 0, mid, size);

    mergeSort ( arr, mid+1, e, size);

    merge ( arr, s, e, mid, size);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for ( int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int size = n;
    mergeSort(arr, 0, n-1, size);

    for ( int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }


    return 0;
}