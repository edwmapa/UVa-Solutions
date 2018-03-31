#include <bits/stdc++.h>
#define ll long long
#define ms(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define vi vector<int>
#define eps 1e-9
using namespace std;

bool critical[105];int parent[105];
vi num(105,-1),low(105,0);
vi adj[105];
int t,special,root;

void dfs(int n){
    num[n]=low[n]=t++;
    for(int i = 0;i<adj[n].size();i++){
        int v = adj[n][i];
        if(num[v]==-1){
            if(n==root)special++;
            parent[v]=n;
            dfs(v);
            if(low[v]>=num[n])critical[n]=true;
            low[n]=min(low[n],low[v]);
        }
        else if(parent[n]!=v) low[n]=min(low[n],num[v]);
    }
}


int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
    int N;
    while(cin>>N && N!=0){
        cin.ignore();
        string str;
        while(getline(cin,str)){
            stringstream ss;
            if(str=="0")break;
            ss<<str;
            int a,b;
            ss>>a;
            while(ss>>b){
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }
        
        for(int i = 1;i<=N;i++){
            if(num[i]!=-1)continue;
            root = i;t=0;special=0;
            dfs(i);
            critical[root]=(special>1);
        }
        int ans = 0;
        for(int i =0;i<=N;i++)if(critical[i])ans++;
        cout<<ans<<'\n';
        
        num.assign(105,-1);low.assign(105,0);
        ms(adj);ms(critical);ms(parent);
    }
}
