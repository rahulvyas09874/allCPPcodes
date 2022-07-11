class DSU{
 
 int*parent;
 int*rank;

 public:
    DSU(int nodes){                         // dsu constructor
    	parent=new int[nodes];
    	rank=new int[nodes];

    	 for(int i=0;i<nodes;i++){
    	 	parent[i]=i;
    	 	rank[i]=1;
    	
         }	
    }
  // find function
    int find(int i){
    	if(parent[i]==i){
    		return i;
    	}

    	return parent[i]=find(parent[i]);
    }

    // union function

    void DSU_union(int i,int j){
    	int par1=find(i);
    	int par2=find(j);

    	if(par1!=par2){
    		if(rank[par1]>rank[par2]){
    			parent[par2]=par1;
    			rank[par1]+=rank[par2];
    		}
    		else{
    			parent[par1]=par2;
    			rank[par2]+=rank[par1];
    		}
    	}
    }
};


int MST_kruskal(vector<pair<int,pair<int,int>>>&graph,int nodes){
    DSU s(nodes+1);   // doing +1 to avoid under flow if my nodes are starting from 1 and not from zero (to be on safe side)
    int ans=0;

    // 1st step is sort the edges in the graph as per weight
    // note: the graph is of the form of vector of vector where each vector has 3 elements 1st element is the 1st node 2nd element is the 2nd node
    // and 3rd element is the weight of the edge

    sort(graph.begin(), graph.end());
    // 2nd step is to iterate over the graph and union those edges which don't have same parent and add their weight to ans

    for(int i=0;i<graph.size();i++){
        if(s.find(graph[i].second.first)!=s.find(graph[i].second.second)){
            s.DSU_union(graph[i].second.first,graph[i].second.second);
            ans+=graph[i].first;
        }
    }

    return ans;

}

// make graph of the form vector<pair<int,pair<int,int>>>&graph where first pair's first element is weight and
// 1st pair's 2nd element is another pair with 2 elements namely {node i, node j}