#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

vi adj[260];
int visited[250];
int inDeg[260];
int keys[260];
int am; bool can = false;

string vp;
void dfs(int n){
    visited[n]=1;
    for(int i = 0;i<adj[n].size();i++)inDeg[adj[n][i]]--;
    for(int j = 'A';j<='Z';j++){
        if(!(keys[j]!=0 && inDeg[j]==0))continue;
        if(visited[j]==1)continue;
        vp+=char(j);
        dfs(j);
        vp.pop_back();
    }
    for(int i = 0;i<adj[n].size();i++)inDeg[adj[n][i]]++;
    if(am==vp.size()){
        for(int i = 0;i<am;i++){
            cout<<vp[i];if(i!=am-1)cout<<' ';
        }
        cout<<'\n';
        can = true;
    }
    visited[n]=0;
    
}


int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int t;cin>>t;cin.ignore();cin.ignore();
    while(t--){
        string a,b,temp;
        stringstream ss,sss;
        getline(cin,a);
        getline(cin,b);
        cin.ignore();
        //cout<<"*"<<a<<'-'<<b<<endl;
        ss<<a;
        while(ss>>temp){
            keys[temp[0]]++;
            am++;
        }
        sss<<b;
        while(sss>>temp){
            adj[temp[0]].push_back(temp[2]);
            inDeg[temp[2]]++;
        }
        int startNode=0;
        for(int i = 'A';i<='Z';i++){
            if(inDeg[i]==0 && keys[i]!=0){
                vp+=char(i);dfs(i);
                vp="";
            }
        }
        if(!can)cout<<"NO\n";
        if(t!=0)cout<<'\n';
        memset(adj,0,sizeof(adj));
        memset(inDeg,0,sizeof(inDeg));
        memset(keys,0,sizeof(keys));
        am = 0;can=false;
        
    }
}

