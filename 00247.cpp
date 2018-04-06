#include<bits/stdc++.h>
#define pii pair<int,int>
#define vi vector<int>
#define ms(a) memset(a,0,sizeof(a))

using namespace std;
vi adj[30];
vi num(30,-1),low(30,0),S;
int visited[30];
int t;
map<string,int>cip;
map<int,string>decip;

void dfs(int u){
    num[u]=low[u]=t++;
    visited[u]=1;
    S.push_back(u);
    for(int i = 0 ; i<adj[u].size();i++){
        int v = adj[u][i];
        if(num[v]==-1)dfs(v);
        if(visited[v]==1)low[u]=min(low[u],low[v]);
    }

    if(low[u]==num[u]){
        while(true){
            int v = S.back();S.pop_back();visited[v]=0;
            cout<<decip[v];
            if(u==v)break;
            else cout<<", ";
        }
        cout<<'\n';
    }

}


int main(){

//    freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    int n,m,tim=1;
    bool init=false;
    while(cin>>n>>m && !(n==0 && m==0)){
        if(init)cout<<'\n';
        init = true;
        t = 1;
        for(int i = 0;i<m;i++){
            string a,b;cin>>a>>b;
            int aa=cip[a],bb=cip[b];
            if(aa==0){
                aa=t++;cip[a]=aa;decip[aa]=a;
            }
            if(bb==0){
                bb=t++;cip[b]=bb;decip[bb]=b;
            }
            adj[aa].push_back(bb);
            decip[aa]=a;decip[bb]=b;
            //cout<<aa<<" "<<bb<<endl;
        }
        t=0;
        cout<<"Calling circles for data set "<<tim++<<":\n";
        /*for(auto it=decip.begin();it!=decip.end();i++){
            if(num[it->first]==-1)dfs(decip)
        }*/
        for(int i = 1 ; i<=n;i++){
            if(num[i]==-1){dfs(i);}
        }
        ms(visited);ms(adj);cip.clear();decip.clear();S.clear();
        num.assign(30,-1);low.assign(30,0);
    }
}