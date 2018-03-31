#include <bits/stdc++.h>
#define ll long long
#define ms(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define vi vector<int>
#define eps 1e-9
#define MAX 1000005
using namespace std;

vi num(MAX,-1),low(MAX,0);
vi adj[MAX];
int parent[MAX];
set<pii>ls;int ans;
int t;
void dfs(int n){
    num[n]=low[n]=t++;
    for(int i = 0;i<adj[n].size();i++){
        int v = adj[n][i];
        if(num[v]==-1){
            parent[v]=n;  
            dfs(v);
            
            if(low[v]>num[n]){
                if(n<v)ls.insert(pii(n,v));
                else ls.insert(pii(v,n));
                ans++;
            }
            
            low[n] = min(low[n],low[v]);
        }else if(v!=parent[n])low[n]=min(low[n],num[v]);
    }
}

int toInt(string str){
    stringstream ss;
    ss<<str;
    int a;ss>>a;
    return a;
}


int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
    int N;
    while(cin>>N){
        int a,b,q;string p;
        for(int i=0;i<N;i++){
            cin>>a>>p;
            q=toInt(p.substr(1,p.size()-1));
            while(q--){
                cin>>b;
                adj[a].push_back(b);
                //adj[b].push_back(a);
            }
        }
        for(int i = 0;i<N;i++){
            if(num[i]!=-1)continue;
            t=0;dfs(i);
        }
        
        cout<<ans<<" critical links\n";
        for(set<pii>::iterator it=ls.begin();it!=ls.end();++it){
            cout<<it->first<<" - "<<it->second<<'\n';
        }
        cout<<'\n';
        num.assign(MAX,-1);low.assign(MAX,0);ls.clear();ans=0;
        ms(adj);ms(parent);
    }
}
