void dfs(int node, vector<int> adj[],vector<bool>&visit,vector<int>&ans){
        ans.push_back(node);// push this node to ans and make visited true
        visit[node]=true;
        
        for(auto it:adj[node]){//now traverse all adjacent nodes of it
            if(visit[it]==false){
                dfs(it,adj,visit,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>visit(V);
        
        for(int i=0;i<V;i++){
            visit[i]=false;
        }
        
        for(int i=0;i<V;i++){//traversing all nodes of graph
            if(visit[i]==false){
                dfs(i,adj,visit,ans);
            }
        }
        return ans;
    }