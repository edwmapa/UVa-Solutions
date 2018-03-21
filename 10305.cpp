#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define vi vector<int>

using namespace std;
int inDeg[105];
int visited[105];
vi adj[105];

int n,m,a,b;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
    while(cin>>n>>m && !(n==0 && m==0)){
        while(m--){
           cin>>a>>b;
           adj[a].push_back(b);
           inDeg[b]++; 
        }
        queue<int>q;
        for(int init=1;init<=n;init++){
            if(inDeg[init]==0)q.push(init);
        }
        queue<int> tp;
        while(!q.empty()){
            int u = q.front();q.pop();
            visited[u]=1;
            tp.push(u);
            for(int i = 0;i<adj[u].size();i++){
                int v = adj[u][i];
                inDeg[v]--;
                if(inDeg[v]>0)continue;
                if(visited[v]==1)continue;
                q.push(v);
            }
        }
        while(!tp.empty()){
            cout<<tp.front()<<' ';tp.pop();
        }
        cout<<endl;
        
        memset(inDeg,0,sizeof(inDeg));
        memset(visited,0,sizeof(visited));
        memset(adj,0,sizeof(adj));        
    }
}

