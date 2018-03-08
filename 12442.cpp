#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eps 1e-9
using namespace std;

int T,N;
vector<int>adj[50005];
int visited[50005];
int depth[50005];


int dfs(int n){  
    visited[n]=1;
    int mx=0;
    // we dont need the loop since each node has only one adjacent node
    for(int i = 0;i<adj[n].size();i++){
        int tNode = adj[n][i];
        if(visited[tNode]==1)continue;
        int rdfs = dfs(tNode);
        mx = max(mx,rdfs);
    }
    visited[n]=0;
    return depth[n]=mx+1;
}


int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
    cin>>T;
    for(int cas = 1;cas<=T;cas++){
       cin>>N; 
        for(int i = 0;i<N;i++){
            int x,y;cin>>x>>y;adj[x].push_back(y);
        }

        int ans = 1,mx=0;
        
        for(int i = 1;i<=N;i++){
            if(depth[i]==0)dfs(i);
            if(depth[i]>mx){mx = depth[i];ans = i;}
        }
        
        cout<<"Case "<<cas<<": "<<ans<<'\n';
        memset(adj,0,sizeof(adj));
        memset(visited,0,sizeof(visited));
        memset(depth,0,sizeof(depth));
    }
}
