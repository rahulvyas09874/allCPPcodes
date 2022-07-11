bool cycle_in_directed_and_undirected(vector<vector<int>>&graph,int par,vector<int>&vis,int curr,vector<int>&parent){
   vis[curr]=1;  // 1 means that the node is visited and is the call stack
   parent[curr]=par;
   for(auto l:graph[curr]){
       if(vis[l]==0){     // 0 means the node is not yet visited
           
           bool aage=cycle_in_directed_and_undirected(graph,curr,vis,l);

          if(aage==true){
            return true;
          }
       }

       else if(l!=par and vis[l]==1){

          // to return back-edges
          // cout << curr << "->" << l << endl;

          return true;
       }
   }
   vis[curr]=2; // 2 means the node is visited but not in the call stack
   return false;

}