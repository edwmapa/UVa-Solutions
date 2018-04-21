#include<bits/stdc++.h>
#define INF INT_MAX
#define vi vector<int>
using namespace std;

vi g[500];
int d[500],visit[500];
vector<string>data;
map<string,int>cip;

int bfs(int a,int b){
    queue<int>q;q.push(a);d[a]=0;visit[a]=1;
    while(!q.empty()){
        int u = q.front();q.pop();
        visit[u]=1;
        for(int i = 0 ; i<g[u].size();i++){
            int v = g[u][i];
            if(visit[v]==1)continue;
            d[v] = d[u]+1;
            q.push(v);
        }
    }
    return d[b];
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int T;cin>>T;cin.ignore();
    bool flag = false;
    while(T--){
        if(!flag){cin.ignore();flag=true;}
        string str;int cipT=1;
        data.push_back("n");//start in one
        while(getline(cin,str)){
            if(str=="*")break;
            cip[str]=cipT++;data.push_back(str);
        }
        for(int i = 1 ; i<data.size();i++){
            for(int j = i+1 ; j<data.size();j++){
                if(data[i].size()!=data[j].size())continue;
                int dif = 0;
                for(int k = 0 ; k<data[i].size();k++)if(data[i][k]!=data[j][k])dif++;
                if(dif>1)continue;
                
                int u = cip[data[i]], v = cip[data[j]];
                g[u].push_back(v);g[v].push_back(u);
            }
        }

        while(getline(cin,str)){
            if(str=="")break;
            stringstream ss;ss<<str;
            string a,b;
            ss>>a>>b;
            int ans = bfs(cip[a],cip[b]);
            cout<<a<<' '<<b<<' '<<ans<<'\n';
            memset(d,0,sizeof(d));memset(visit,0,sizeof(visit));
        }
        memset(g,0,sizeof(g));
        data.clear();cip.clear();
        if(T-1!=-1)cout<<"\n";
    }
}