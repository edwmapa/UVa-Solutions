#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

vi adj[205];
int visited[205];

bool dfs(int n,int c){
    visited[n]=c;
    
    bool ans=true;
    for (int i = 0;i<adj[n].size();i++){
        int u = adj[n][i];
        if(visited[u]==c)return false;
        if(visited[u]==-c)continue;
        ans = ans && dfs(u,-c);
    }
    
    
    return ans;
}


int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
    int nodes;
    while(cin>>nodes && nodes!=0){
        int l;cin>>l;
        while(l--){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
        }
        if(dfs(0,1))cout<<"BICOLORABLE.\n";
        else cout<<"NOT BICOLORABLE.\n";
        memset(visited,0,sizeof(visited));
        memset(adj,0,sizeof(adj));
    }
    
}

