#include<iostream>
#include<numeric>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    vector<int>nums;
    for(int i=0;i<n;i++){
        cin>>k;
        nums.push_back(k);
    }
    int sum=0;
    for(int i=1;i<nums.size()-1;i++){
        int index=i;
        if(nums[0]>nums[1]){
            index=0;
        }    
        int j=i+1;
        bool isvalid=false;
        while(nums[index]>nums[j]){
            isvalid=true;
            j++;
        }
        if(isvalid==false){
            index=j+1;
        }
        while(i<j){
            sum+=nums[index]-nums[i];
            i++;
        }
        i=j;

    }
    cout<<sum<<endl;
    return 0;
}