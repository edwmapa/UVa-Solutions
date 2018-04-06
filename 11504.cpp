#include <bits/stdc++.h>
#define ll long long
#define ms(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define vi vector<int>
#define eps 1e-9
using namespace std;

vi adj[100005];//vi comps[100005];
vi low(100005,0),num(100005,-1),S,tp;
int visited[100005],t,ssc;
void dfs(int u){
    num[u]=low[u]=t++;
    visited[u]=1;
    S.push_back(u);
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(num[v]==-1){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        if(visited[v]==1)low[u]=min(low[u],low[v]);
    }
    if(low[u]==num[u]){        
        while(true){
            int v = S.back();S.pop_back();visited[v]=0;
            tp.push_back(v);
            //comps[ssc].push_back(v);
            if(u==v)break;
        }
        ssc++;
    }
}

void dfs2(int u){
    visited[u]=1;
    for(int i = 0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(visited[v]==1)continue;
        dfs2(v);
    }
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
    int cas;cin>>cas;
    while(cas--){
        int n,m;
        cin>>n>>m;
        for(int i = 0 ; i<m;i++){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
        }
        
        for(int i = 1 ;i<=n;i++){
            if(num[i]==-1)dfs(i);
        }
        ms(visited);
        reverse(tp.begin(),tp.end());
        int ans = 0;
        for(int i = 0 ; i <tp.size();i++){
            if(visited[tp[i]]==0){
                dfs2(tp[i]);
                ans++;
            }
        }
        cout<<ans<<'\n';
        ms(visited);ms(adj);num.assign(100005,-1);low.assign(100005,0);
        S.clear();tp.clear();ssc=t=0;
    }
}
