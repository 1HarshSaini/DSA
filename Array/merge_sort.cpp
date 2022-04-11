#include <iostream>
using namespace std;
void merge(int arr[],int l,int r,int mid){
    int n=mid-l+1;
    int m=r-mid;

    int left[n];
    int right[m];

    for(int i=0;i<n;i++){
        left[i]=arr[i+l];
    }
    for(int i=0;i<m;i++){
        right[i]=arr[mid+i+1];
    }

    int i=0;
    int j=0;
    int k=l;
    while(i<n && j<m){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
            k++;
        }
        else{
            arr[k]=right[j];
            j++;k++;
        }
    }
    while(i<n){
        arr[k]=left[i];
            i++;
            k++;
    }
    while(j<m){
         arr[k]=right[j];
            j++;k++;
    }
}
    
void merge_sort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0;
    int r=n-1;
    merge_sort(arr,l,r);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}