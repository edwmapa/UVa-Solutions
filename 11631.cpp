#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int m,n;
int x,y,z;

vector<pii> adj[200005];
bool marked[200005];

int main(){
	while(cin>>m>>n && !(m==0 && n==0)){
		int ans = 0;
		for(int i = 0 ; i<n;i++){
			cin>>x>>y>>z;
			adj[x].push_back({z,y});
			adj[y].push_back({z,x});
			ans +=z;
		}
		
		priority_queue<pii,vector<pii>,greater<pii>>pq;
		marked[0] = true;
		for(int i = 0 ; i<adj[0].size();i++){
			pq.push(adj[0][i]);
		}
		while(!pq.empty()){
			pii u = pq.top();pq.pop();
			if(marked[u.second])continue;
			marked[u.second]=true;
			ans -=u.first;
			for(int i = 0 ; i<adj[u.second].size();i++){
				pii v = adj[u.second][i];
				if(!marked[v.second]){
					pq.push(v);
				}
			}
		}
		memset(marked,0,sizeof(marked));
		memset(adj,0,sizeof(adj));
		
		cout<<ans<<'\n';
		
	}
}
