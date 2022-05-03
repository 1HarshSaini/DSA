
#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
	vector<int>v;
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=0;i<k;i++){
		for(int j=0;j<kArrays[i].size();j++){
			pq.push(kArrays[i][j]);
			
		}
	}
	while(pq.size()>0){
		v.push_back(pq.top());
		pq.pop();
	}
	return v;
}
