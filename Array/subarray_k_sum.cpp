class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //here we going to use map for prefix sum and their frequency
       unordered_map<int,int>map;
       int pre_sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            pre_sum+=nums[i];
            if(pre_sum==k){
                count++;
            }
            if(map.find(pre_sum-k)!=map.end()){
                 count+=map[pre_sum-k];//we increase count as many time as many rime                       //pre su comes
            }
            map[pre_sum]++;
            
            
        }
        return count;
        
        
        
        
    }
};