#include<iostream>
using namespace std;
int partition(int arr[],int l,int h){//hoare partition
    int pivot=arr[l];
    int i=l-1;
    int j=h+1;
    while(i<j){
        do
        {
           i++;
        } while (arr[i]<=pivot);

        do
        {
            j--;
        } while (arr[j]>pivot);

        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;
}
void quicksort(int arr[],int l,int h){
    if(l<h){
        int p=partition(arr,l,h);
        quicksort(arr,l,p);
        quicksort(arr,p+1,h);
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
    int h=n-1;
    quicksort(arr,l,h);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}