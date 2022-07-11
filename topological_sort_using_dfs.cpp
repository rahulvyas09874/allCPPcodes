

void dfs(vector<vector<int>>&graph,int curr,vector<bool>&vis,vector<int>&ans){
  vis[curr]=true;

  for(auto l:graph[curr]){
       if(!vis[l]){
        dfs(graph,l,vis,ans);
       }
  }

  ans.push_back(curr);
  return;

}


vector<int>topo_sort_using_dfs(vector<vector<int>>&graph,int n){
  vector<bool>vis(n+1,false);
  vector<int>ans;
  for(int i=1;i<n+1;i++){
    if(vis[i]==false){
      dfs(graph,i,vis,ans);
    }
  }
  reverse(ans.begin(),ans.end());
  return ans;

}