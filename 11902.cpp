#include<bits/stdc++.h>

using namespace std;

int adj[105][105];
int v[105];
int alt[105];
int T,N;

void dfs(int node){
    v[node]=1;
    for (int i = 0;i<N;i++){
        if(adj[node][i]==0)continue;
        if(v[i]==0){
            dfs(i);
        }
    }
}


void rdfs(int node,int removal){
    if(node==removal)return;
    alt[node]=1;
    for (int i = 0;i<N;i++){
        if(adj[node][i]==0)continue;
        if(alt[i]==0){
            rdfs(i,removal);
        }
    }
}

int main() {
    
    cin>>T;
    for(int i = 1;i<=T;i++){
        cin>>N;
        for (int j = 0;j<N;j++){
            for (int k = 0;k<N;k++){
                cin>>adj[j][k];
            }
        }
        dfs(0);
        cout<<"Case "<<i<<":\n";
        string divisor = "+"+string(2*N -1,'-')+"+";
        for (int j = 0;j<N;j++){
            rdfs(0,j);
            cout<<divisor<<'\n';
            for (int k = 0;k<N;k++){
                if(v[k]==1 && alt[k]==0)cout<<"|Y";
                else cout<<"|N";
            }
            cout<<"|\n";
            memset(alt,0,sizeof(alt));
        }
        cout<<divisor<<'\n';
        memset(v,0,sizeof(v));
    }
}
