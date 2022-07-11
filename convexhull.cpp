class point{
public:
    int x;
    int y;
};

int cross_product(point p, point q, point r){
    int val= (r.x-q.x)*(q.y-p.y)-(q.x-p.x)*(r.y-q.y);
    if(val==0){
        return 0; // collinear
    }
    return (val<0) ? 2:1; //clockwise/counter-clockwise
}

void convex_hull(vector<point>v){
    int n=v.size();
    vector<vector<int>>ans;
    vector<point>tempans;

    if(n<3){
        return;
    }

    // find the leftmost point
    int l=0;
    for(int i=1;i<n;i++){
        if(v[i].x < v[l].x){
           l=i;
        }
    }

  // finding most clockwise point with respect to p
    int p=l,q;

    do{
      tempans.push_back(v[p]);

     q=(p+1)%n;
     for(int i=0;i<n;i++){
        if(cross_product(v[p],v[q],v[i])==2){
            q=i;
        }
     }
     for(int i=0;i<n;i++){
        if(cross_product(v[p],v[q],v[i])==0 and (v[i].x > v[p].x) and (v[i].x <v[q].x)  and (v[i].y < v[p].y) and (v[i].y > v[q].y) ){
            tempans.push_back(v[i]);
        }
     }

     p=q;


    }while(p!=l);

    // printing ans

    for(auto l:tempans){
        vector<int>noob;
        noob.push_back(l.x);
        noob.push_back(l.y);
        ans.push_back(noob);
    }

    for(auto l:ans){
        for(auto p:l){
            cout << p << " ";
        }
        cout << endl;
    }
    

}


