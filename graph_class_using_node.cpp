class node{
public:
   string name;
   list<string>neighbours;

   node(string a){
       this->name=a;
   }

};

class graph{
public:

   unordered_map<string,node*>m;

   graph(vector<string>v){
       for(auto temp:v){
           m[temp]=new node(temp);
       }
   }

   void addedge(string x,string y,bool undir=false){
       m[x]->neighbours.push_back(y);
       if(undir){
           m[y]->neighbours.push_back(x);
       }
   }

   void printgraph(){
       for(auto temp:m){
           cout << temp.first << "-->";
           for(auto neigh:temp.second->neighbours){
               cout << neigh << ",";
           }
           cout << endl;
       }
   }




};