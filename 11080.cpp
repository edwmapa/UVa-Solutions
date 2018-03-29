#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define vi vector<int>
using namespace std;

vi adj[205];
int visited[205];
int c1,c2;

bool dfs(int n,int c){
    visited[n]=c;
    
    if(c==1)c1++;
    else c2++;
    
    bool ans = true;
    for(int i = 0;i<adj[n].size();i++){
        int v = adj[n][i];
        if(v==n)continue;
        if(visited[v]==c)return false;
        if(visited[v]==-c)continue;
        ans = ans && dfs(v,-c);
    }
    return ans;
}


int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int v,e;cin>>v>>e;
        while(e--){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;bool p=true;
        for(int i = 0;i<v;i++){
            if(visited[i]!=0)continue;
            p = p&&dfs(i,1);
            ans+=(c1==0)?c2:(c2==0)?c1:min(c1,c2);
            c1=c2=0;
        }
        if(p)cout<<ans<<'\n';
        else cout<<"-1\n";
        
        memset(adj,0,sizeof(adj));
        memset(visited,0,sizeof(visited));
    }
    
}

