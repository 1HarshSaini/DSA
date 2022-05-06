	public:
	//Function to return list containing vertices in Topological order.
    
    // void sort(int node,vector<bool>& visit,stack<int>&st, vector<int> adj[]){//by dfs
    //     visit[node]=true;
    //     for(auto it:adj[node]){
    //         if(visit[it]==false){
    //             sort(it,visit,st,adj);
    //         }
    //     }
    //      st.push(node);//pushing last node of recursive call stack...parent node is pushed at last 
    // }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    vector<int>ans;   //kahns algo--bfs...  we can do it by simply dfs+stack
	    queue<int>q;
	    vector<int>indegree(V);
	    for(int i=0;i<V;i++){//make indergree of every node=0
	        indegree[i]=0;
	    }
	    //now checking for adj of every node and increasing indegree accodingley
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++; 
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){//pushing node whose indegree=0
	            q.push(i);
	        }
	    }
	    while(q.empty()==false){
	        int t=q.front();
	        q.pop();
	        ans.push_back(t);
	        
	        for(auto it:adj[t]){
	            indegree[it]--; //degrease indgree of adj of t as we remove t now;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	   
	   
	   //vector<bool>visit(V,false);
	   //stack<int>st;
	   //for(int i=0;i<V;i++){
	   //    if(visit[i]==false){
	   //        sort(i,visit,st,adj);
	   //    }
	   //}
	   //vector<int>ans;
	   //while(st.size()>0){
	   //    ans.push_back(st.top());
	   //    st.pop();
	   //}
	   //return ans;
	   
	   
	}