#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

vi adj[3000];

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int E,N,T;
    cin>>E;
    for(int u = 0 ; u <E;u++){
        cin>>N;
        int v;
        while(N--){
            cin>>v;
            adj[u].push_back(v);
        }
    }
    cin>>T;
    while(T--){
        cin>>N;
        vi d(3000,-1);
        int levels[3000];memset(levels,0,sizeof(levels));
        queue<int>q;q.push(N);d[N]=0;
        int boom=0,day=3000;
        while(!q.empty()){
            int u = q.front();q.pop();
            for(int i = 0 ;i<adj[u].size();i++){
                int v = adj[u][i];
                if(d[v]!=-1)continue;
                d[v] = d[u]+1;
                levels[d[u]]++;
                q.push(v);
            }
            if(levels[d[u]]>boom){
                boom = levels[d[u]];
                day = d[u];
            }
        }
        if(boom == 0)cout<<"0\n";
        else cout<<boom<<' '<<day+1<<'\n';
    }
    
}