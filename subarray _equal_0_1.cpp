class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //here we use map to keep track of prefix sum we visited no of times
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr[i]=-1;
            }
        }
        unordered_map<int ,int>map;
       int prefix_sum=0;
       map[prefix_sum]=1;   //inserting prefix_sum=0,freq=1 in map intialy
       
       for(int i=0;i<n;i++){
           prefix_sum+=arr[i];
           if(map.find(prefix_sum)!=map.end()){//found sum
               count+=map[prefix_sum];
           }
           map[prefix_sum]++;
       }
       return count;
       

    //for largest subarray
    class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        // Your code here
      
        for(int i=0;i<N;i++){
            if(arr[i]==0){
                arr[i]=-1;//replace 0 by -1
            }
            
        }
        
        unordered_map<int,int>map;
        int sum=0;
        int ans=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            
            if(sum==0){
                ans=max(ans,i+1);
            }
             
             if(map.find(sum)!=map.end()){
                ans=max(ans,i-map[sum]);
            }
           else{
                map[sum]=i;
            }
        }
        return ans;
    }
};
