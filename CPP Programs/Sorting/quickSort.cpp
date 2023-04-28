#include <iostream>
using namespace std;

int partition ( int arr[], int s, int e){

    int pivot = arr[s];
    
    int count = 0;

    for(int i = s + 1; i <= e; i++){
        if (arr[i] <= pivot){
            count++;
        }
    }

    int pivotIndex = s + count;

    swap (arr[pivotIndex], arr[s]);

    int l = s;
    int r = e;

    while ( l < pivotIndex && r > pivotIndex){

       while(arr[l] <= pivot){
        l++;
       }
       while ( arr[r] >= pivot){
       r--;
       }

       if(l < pivotIndex && r > pivotIndex)
       {
        swap(arr[l++],arr[r--]);
       }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if (s >= e){
        return;
    }

    int P = partition(arr, s, e);

    //quick sort for left part

    quickSort ( arr, s, P-1);

    //quick sort for right part

    quickSort(arr, P+1, e);


}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for ( int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    for ( int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}