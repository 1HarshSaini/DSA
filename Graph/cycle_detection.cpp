 bool isCyclic(int V, vector<int> adj[]) {
        // code here
        //we can find cycle by using topological sort using kahns algo..as kahns algo only apply in DAG
        
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(q.empty()==false){
            int t=q.front();
            q.pop();
            cnt++;
            
            for(auto it:adj[t]){
                indegree[it]--;
                
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==V){//bcz if we find accirate toposort,it mean we have acyclic graph
            return false;
        }
        return true;
       
        
    }