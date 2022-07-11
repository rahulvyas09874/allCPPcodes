  int helper(vector<vector<int>>&edges,int n){
    int ans=INT_MAX;
    for(int i=1;i<=n;i++){           // starting bfs from every node to check whether a cycle exist from each node as start node
        vector<int>dis(n+1,INT_MIN); // distance vector ,storing distance from origin node(i)
        vector<int>parent(n+1,-1);   // parent vector ,storing immediate parent for each node
        queue<int>q;
        q.push(i);
        dis[i]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto l:edges[curr]){
                if(dis[l]==INT_MIN){            // this is the condition for a non-visited node
                    q.push(l);
                    dis[l]=dis[curr]+1;        // increase it's distance by 1 from it's parent node
                    parent[l]=curr;            // update it's parent node
                }
                else if(parent[l]!=curr and parent[curr]!=l){  // this is the condition when the node is visited,
                    ans=min(ans,dis[curr]+dis[l]+1);           //->continue ,there are two conditions to check
                }                                              // -> 1st whether the child node is not the parent of curr
            }                                                 // ->2nd is whether the curr node is not a child 
        }                                                     // ->or simply the nodes are not parent of each other, this case arises when we are stucked b/w 2 nodes
    }
    return (ans==INT_MAX)?-1:ans;


  }