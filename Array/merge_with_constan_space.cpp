class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // in this ,we fix three pointers i to start of arr1 ,j to start of arr2 and k to end of arr1
            // if we encounter any element in arr2 who is smaller then arr1[i] then include it in arr1/
            // else move ahead
            int i=0;
            int j=0;
            int k=n-1;
            while( (i<k || i<n) && j<m){ // can write i<n and j<m
                if(arr2[j]<arr1[i]){
                    int t=arr1[k];
                    arr1[k]=arr2[j];
                    arr2[j]=t;
                    
                    j++;
                    k--;
                }
                else{
                    i++;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};