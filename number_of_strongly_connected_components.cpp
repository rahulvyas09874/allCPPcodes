
// dfs for topological sorting
void dfs1(vector<vector<int>>&graph,vector<int>&topo,int curr,vector<bool>&vis){
   vis[curr]=true;
   for(auto l:graph[curr]){
    if(!vis[l]){
      dfs1(graph,topo,l,vis);
    }
   }
   topo.push_back(curr);
}


// dfs for scc,  here the scc vector contains that which nodes are part of which connected component
void dfs2(vector<vector<int>>&revgraph,vector<bool>&vis,int curr,vector<vector<int>>&scc,int scc_count){
   vis[curr]=true;
   scc[scc_count].push_back(curr);
   for(auto l:revgraph[curr]){
     if(!vis[l]){
       dfs2(revgraph,vis,l,scc,scc_count);
     }
   }
   return;
}


int number_of_scc(int nodes,int count_of_edges){
 vector<vector<int>>edges;
 vector<bool>vis(nodes+1);
 vector<int>topo;
 vector<vector<int>>graph(nodes+1);
 vector<vector<int>>revgraph(nodes+1);
 vector<vector<int>>scc(nodes+1);
 int scc_components=0;
  // forming graph and revgraph from edges

 for(int i=0;i<count_of_edges;i++){
    int x,y;
    cin>>x>>y;
    edges.push_back({x,y});
 }

 for(auto l:edges){
  graph[l[0]].push_back(l[1]);
  revgraph[l[1]].push_back(l[0]);
 }
 
 // performing dfs1 for getting topological sorting
 for(int i=1;i<nodes+1;i++){
  if(!vis[i]){
    dfs1(graph,topo,i,vis);
  }
 }
 
 reverse(topo.begin(),topo.end());
 // now i am having the topo sort

 fill(vis.begin(), vis.end(),false);

 // performing dfs2 from every topo node notice here that we are using the graph revgraph instead of graph
for(auto l:topo){
  if(!vis[l]){
    scc_components+=1;
    dfs2(revgraph,vis,l,scc,scc_components);
  }
}


  return scc_components;
}