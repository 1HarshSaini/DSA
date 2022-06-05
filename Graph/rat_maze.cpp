class Solution{
     public:
    bool issafe(int x, int y, int n, vector<vector<int>>m, vector<vector<int>> visited)
    {
        //check if x,y lie in matrix or not and visit aray
        if((x >= 0 && x < n) && (y >= 0 && y < n) && m[x][y] == 1 && visited[x][y] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    void solve(vector<vector<int>>&m, int n, vector<string>&ans, string path, 
        vector<vector<int>> &visited,int x, int y)
        {
            //Base case,check if rat reach the destination
            if(x == n-1 && y == n-1)
            {
                ans.push_back(path);
                return;
            }
            
            visited[x][y] = 1;
            
            //Down
            int newx = x + 1;
            int newy = y;
            if(issafe(newx, newy, n, m, visited))
            {
                path.push_back('D');
                //Recursive call
                solve(m, n, ans, path, visited, newx, newy);
                path.pop_back();
               
            }      
            
            //Right
            newx = x;
            newy = y + 1;
            if(issafe(newx, newy, n, m, visited))
            {
                path.push_back('R');
                //Recursive call
                solve(m, n, ans, path, visited, newx, newy);
                path.pop_back();//remove while returning
               
            }  
            
            //Left
            newx = x;
            newy = y - 1;
            if(issafe(newx, newy, n, m, visited))
            {
                path.push_back('L');
                //Recursive call
                solve(m, n, ans, path, visited, newx, newy);
                path.pop_back();
            
            } 
            
            //Up
            newx = x - 1;
            newy = y;
            if(issafe(newx, newy, n, m, visited))
            {
                path.push_back('U');
                //Recursive call
                solve(m, n, ans, path, visited, newx, newy);
                path.pop_back();
                
            }
            //make viisted false while returning after find one path to open way for another path
            visited[x][y] = 0;
            
        }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        //base case,check if (0,0) in matrix is blocked==0 or noyt
        if(m[0][0] == 0)
        {
            return ans;
        }
        
        int x = 0;
        int y = 0;
        //create visited matrix
        vector<vector<int>> visited = m;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        
        string path = "";
        
        solve(m,n,ans,path,visited,x,y);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
