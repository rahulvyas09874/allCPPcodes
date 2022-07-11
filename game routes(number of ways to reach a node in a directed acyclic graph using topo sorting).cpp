
void helper(vector<vector<int>>&graph,int n,vector<int>&ways_till_each_node){
    queue<int>q;
    vector<int>topological_sort;
    vector<int>indegree(n+1,0);
    for(auto l:graph){
        for(auto p:l){
            indegree[p]++;
        }
    }
    for(int i=1;i<n+1;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        topological_sort.push_back(curr);
        for(auto l:graph[curr]){
            indegree[l]--;
            if(indegree[l]==0){
                q.push(l);
            }
        }
    }
    for(auto l:topological_sort){
        for(auto p:graph[l]){
            ways_till_each_node[p]=(ways_till_each_node[p]+ways_till_each_node[l])%1000000007;
        }
    }
    return;
}


int gameRoutes(int n, vector<vector<int>> edges){

    vector<vector<int>>graph(n+1);
    for(auto l:edges){
        graph[l[0]].push_back(l[1]);
    }
    vector<int>ways_till_each_node(n+1,0);
    ways_till_each_node[1]=1;
    helper(graph,n,ways_till_each_node);
    return ways_till_each_node[n];


}