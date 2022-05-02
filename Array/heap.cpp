/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class heap{
  public:
  int arr[100];
  int size=0;

  void insert(int val){
      size++;
      int index=size;
      arr[index]=val;
      
      
      while(index>=1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
           swap(arr[index],arr[parent]);
           index=parent;
        }
        else{
            return;
        }
      }
      
      
  }
  
  void del(){
      if(size==0){
          return;
      }
      swap(arr[1],arr[size]);
      size--;
      
      //now put the root=1 node to its right position
      int i=1;
      while(i<size){
          int left=2*i;
          int right=2*i+1;
          
          if(arr[i]<arr[left] && left<size){
              swap(arr[i],arr[left]);
              i=left;
          }
          else if(arr[i]<arr[right] && right<size){
              swap(arr[i],arr[right]);
              i=right;
          }
          else{
              return;
          }
      }
  }
  void heapify(int arr[],int n,int i){
      int largest=i;
      int left=2*i;
      int right=2*i;
      
      if(arr[largest]<arr[left] && left<n){
          largest=left;
      }
      if(arr[largest]<arr[right] && right<n){
          largest=right;
      }
      if(largest!=i){
          swap(arr[largest],arr[i]);
          heapify(arr,n,largest);
      }
  }
  void print(){
      for(int i=1;i<=size;i++){
          cout<<arr[i]<<" ";
      }
  }
  
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    
    h.print();
    cout<<endl;
    h.del();
    h.print();
    cout<<endl;
    
    int arr[6]={0,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        h.heapify(arr,n,i);
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
