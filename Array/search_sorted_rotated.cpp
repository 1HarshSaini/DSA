 int search(vector<int>& a, int target) {
       
       
        int low =0 ;
        int high=a.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(a[mid]==target)
                return mid;
            
            
            if(a[low]<=a[mid]){//left part is sorted 
                if(target>=a[low] && target<a[mid]){
                    high=mid-1;
                }
                else{
                        low=mid+1;
                }
            }
           
            else{ // right of mid is sorted 
                if(target>a[mid] && target<=a[high]){
                    low = mid+1;
                }
                else{
                    high =mid-1;
                }
            }
        }
        return -1;
    }