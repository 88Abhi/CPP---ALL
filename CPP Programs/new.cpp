#include<iostream>
using namespace std;
   void rotatearray(int arr[],int d,int n)
   {int temp[n];
   int k=0;
    for(int i=d;i<n;i++){
       temp[k]=arr[i];
       k++;
        }
        for(int i=0;i<d;i++){
         temp[k]=arr[i];
       k++;
       }
      
      for(int i=0;i<n;i++){
      arr[i]=temp[i];
      }
     for(int i=0;i<n;i++){
            cout<<arr[i]<<endl;
         }
      }
      
      
   int main(){

   int n,d;
   cin>>n>>d;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
  rotatearray(arr, d,n);
    return 0;
    
} 
