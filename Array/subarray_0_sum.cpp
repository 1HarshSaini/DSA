class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //map is used to keep track of prefix sum of arry and pre sum frequeny
        //frequency is used bcz if we need to tell how many times  this sum=0 come
        unordered_map<int,int>map;
        int prefix_sum=0;
    
        for(int i=0;i<n;i++){
            prefix_sum+=arr[i];
            
            if(prefix_sum==0){//eg= -3,2,1
                return true;
            }
            
            if(map.find(prefix_sum)!=map.end()){ //mil gya sum map me
                //count+=map[prefix_sum];
                return true;
            }
            map[prefix_sum]++;
        }
        return false;
    }
};