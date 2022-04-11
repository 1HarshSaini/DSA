 public:
    typedef long long ll;
    long long ans = 0;
    void merge(ll arr[], ll low, ll mid, ll high)
    {
        ll n1 = mid-low+1;
        ll n2 = high-mid;
        ll left[n1], right[n2];
        
        for(int i=0;i<n1;i++)
           left[i] = arr[low+i];
        
        for(int i=0;i<n2;i++)
           right[i] = arr[mid+1+i];
        
        ll i=0,j=0,k=low;
        
        while(i<n1&&j<n2)
        {
            if(left[i]<=right[j])
              arr[k++] = left[i++];
            else
            {
                ans+=(n1-i);
                arr[k++] = right[j++];
            }
        }
        
        while(i<n1) arr[k++] = left[i++];
        while(j<n2) arr[k++] = right[j++];
        
    }
    void mergeSort(long long arr[], int low, int high)
    {
        if(low<high)
        {
            ll mid = low+(high-low)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return ans;
    }

};