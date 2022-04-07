#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int triplet(int arr[],int n){
    if(n<3){
        cout<<"No triplet ";
    }

    sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
        if(i==0 || (i>0 && arr[i]!=arr[i-1])){
             int low=i+1;
             int high=n-1;
             while(low<high){
                 int sum=arr[0]+arr[low]+arr[high];
                 if(sum==0){
                     cout<<"pair is"<<endl;
                     cout<<arr[i]<<endl;
                     cout<<arr[low]<<endl;
                     cout<<arr[high]<<endl;

                     while(low<high && arr[low]==arr[low+1]){
                         low++;
                     }
                      while(low<high && arr[high]==arr[high-1]){
                         high;
                     }
                     low++;
                     high--;
                 }
                 else if(sum>0){
                     high--;
                 }
                 else{
                     low++;
                 }
             }
        }
    }
}
int main(){
    int arr[]={1,0,1,2,-1,-4};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<triplet(arr,n);
}