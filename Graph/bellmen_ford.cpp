int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dist(n,1e6);
	    
	    dist[0]=0;
        //traverse n-1 times bcz there are n-1 edges for n vertices
	    for(int i=0;i<n-1;i++){
	        for(int j=0;j<edges.size();j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            //update dist array
	            if(dist[u]+wt<dist[v]){
	                dist[v]=dist[u]+wt;
	                
	               
	            }
	        }
	    }
	    for(int j=0;j<edges.size();j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            //its mean there is -ve cycle which result less distance again n again
	            if(dist[u]+wt<dist[v]){
	                return 1;
	               
	            }
	        }
	    return 0;
	   
	}