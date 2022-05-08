 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>v;
        vector<bool>visit(V);
        queue<int>q;
        
        for(int i=0;i<V;i++){
            visit[i]=false;
        }
        
        q.push(0);//push first node in queue and make it true in vistt
        visit[0]=true;
        while(q.empty()==false){
            int t=q.front();
            q.pop();
            v.push_back(t);
            
            for(auto it:adj[t]){//traversing all adj of t
                if(visit[it]==false){
                    q.push(it);
                    visit[it]=true;
                }
            }
        }
        return v;
    }