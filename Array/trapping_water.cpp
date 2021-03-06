class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // here we found max on both side of element,
       vector<int> left(n);
      
        vector<int> right(n); 
      
        long long water = 0;
      
       
        left[0] = arr[0];
        for (int i = 1;i < n;i++) {
            left[i] = max(left[i - 1], arr[i]);
        }
      
        
        right[n-1] = arr[n-1]; 
        for (int i = n - 2;i >= 0;i--) {
            right[i] = max(right[i + 1], arr[i]);
        }
      
       
        for (int i = 0;i < n;i++) {
            water += max(0,min(left[i], right[i]) - arr[i]);
        }
        
        return water;
        
       
    }
};

// { Driver Code Starts.

