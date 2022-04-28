#include <iostream>

using namespace std;
int minop(int arr[],int n){
    int count=0;
    int i=0;
    int j=n-1;
    while(i<=j){
        if(arr[i]==arr[j]){
            i++;j--;
        }
        else if(arr[i]<arr[j]){
            i++;
            arr[i]=arr[i]+arr[i-1];
            count++;
        }
        else{
            j--;
            arr[j]=arr[j]+arr[j+1];
            count++;
        }
    }
    return count;
}

int main()
{
  int arr[]={1,3,4,5,7};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<"No are "<<minop(arr,n)<<endl;
  return 0;
}
