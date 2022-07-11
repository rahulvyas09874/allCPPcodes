class DSU{
 
    vector<int>parent;
    vector<int>rank;
    int distinct_components;
 public:
    
    
    DSU(int nodes){                 // constructor                        

         for(int i=0;i<nodes+1;i++){
            parent.push_back(i);
            rank.push_back(1);
         }
         distinct_components=nodes;
    }
    int find(int i){              // path compression
        if(parent[i]==i){
            return i;
        }

        return parent[i]=find(parent[i]);           
    }


    void DSU_union(int i,int j){ 
        int par1=find(i);
        int par2=find(j);

        if(par1!=par2){                             // rank optimization
            if(rank[par1]>rank[par2]){               
                parent[par2]=par1;
                rank[par1]+=rank[par2];
            }
            else{
                parent[par1]=par2;
                rank[par2]+=rank[par1];
            }
            distinct_components--;
        }
        
    }

    bool is_graph_have_only_one_component(){    // directly returns wether our graph has single component or not
        return distinct_components==1;

    }
};