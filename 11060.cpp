#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define vi vector<int>
#define ms(a) memset(a,0,sizeof(a))
using namespace std;

map<string,int>cip;
map<int,string>de;
vi adj[105];
int inDeg[105];

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int n,cas=1;
    while (cin>>n){
        for(int i = 0;i<n;i++){
            string str;cin>>str;
            cip[str]=i;de[i]=str;
        }
        int rel;cin>>rel;
        while(rel--){
            string a,b;cin>>a>>b;int cipb=cip[b];
            adj[cip[a]].push_back(cipb);
            inDeg[cipb]++;
        }
        
        priority_queue<int,vi,greater<int>>q;
        for(int i = 0;i<n;i++){
            if(inDeg[i]==0)q.push(i);
        }
        vi tp;
        while(!q.empty()){
            int v = q.top();q.pop();
            tp.push_back(v);
            for(int i = 0;i<adj[v].size();i++){
                int u = adj[v][i];
                inDeg[u]--;
                if(inDeg[u]==0)q.push(u);
            }
            
        }
        
        printf("Case #%d: Dilbert should drink beverages in this order: ",cas++);
        for(int i = 0;i<tp.size();i++){
            //printf("%d ",tp[i]);
            cout<<de[tp[i]];if(i+1!=tp.size())cout<<' ';
        }
        printf(".\n\n");
        ms(adj);ms(inDeg);
        de.clear();cip.clear();
    }
}

