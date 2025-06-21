#include<bits/stdc++.h>
#define alg ios_base::sync_with_stdio(false);
using namespace std;
vector< pair<int,int >>ans;

int Find(int a,vector<int>&DSU){
    if(DSU[a]!=a) return Find(DSU[a],DSU);
    return a;
}

bool Union(int a,int b,vector<int>&DSU,vector<int>&SZ){
    int x =Find(a,DSU);
    int y =Find(b,DSU);
    if(x==y)return false;
    if(SZ[x]<SZ[y]){
        swap(x,y);
    }
    SZ[x]+=SZ[y];
    DSU[y]=x;
    return true ;
}


int main(){
    alg
    int n,r;
    cin >>n>>r;
    vector<int>DSU(n+5);
    vector<int>SZ(n+5,1);

    for(int i= 0;i<=n;i++){
        DSU[i]=i;
    }

    while(r--){
        int a,b;
        cin >> a >>b;
        if(Union(a,b,DSU,SZ)){
            ans.push_back({a,b});
        }
    }
    for (auto i :ans){
        cout <<i.first<<" "<<i.second<<endl;
    }
}   
